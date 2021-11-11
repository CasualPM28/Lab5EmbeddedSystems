# Lab5EmbeddedSystems - Vincent Agostino Del Tufo
Lab 5 for Embedded Systems - Section 4

The code within this Git repository is for Lab 5 for Embedded Systems.

Q1.) 
The clock was configured to have a 256ms delay. This was done by first setting the watchdog timer to WDTCTL = WDT_MDLY_32. Use the SMCLK of 1MHz, which is needed as f = 1/T so 1/(256E-3)= 3.90625Hz. This led to the choice of the SMCLK, with a WDT_MDLY_32 as that is the highest timer setting. The next part was to set the basic clock system, BCSCTL2 to the clock divider of DIVS_3, which resulted in a clock divider of 8. 256/8 = 32, so this proves that the right watchdog timer was chosen from a clock divider of 8. The value in this Being that this program utilized ![image](https://user-images.githubusercontent.com/60796502/141367191-28c0e3ed-4321-4fcd-86d6-8d4ae44dd143.png)
