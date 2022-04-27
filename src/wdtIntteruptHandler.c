#include <msp430.h>
#include "libTimer.h"
#include "draw_shapes.h"

void __interrupt_vec(WDT_VECTOR) WDT(){
  const  u_int second_limit = 50;
  static u_int second_count = 0;

  second_count++;

  if (second_count >= second_limit) {
    move_turtle();
    second_count = 0;
  }
} 