
#include <msp430.h>
#include "buttons.h"
#include "led.h"
#include "buzzer.h"
#include "stateMachines.h"

unsigned char paradiddle_on = 0;
unsigned char nfi_on = 0;
unsigned char whistle_on = 0;
unsigned char turnoff_on = 0;

void selectFunction()
{
  //If button 4 is pressed,all leds and the buzzer is turned off
  if(sw4_state_down){
    paradiddle_on = 0;
    nfi_on = 0;
    whistle_on = 0;
    turnoff_on = 1;
    
  }
  //If button 3 is pressed, the paradiddle state machine is started
  if(sw3_state_down){
    paradiddle_on = 1;
    nfi_on = 0;
    whistle_on = 0;
    turnoff_on = 0;
  }

  //If button 2 is pressed, a song is played
  if(sw2_state_down){
    paradiddle_on = 0;
    nfi_on = 1;
    whistle_on = 0;
    turnoff_on = 0;
  }

  //If button 1 is pressed a whistle occurs
  if(sw1_state_down){
    paradiddle_on = 0;
    nfi_on = 0;
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
// The following two funtions are used to easily switch one led on and the other off
// The right function turns red on, green off and the left function does the opposite
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
  static int period = 250; //period for all beats except the 1st of each measure
  static char beat = 1; // holds the current state value
  static char beat_count = 1; // counts how many beats have occurred
  static int first_beat_period = 100; //period for the first beat  
  turn_leds_off();
  //paradiddle state machine
  switch(beat){
    //Case one operates the first beat
     case 1:
       if (beat_count == 5){
	 turn_green_on();
       }
       else{
	 turn_red_on();
       }
       beat_count++;
       //buzzer_set_period(first_beat_period);
       beat= 3;
       break;
       
     case 2:
       if(beat_count == 2 || beat_count == 7 || beat_count == 8){
	 turn_green_on();
       }
       else if(beat_count == 3 || beat_count == 4 || beat_count == 6){
	 turn_red_on();
       } 
       beat_count++;
       // buzzer_set_period(period);
       beat = 3;
       break;
       
     case 3:
       turn_leds_off();
       turn_buzzer_off();
       if(beat_count == 5 || beat_count == 9){
	 beat = 1;
	 if(beat_count == 9){
	   beat_count == 1;
	 }
       }
       else{
	 beat = 2;
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
void nf_intro(){
  static char nfi_state = 0;
  static int f_note = 1397;
  static int e_note = 1319;
  static int d_note = 1175;
  static int a_note = 880;
  static int d_flat_note = 1109;
  static int b_flat_note = 932;
  switch(nfi_state){
    case 0:
      turn_leds_on();
      buzzer_set_period(f_note);
      nfi_state = 1;
      break;
    case 1:
      right();
      buzzer_set_period(e_note);
      nfi_state = 2;
      break;
    case 2:
      left();
      buzzer_set_period(d_note);
      nfi_state = 3;
      break;
    case 3:
      right();
      buzzer_set_period(d_flat_note);
      nfi_state = 4;
      break;
    case 4:
      turn_leds_on();
      buzzer_set_period(d_note);
      nfi_state = 5;
      break;
    case 5:
      left();
      buzzer_set_period(d_flat_note);
      nfi_state = 6;
      break;
    case 6:
      right();
      buzzer_set_period(b_flat_note);
      nfi_state = 7;
      break;
    case 7:
      left();
      buzzer_set_period(a_note);
      nfi_state = 0;
      break;
  }
  led_changed = 1;
  led_update();
}  

    
	
	
	  
      
    
      
    
  

  

