#ifndef switches_included
#define switches_included

// Defining all switches 

#define SW1 BIT0 // port p2.0 = switch1

#define SW2 BIT1 // port p2.1 = switch2

#define SW3 BIT2 // port p2.2 = switch3

#define SW4 BIT3 // port p2.3 = switch4

#define SWITCHES (SW1 | SW2 | SW3 | SW4) // to hold all switches on greenboard 


// Functions to handle buttons
void switch_init();
void sw1_interrupt_handler();
void sw2_interrupt_handler();
void sw3_interrupt_handler();
void sw4_interrupt_handler();


// booleans that hold values whether button is pressed

extern char sw1_state_down, sw1_state_changed,
  sw2_state_down, sw2_state_changed,
  sw3_state_down, sw3_state_changed,
  sw4_state_down, sw4_state_changed;

#endif 
