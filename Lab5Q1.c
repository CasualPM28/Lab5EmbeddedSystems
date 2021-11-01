#include <msp430.h> 
#define RedLED BIT6         // set BIT6 to RedLED
#define GreenLED BIT0       // set BIT0 to GreenLED
#define ToggleLeds (P1OUT ^= RedLED|GreenLED)    // define variable ToggleLeds to be "P1OUT ^= RedLED|GreenLED
#define Button BIT3         // set BIT3 to Button

void main(void)
{
    BCSCTL2 |= DIVS_3;     // set basic clock system register to SMCLK
	WDTCTL = WDT_MDLY_32; // set watchdog timer to 32s, of SMCLK(1MHz) in Timer mode
	IE1 |= WDTIE;        // enable interrupt on WDT
	P1DIR = RedLED|GreenLED; // set the pin direction to be either the red or green LED
	P1OUT = RedLED;       // set the initial direction to be the red LED
	_enable_interrupts(); // enable the interrupts
	LPM1;                 // put microcontroller in low power mode, (disables CPU, MCLK, DCO)
}
#pragma vector = WDT_VECTOR // enable vector on watchdog timer vector
__interrupt void WDT(void)
{
    P1OUT = ToggleLeds;   // alternate between GreenLED or RedLED from defined variable above
}
