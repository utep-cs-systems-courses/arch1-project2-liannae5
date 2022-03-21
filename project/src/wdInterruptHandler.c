#include <msp430.h>
#include "buttons.h"
#include "led.h"
#include "stateMachines.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){

  static char blink_count = 0;
  if(++blink_count == 125){
    if(turnoff_on)
    {
      turnoff();
    }
    
   if(whistle_on)
    {
      whistle();
    }
   if(paradiddle_on){
     paradiddle();
   }
   blink_count = 0;
  }
}
