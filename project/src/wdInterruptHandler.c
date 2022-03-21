#include <msp430.h>
#include "buttons.h"
#include "led.h"
#include "stateMachine.h"

void __interrupt_vec(WDT_VECTOR) WDT(){

  static char blink_count = 0;
  if (++blink_count == 125) {
    blink_count = 0;

  }

  
}
