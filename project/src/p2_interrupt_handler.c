#include <msp430.h>
#include "buttons.h"


// handles switches interrupts on greenboard(p2)
void __interrupt_vec(PORT2_VECTOR) Port_2(){

  if (P2IFG & SW1) { //checks whether button caused interrupt

    P2IFG &= ~SW1; // clears switch interrupt
    sw1_interrupt_handler(); // switch handler
  }
  
  else if (P2IFG & SW2) {

    P2IFG &= ~SW2;
    sw2_interrupt_handler();
  }
  
  else if (P2IFG & SW3) {

    P2IFG &= ~SW3;
    sw3_interrupt_handler();
  }
  
  else if (P2IFG & SW4) {

    P2IFG &= ~SW4;
    sw4_interrupt_handler();
  }
}
