# Lab5EmbeddedSystems - Vincent Agostino Del Tufo
Lab 5 for Embedded Systems - Section 4

The code within this Git repository is for Lab 5 for Embedded Systems.

Q1.) 
The clock was configured to have a 256ms delay. This was done by first setting the watchdog timer to WDTCTL = WDT_MDLY_32. Use the SMCLK of 1MHz, which is needed as f = 1/T so 1/(256E-3)= 3.90625Hz. This led to the choice of the SMCLK, with a WDT_MDLY_32 as that is the highest timer setting. The next part was to set the basic clock system, BCSCTL2 to the clock divider of DIVS_3, which resulted in a clock divider of 8. 256/8 = 32, so this proves that the right watchdog timer was chosen from a clock divider of 8. The value in the register for the clock was 0x06![image](https://user-images.githubusercontent.com/60796502/141367344-6ba1358e-c868-4807-9bc7-1a7f04b85387.png)


Being that this program utilized interrupts to switch the LEDs, interrupt flags were delcared and enabled, (IE1 |= WDTIE, enable_interrupts()). The value in the interrupt flag register after running the program was 0x01.![image](https://user-images.githubusercontent.com/60796502/141367888-ebd45a86-5219-4d2a-8451-369423f9c891.png)


The GIE bit in the register was recorded as 1, ![image](https://user-images.githubusercontent.com/60796502/141368327-5f2dadad-f4e3-4040-af9a-7e87c6ff0e91.png)


Q2.) This question was about the generation of a PWM using software that would control the brightness of an LED. It can be seen in the image below that the PWM wave was correctly generated. Additionally, the chart of the calculated vs. measured Duty Cycle, Period, and Frequency are seen below. The hand calculations for each calculated measurement is also seen below. The only value to be caluclated was the frequency, which was found to be 2Hz. The measured duty cycle, period, and frequency were 10.003%, 481.62ms, and 2.076Hz respectively. These values matched the measured values from the oscilloscope. Unlike Q3, the below images show the Level 0 diagram of the PWM generator and it's UML diagram.

![image](https://user-images.githubusercontent.com/60796502/141378426-2b21294e-8944-47f4-8be0-b46c7948aa6f.png)
![image](https://user-images.githubusercontent.com/60796502/141378582-84e45432-ce16-4265-afe2-d6c32fbabb90.png)
![image](https://user-images.githubusercontent.com/60796502/141378630-0980f559-9b10-4ce7-89c7-74007965f774.png)
![image](https://user-images.githubusercontent.com/60796502/141378662-584fc0ee-5312-4c4e-adac-5ce332ee6812.png)
![image](https://user-images.githubusercontent.com/60796502/141378675-e7edaa29-6762-4e09-95b7-3ac798297681.png)



Q3.) This question was about the generation of a PWM using hardware that would control the brightness of an LED. It can be seen in the image below that the PWM wave was correctly generated. Additionally, the chart of the calculated vs. measured Duty Cycle, Period, and Frequency are seen below. The hand calculations for each calculated measurement is also seen below. The only value to be caluclated was the frequency, which was found to be 4Hz. The measured duty cycle, period, and frequency were 20.00%, 240.72ms, and 4.154Hz respectively. These values matched the measured values from the oscilloscope.

![image](https://user-images.githubusercontent.com/60796502/141378695-502fa30e-3431-4fda-9229-fc9d820c61e2.png)
![image](https://user-images.githubusercontent.com/60796502/141378833-47ae4fb4-f6b7-40d2-95c3-7e7d927c6d26.png)
![image](https://user-images.githubusercontent.com/60796502/141378711-90996359-6d4b-4779-bbae-3ec2373cf823.png)



