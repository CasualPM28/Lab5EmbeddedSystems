#include <msp430.h> 

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // Stop the watchdog timer
    P1DIR |= BIT6;             // set the direction to the red LED
    P1OUT = 0x00;              // set the initial output to be 0x00
    P1SEL |= BIT6;             // select output signal on red LED
    TACCR0 = 500000 - 1;       // set TACCR0 to 500ms, or 500,000 microseconds
    TACCTL1 = OUTMOD_7;        // set to mode 7 for the output signal
    TACCR1 = 1000-1;           // PWM Duty Cycle of 10%
    TACTL = TASSEL_1 + MC_1;   // use ACLK and up mode

    while(1){
        P1OUT ^= BIT6;          // set BIT6 toggle
    }
}
