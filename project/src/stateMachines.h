#ifndef stateMachine_included
#define stateMachine_included

// Booleans that hold machine statuses
unsigned char paradiddle_on, nfi_on, whistle_on, turnoff_on;

void selectFunction();
void paradiddle();
void nf_intro();
void whistle();
void turnoff();


#endif
