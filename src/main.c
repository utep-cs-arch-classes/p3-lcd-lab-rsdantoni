#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!! 

void main()
{
  configureClocks();
  lcd_init();

  // clear the screen in case something is already on there
  clearScreen(COLOR_WHITE);

  draw_turtle(screenWidth/2, screenHeight/2);
}
