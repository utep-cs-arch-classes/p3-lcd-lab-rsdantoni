#include <msp430.h>
#include "libTimer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include "buzzer.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  const  unsigned int second_limit = 50;
  static unsigned int second_count = 0;

  check_p2_switches();
  second_count++;
  
  if (second_count >= second_limit) {
    move_shapes();
    buzzer_set_period(1000);
    
    second_count = 0;
  }
} 
