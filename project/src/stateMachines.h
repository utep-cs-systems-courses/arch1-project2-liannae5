#ifndef stateMachine_included
#define stateMachine_included

// Booleans that hold machine statuses
unsigned char paradiddle_on, hcb_on, whistle_on, turnoff_on;

void selectFunction();
void paradiddle();
void hotCrossBuns();
void whistle();
void turnoff();
void turn_red_on();
void turn_green_on();
void turn_red_off();
void turn_green_off();
void right();
void left();

#endif
