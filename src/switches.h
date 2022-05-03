#ifndef switches_included
#define switches_included

#define S1 BIT0;
#define S2 BIT1;
#define S3 BIT2;
#define S4 BIT3;

void switch_p2_init(void);         /* Initializes the port 2 switches */
void check_p2_switches(void);      /* Checks the port 2 switches */

extern char switch1_state, switch2_state, switch3_state, switch4_state;