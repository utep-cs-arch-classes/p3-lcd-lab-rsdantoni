#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "move_shapes.h"
#include "switches.h"
#include "buzzer.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main(){
  
  configureClocks();
  switch_p2_init();
  lcd_init();
  buzzer_init();

  enableWDTInterrupts();
  //or_sr(0x08);
  
  clearScreen(COLOR_WHITE);
  init_shapes();
  or_sr(0x18);
}
