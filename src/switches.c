#include <msp430.h>
#include "switches.h"

char switch1_state, switch2_state, switch3_state, switch4_state;

static char switch_update_interrupt_sense(void) {
  char p2val = P2IN;
  P2IES |= (p2val &  P2_SWITCHES);	// if switch up, sense down
  P2IES &= (p2val | ~P2_SWITCHES);	// if switch down, sense up
  return p2val;
}

/* setup switches */
void 
switch_p2_init(void)
{  
  P2REN |=  P2_SWITCHES;		// enables resistors for switches
  P2IE  |=  P2_SWITCHES;		// enable interrupts from switches
  //P2OUT |=  SWITCHES;		// turn on switches so we can read them
  P2DIR &= ~P2_SWITCHES;	 	// set switch pins to input
  switch_update_interrupt_sense();
}

void
check_p2_switches(void)
{
  char p2val = switch_update_interrupt_sense();
  switch1_state = (p2val & S1) ? 0 : 1;
  switch2_state = (p2val & S2) ? 0 : 1;
  switch3_state = (p2val & S3) ? 0 : 1;
  switch4_state = (p2val & S4) ? 0 : 1;
}
