
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
  if(sw3_state_down){
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
  else if(sw1_state_down){
    paradiddle_on = 0;
    hcb_on = 0;
    whistle_on = 1;
    turnoff_on = 0;
  }
}

// The following functions turn the leds on or off

void turn_red_on()
{
  red_on = 1;
}

void turn_red_off()
{
  red_on = 0;
}
void turn_green_on()
{
  green_on = 1;
}

void turn_green_off()
{
  green_on = 0;
}

void turn_leds_off()
{
  green_on = 0;
  red_on = 0;
}

void turn_leds_on()
{
  green_on = 1;
  red_on = 1;
}

void turn_buzzer_off()
{
  buzzer_set_period(0);
}
// The following two funtions are used in the paradiddle machine
// They turn one led on and the other led off
void right(){
  turn_red_on();
  turn_green_off();
}
void left(){
  turn_red_off();
  turn_green_on();
}

 
// Uses switch 4 (P2.3) to turnoff all leds and the buzzer
void turnoff()

{
  turn_green_off();
  turn_red_off();
  buzzer_set_period(0);
  led_changed = 1;
  led_update();

}

//The paradiddle machine loops the most basic drumming paradiddle: RLRR LRLL
//The red led represents an R (right) and the green is L (left). 
void paradiddle()
{
  static int period = 750; 
  static char beat = 1;
  static char beat_count = 1;
  static int first_beat_period = 500;
  turn_leds_off();
  switch(beat){
     case 1:
       if (beat_count == 5){
	 turn_green_on();
       }
       else{
	 turn_red_on();
       }
       beat_count++;
       
        buzzer_set_period(first_beat_period);
        beat= 3;
        break;
     case 2:
       if(beat_count > 4){
	 if(beat_count == 6)
	   {
	     turn_red_on();
	   }
	 else{
	   if(beat_count >= 8){
	     beat_count = 0;
	   }
	   turn_green_on();
	 }
       }
       else{
	 if(beat_count == 2){
	   turn_green_on();
	 }
	 else{
	   turn_red_on();
	     }
       }
       buzzer_set_period(period);
       beat_count++;
       beat = 3;
       break;
     case 3:
       turn_leds_off();
       turn_buzzer_off();
       if(beat_count == 5){
	 beat = 1;
       }
       else{
	 beat = 2;
       }
       if(beat_count == 8){
	 beat_count == 1;
       } 
       break;
  }
   
  led_changed = 1;
  led_update();
    
}
    
   
void whistle()
{
  static int period = 1000;
  static char whistle_state = 0;
  turn_red_on();
  switch (whistle_state) {
  case 0:
    if(period == 100){
      period = 1000;
    }
 
    right();
    period = period - 100;
    buzzer_set_period(period);
    whistle_state = 1;
    break;
  case 1:
    if(period == 100){
      period = 1000;
    }
 
    left();
    period = period - 100;
    buzzer_set_period(period);
    whistle_state = 0;
    break;
  }
  led_changed = 1;
  led_update();
}
void hotCrossBuns(){
  static char hcb_state = 0;
  static char bag_repeat = 0;
  static char note_repeat = 0;
  static char end_song = 0;
  static int g_note = 247;
  static int a_note = 220;
  static int b_note = 196;
  switch(hcb_state){
    case 0:
      turn_leds_on();
      buzzer_set_period(b_note);
      hcb_state = 1;
      break;
    case 1:
      right();
      buzzer_set_period(a_note);
      hcb_state = 2;
      break;
    case 2:
      left();
      buzzer_set_period(g_note);
      if(bag_repeat == 0){
	hcb_state = 0;
	bag_repeat = 1;
      }
      else if(end_song){
	end_song = 0;
	hcb_state = 4;
      }
      else{
	bag_repeat = 0;
	hcb_state = 3;
      }
      break;
    case 3:
      turn_buzzer_off();
      turn_leds_off();
      if(note_repeat >= 3){
	buzzer_set_period(g_note);
	left();
	hcb_state = 3;
	note_repeat++;
      }
      else{
	buzzer_set_period(a_note);
	right();
	if(note_repeat == 7){
	  note_repeat = 0;
	  hcb_state = 0;
	  end_song = 1;
	}
	else{
	  hcb_state = 3;
	  note_repeat++;
	}
      }
      break;
    case 4:
      turn_buzzer_off();
      turn_leds_off();
      hcb_state = 0;
      break;
  }
}
    
	
	
	  
      
    
      
    
  

  

