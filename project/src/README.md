##Project 2: Blinky-Buzzy Toy

#Objective
To make a toy that utilizes interrupts and buttons, leds, and buzzer on the
MSP430.

#Challenges
The main challenge I faced was setting up the Makefile and other code(mainly
the header files) necessary to make the basic functions of the MSP430 work.
Through this process I became much more comfortable with the elements of a
makefile and what needs to be included in them to make the MSP430 work.

Once I got the MSP430 working, I had little issues with creating the state
machines. I used some of the files from the demos (mainly from demos 8,10,11)
to guide me, and adjusted them to fit my needs. The state machine that I had the most
trouble with was the paradiddle method I created. It required turning the
buzzer and leds on and off in a specific and alternating pattern.

#Instuctions
 *Press Button 1 to create a whistle/siren sound that decreases in frequency.
 *Press Button 2 to play a song
 *Press Button 3 to show a paradiddle sequence
 *Press Button 4 to turn off all leds and the buzzer.
