# Lab5EmbeddedSystems - Vincent Agostino Del Tufo
Lab 5 for Embedded Systems - Section 4

The code within this Git repository is for Lab 5 for Embedded Systems.

Q1.) 
The clock was configured to have a 256ms delay. This was done by first setting the watchdog timer to WDTCTL = WDT_MDLY_32. Use the SMCLK of 1MHz, which is needed as f = 1/T so 1/(256E-3)= 3.90625Hz. This led to the choice of the SMCLK, with a WDT_MDLY_32 as that is the highest timer setting. The next part was to set the basic clock system, BCSCTL2 to the clock divider of DIVS_3, which resulted in a clock divider of 8. 256/8 = 32, so this proves that the right watchdog timer was chosen from a clock divider of 8. The value in the register for the clock was 0x06![image](https://user-images.githubusercontent.com/60796502/141367344-6ba1358e-c868-4807-9bc7-1a7f04b85387.png)


Being that this program utilized interrupts to switch the LEDs, interrupt flags were delcared and enabled, (IE1 |= WDTIE, enable_interrupts()). The values in these registers after running the program were ![image](https://user-images.githubusercontent.com/60796502/141367888-ebd45a86-5219-4d2a-8451-369423f9c891.png)


xz
