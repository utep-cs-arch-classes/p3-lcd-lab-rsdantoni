#include <msp430.h>
#include "libTimer.h"
#include "switches.h"
#include "buzzer.h"
#include "buzzer_sounds_c.h"

void buzzer_init()
{
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles) /* buzzer clock = 2MHz.  (period of 1k results in 2kHz tone) */
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

void buzzer_switch_handler(){
  if(switch1_state == 1){
    buzzer_set_period(getBuzzerCycle(0))
  } else if(switch1_state == 1){
    buzzer_set_period(getBuzzerCycle(2))
  } else if(switch1_state == 1){
    buzzer_set_period(getBuzzerCycle(4))
  } else if(switch1_state == 1){
    buzzer_set_period(getBuzzerCycle(7))
  }
}
