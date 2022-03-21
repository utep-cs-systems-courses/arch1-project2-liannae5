#include <msp430.h>
#include "buttons.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"

unsigned char paradiddle_on = 0;
unsigned char hcb_on = 0;
unsigned char whistle_on = 0;
unsigned char turnoff_on = 0;

void selectFunction()
{
  if(sw4_state_down){
    paradiddle_on = 0;
    hcb_on = 0;
    whistle_on = 0;
    turnoff_on = 1;
    
  }
  if(sw1_state_down){
    paradiddle_on = 1;
    hcb_on = 0;
    whistle_on = 0;
    turnoff_on = 0;
  }
  else if(sw2_state_down){
    paradiddle_on = 0;
    hcb_on = 1;
    whistle_on = 0;
    turnoff_on = 0;
  }
  else if(sw3_state_down){
    paradiddle_on = 0;
    hcb_on = 0;
    whistle_on = 1;
    turnoff_on = 0;
  }
}

/* These functions will signal if either LED is on or off */

void turn_red_on()
{
  red_on = 1;
}

void turn_green_on()
{
  green_on = 1;
}

void turn_red_off()
{
  red_on = 0;
}

void turn_green_off()
{
  green_on = 0;
}
void right(){
  turn_red_on();
  turn_green_off();
}
void left(){
  turn_red_off();
  turn_green_on();
}
/* These functions are the states of the machines and what each one will do. */



/* This particular state machine will power off all the LEDS 

   and shut down the buzzer. This will be mapped out to

   switch P1.3 on the red board (SW_POWEROFF).

*/

void turnoff()

{
  turn_green_off();
  turn_red_off();
  buzzer_set_period(0);

  led_changed = 1;

  led_update();

}

void paradiddle()
{
  static int period = 750; 
  static char beat_count = 1;
  static int first_beat_period = 500;
  turn_red_on();
  switch(beat_count){
     case 1:
        right();
        buzzer_set_period(first_beat_period);
        beat_count++;
        break;
     case 2:
        left();
        buzzer_set_period(period);
        beat_count++;
        break;
     case 3:
        right();
        buzzer_set_period(period);
        beat_count++;
        turn_red_off();
        break;
      case 4:
 	right();
	buzzer_set_period(period);
	beat_count++;
	break;
      case 5:
	left();
	buzzer_set_period(first_beat_period);
	beat_count++;
	break;
      case 6:
        right();
	buzzer_set_period(period);
	beat_count++;
	break;
      case 7:
	left();
	buzzer_set_period(period);
	beat_count++;
	turn_green_off();
	break;
      case 8:
	left();
	buzzer_set_period(period);
	beat_count = 0;
	break;
  }
  led_changed = 1;
  led_update();
    
}
    
    
 
void whistle()
{
  static enum {R=0, G=1} color = G;

  static int period = 1000;
  turn_red_on();
  switch (color) {

  case R:
    if(period == 0){
      period = 1000;
    }
    turn_red_on();
    turn_green_on();
    period = period - 100;
    buzzer_set_period(period);
    color = G;
    break;
  case G:
    if(period == 0){
      period = 1000;
    }
    turn_green_off();
    turn_red_off();
    period = period - 100;
    buzzer_set_period(period);
    color = R;
    break;
  }
  led_changed = 1;
  led_update();
}


