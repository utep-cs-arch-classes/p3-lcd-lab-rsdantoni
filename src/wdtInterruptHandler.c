#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  const  unsigned int second_limit = 50;
  static unsigned int second_count = 0;

  second_count++;

  if (second_count >= second_limit) {
    move_shapes();
    second_count = 0;
  }
} 
