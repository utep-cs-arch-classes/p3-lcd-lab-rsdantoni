#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "move_shapes.h"
#include "switches.h"
#include <stdbool.h>

const int unit_height = 5, unit_width = 5;
int turtle_x = screenWidth/2, turtle_y = screenHeight/2;
int donut_x = 20, donut_y = 20;
int barrel_x = screenWidth - 30, barrel_y = screenHeight - 30;
int text_x = screenWidth - 35 , text_y = 15;

turtle turt;
donut don;

int turt_vel_x = 0, turt_vel_y = 0;
int donut_vel_x = 6, donut_vel_y = 6;

void init_shapes(){
  turt.turt_row = turtle_x;
  turt.turt_col = turtle_y;
  turt.old_turt_row = turtle_x;
  turt.old_turt_col = turtle_y;

  don.donut_row = donut_x;
  don.donut_col = donut_y;
  don.old_donut_row = donut_x;
  don.old_donut_col = donut_y;
}

void move_shapes(){
  draw_barrel(barrel_x, barrel_y);
  move_donut(&don);
  move_turtle(&turt);

      
  if(switch1_state == 1){
    turt_vel_x = -5;
    drawString5x7(text_x, text_y, "Left", COLOR_BLACK, COLOR_WHITE);
  }

  if(switch2_state == 1){
    turt_vel_y = 5;
    drawString5x7(text_x, text_y, "Down", COLOR_BLACK, COLOR_WHITE);
  }
  
  if (switch3_state == 1){
    turt_vel_x = 5;
     drawString5x7(text_x, text_y, "Right", COLOR_BLACK, COLOR_WHITE);
  } 

  if(switch4_state == 1){
    turt_vel_y = -5;
    drawString5x7(text_x, text_y, "Up", COLOR_BLACK, COLOR_WHITE);
 }
}


void move_turtle(turtle *to_draw){


 // if(turt_vel_x >= 0){
  draw_right_turtle(to_draw->old_turt_row, to_draw->old_turt_col, true);
  draw_right_turtle(to_draw->turt_row, to_draw->turt_col, false);
    // }

  to_draw-> old_turt_row = to_draw->turt_row;
  to_draw->old_turt_col = to_draw->turt_col;

  to_draw->turt_row += turt_vel_x;
  to_draw->turt_col += turt_vel_y;
  
  if( (to_draw->turt_row + 4.5) >= screenWidth ){
      to_draw->turt_row = 5;
  }

  if( (to_draw->turt_row - 4.5) <= 0 ){
      to_draw->turt_row = screenWidth - 4.5;
  }
}

void move_donut(donut *to_draw){
  draw_donut(to_draw->old_donut_row, to_draw->old_donut_col, true);
  draw_donut(to_draw->donut_row, to_draw->donut_col, false);

  to_draw->old_donut_row = to_draw->donut_row;
  to_draw->old_donut_col = to_draw->donut_col;

  to_draw->donut_row += donut_vel_x;
  to_draw->donut_col += donut_vel_y;

  if ( (to_draw->donut_col) + 20 >= screenHeight || (to_draw->donut_col - 20) <= 0){
    donut_vel_y *= -1;
  }

  if ( (to_draw->donut_row + 20) >= screenWidth || (to_draw->donut_row - 20) <= 0){
    donut_vel_x *= -1;
  }
}