#include <msp430.h>
#include "buttons.h"
#include "led.h"
#include "stateMachines.h"


char sw1_state_down, sw1_state_changed,

  sw2_state_down, sw2_state_changed,

  sw3_state_down, sw3_state_changed,

  sw4_state_down, sw4_state_changed;

// handle when each respective is pressed/unpressed
static char sw1_update_interrupt_sense()
{
  char p2val = P2IN;
  // Update switch interrupt to detect changes from current buttons
  P2IES |= (p2val & SW1);// If switch up, sense down 
  P2IES &= (p2val | ~SW1);// If switch down, sense up
  return p2val;
}

static char sw2_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SW2);
  P2IES &= (p2val | ~SW2);
  return p2val;
}

static char sw3_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SW3);
  P2IES &= (p2val | ~SW3);
  return p2val;
}

static char sw4_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SW4);
  P2IES &= (p2val | ~SW4);
  return p2val;
}

// Initializes switches
void switch_init()
{
  P2REN |= SWITCHES; // Enables resistors for switches 
  P2IE |= SWITCHES; // Enable interrupts from switches 
  P2OUT |= SWITCHES; // Pull-ups for switches 
  P2DIR &= ~SWITCHES; // Set switches' bits for input

  // Detect button presses 
  sw1_update_interrupt_sense();
  sw2_update_interrupt_sense();
  sw3_update_interrupt_sense();
  sw4_update_interrupt_sense();

}

void sw1_interrupt_handler()
{
  char p2val = sw1_update_interrupt_sense();
  sw1_state_down = (p2val & SW1) ? 0 : 1;
  sw1_state_changed = 1;
}


void sw2_interrupt_handler()
{
  char p2val = sw2_update_interrupt_sense();
  sw2_state_down = (p2val & SW2) ? 0 : 1;
  sw2_state_changed = 1;
}

void sw3_interrupt_handler()
{
  char p2val = sw3_update_interrupt_sense();
  sw3_state_down = (p2val & SW3) ? 0 : 1;
  turn_green_on();
  sw3_state_changed = 1;
  selectFunction();
  led_update();
}


void sw4_interrupt_handler()
{
  char p2val = sw4_update_interrupt_sense();
  sw4_state_down = (p2val & SW4) ? 0 : 1;
  sw4_state_changed = 1;
  selectFunction();
  led_update();
}
