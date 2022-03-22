#include <msp430.h>
#include "buttons.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){

  static char blink_count = 0;
  if(++blink_count == 125){

    if(turnoff_on) {
      turnoff();
    }
    if(whistle_on) {
      whistle();
    }

    else if(paradiddle_on) {
      paradiddle();
    }

    else if(hcb_on) {
      hotCrossBuns();
    }

    blink_count = 0;
  }
}
