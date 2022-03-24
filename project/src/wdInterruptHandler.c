#include <msp430.h>
#include "buttons.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){

  static char blink_count = 0;
  if(++blink_count == 63){

    if(turnoff_on) {
      turnoff();
    }
   else if(whistle_on) {
      whistle();
    }

   else if(paradiddle_on) {
      paradiddle();
    }

   else if(nfi_on) {
      nf_intro();
    }

    blink_count = 0;
  }
}
