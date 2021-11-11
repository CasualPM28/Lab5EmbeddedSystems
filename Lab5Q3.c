#include <msp430.h> 

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;	// stop watchdog timer
	
	P1DIR |= BIT6;      // set Port 1.6 to be the output
	TA0CTL = TASSEL_2 + MC_1 + ID_3; //use SMCLK, up mode, frequency division of 1,
	                                         //and resetting clock divider
	TA0CCR0 = 31250-1; // set to maximum count value
	TA0CCR1 = 6250;  // initialize counter compare

	TA0CCTL0 |= CCIE; // enable capture/compare interrupt at TA0CCTL0
	TA0CCTL1 |= CCIE; // enable capture/compare interrupt at TA0CCTL1

	TA0CCTL0 &=~CCIFG; // set capture/compare flag to 'not' of the value of the memory location of TA0CCTL1
	TA0CCTL1 &=~CCIFG; // set capture/compare flag to 'not' of the value of the memory location of TA0CCTL0

	_enable_interrupts(); // enable interrupts
}
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TA0_ISR(void)      // define ISR for TA0CCTL0
{
    P1OUT |= BIT6;  // set the output to not the value of the memory location of the red LED
    TA0CCTL0 &=~CCIFG; // set capture/compare flag to not the value of the memory location
}
#pragma vector = TIMER0_A1_VECTOR       //define the interrupt service vector
__interrupt void TA1_ISR (void)    // interrupt service routine
    {
    P1OUT &=~BIT6;
    TA0CCTL1 &=~CCIFG;

    }
