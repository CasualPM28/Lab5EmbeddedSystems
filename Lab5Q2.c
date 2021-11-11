#include <msp430.h> 

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop the watchdog timer
    P1DIR |= BIT6;             // set the direction to the red LED
    P1OUT = 0x00;              // set the initial output to be 0x00
    P1SEL |= BIT6;             // select output signal on red LED
    TACCR0 = 62499;       // set TACCR0 to 62499, or 500,000 microseconds in TACCR0
    TACCTL1 = OUTMOD_7;        // set to mode 7 for the output signal
    TACCR1 = 6250;           // PWM Duty Cycle of 10% (10% of 62499)
    TACTL = TASSEL_2 + MC_1 + ID_3;   // use SMCLK and up mode

    while(1){
        P1OUT ^= BIT6;          // set BIT6 toggle
    }
}
