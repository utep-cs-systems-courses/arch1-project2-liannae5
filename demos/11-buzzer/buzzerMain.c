#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
    enableWDTInterrupts();
 
    buzzer_init();
    int count = 0;
    // buzzer_set_period(1500);/* start buzzing!!! 2MHz/1000 = 2kHz*/
     


    or_sr(0x18);          // CPU off, GIE on
}
int secondCount = 0;
void __interrupt_vec(WDT_VECTOR) WDT(){

  secondCount++;
  if(secondCount >=250){
    buzzer_set_period(500);
    secondCount = 0;
  }
  else{
    buzzer_set_period(0);
  }

}
