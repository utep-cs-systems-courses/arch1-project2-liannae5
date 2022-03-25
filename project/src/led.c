#include <msp430.h>
#include "led.h"
#include "stateMachines.h"
#include "buttons.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;// bits attached to leds are output
  led_changed = 1;
  led_update();
}

void led_update()
{
  if (led_changed) {
    char ledFlags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;     // set bit for on leds
    led_changed = 0;
  }
}

//Turns red led on
void turn_red_on()
{
  red_on = 1;
}
//Turns red led off
void turn_red_off()
{
  red_on = 0;
}
//Turns green led on
void turn_green_on()
{
  green_on = 1;
}
//Turns green off
void turn_green_off()
{
  green_on = 0;
}
//Turns both leds off
void turn_leds_off()
{
  green_on = 0;
  red_on = 0;
}
//Turns both leds on
void turn_leds_on()
{
  green_on = 1;
  red_on = 1;
}
//Turns right (red) led on, and turns left (green) led off
void right(){
  turn_red_on();
  turn_green_off();
}
//Turns left (green) led on, and turns right(led) off
void left(){
  turn_red_off();
  turn_green_on();
}

