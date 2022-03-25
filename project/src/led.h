# include <msp430.h>
#ifndef led_included
#define led_included

#define LED_RED BIT6               // P1.6
#define LED_GREEN BIT0             // P1.0
#define LEDS (BIT0 | BIT6)

extern unsigned char red_on, green_on;
extern unsigned char led_changed;

void led_init();
void led_update();
void turn_leds_off();
void turn_leds_on();
void turn_red_on();
void turn_green_on();
void turn_red_off();
void turn_green_off();
void right();
void left();


#endif // included
