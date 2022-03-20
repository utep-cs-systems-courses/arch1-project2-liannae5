#ifndef switches_included

#define switches_included



/* Defining all the switches */

//#define SW_POWEROFF BIT3 /* Poweroff switch is in port p1.3 */

//#define SWITCH SW_POWEROFF /* Poweroff switch is in the redboard */

#define SW1 BIT0 // p2.0 = switch 1

#define SW2 BIT1 // p2.1 = switch 2

#define SW3 BIT2 // p2.2 = switch 3 

#define SW4 BIT3 // p2.3 = switch 4

#define SWITCHES (SW1 | SW2 | SW3 | SW4) // Switches 1-4 on green board

void switch_init();
void sw1_interrupt_handler();
void sw2_interrupt_handler();
void sw3_interrupt_handler();
void sw4_interrupt_handler();

#endif
