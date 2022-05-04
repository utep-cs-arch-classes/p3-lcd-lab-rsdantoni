#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include <stdbool.h>

const int unit_height = 5, unit_width = 5;
int turtle_x = screenHeight/2, turtle_y = screenWidth/2;
turtle turt;
int turt_vel_x = 0;
int turt_vel_y = 0;

void draw_right_turtle(int turtle_x, int turtle_y, bool erase){
   
    u_int shell_color, flesh_color, eye_color;

    if(erase){
      shell_color = COLOR_WHITE;
      flesh_color = COLOR_WHITE;
      eye_color = COLOR_WHITE;
    } else{
      shell_color = COLOR_DARK_GREEN;
      flesh_color = COLOR_TAN;
      eye_color = COLOR_BLACK;
    }
    
    int left_col = turtle_x - (6 * unit_width / 2);
    int top_row  =  turtle_y;
    top_row -= (3 * unit_height / 2);
    fillRectangle(left_col, top_row, unit_width * 6, unit_height * 3, shell_color);

    left_col = turtle_x - (4 * unit_width / 2); 
    top_row -= unit_height;
    fillRectangle(left_col, top_row, unit_width * 4, unit_height, shell_color);

    left_col = turtle_x - (2 * unit_width / 2);
    top_row -= unit_height;
    fillRectangle(left_col, top_row, 2 * unit_width, unit_height, shell_color);

    left_col = turtle_x - (6 * unit_height / 2);
    top_row += unit_height * 5;
    fillRectangle(left_col, top_row, 2 * unit_width, 2 * unit_height, flesh_color);

    left_col = turtle_x - (2 * unit_width / 2);
    fillRectangle(left_col, top_row, 2 * unit_width, unit_height, flesh_color);

    left_col = turtle_x + (2 * unit_width / 2);
    fillRectangle(left_col, top_row, 2 * unit_width, 2 * unit_height, flesh_color);

    left_col = turtle_x + (6 * unit_width / 2);
    top_row -= 4 * unit_height;
    fillRectangle(left_col, top_row, 2 * unit_width, 4 * unit_height, flesh_color);

    left_col = turtle_x + (8 * unit_width / 2);
    top_row += unit_height;
    fillRectangle(left_col, top_row, unit_width, unit_height, eye_color);
  
}

void move_shapes(){
  move_turtle(&turt);
}

void init_shapes(){
    turt.turt_row = turtle_x;
    turt.turt_col = turtle_y;
    turt.old_turt_row = turtle_x;
    turt.old_turt_col = turtle_y;
}

void move_turtle(turtle *to_draw){
    
  if(switch1_state == 1){
    turt_vel_x = -5;
  }

  if(switch2_state == 1){
    turt_vel_y = 5;
  }
  
  if (switch3_state == 1){
    turt_vel_x = 5;
  }

  if(switch4_state == 1){
    turt_vel_y = -5;
  }

  // if(turt_vel_x >= 0){
    draw_right_turtle(to_draw->old_turt_row, to_draw->old_turt_col, true);
    draw_right_turtle(to_draw->turt_row, to_draw->turt_col, false);
      // }

    to_draw-> old_turt_row = to_draw->turt_row;
    to_draw->old_turt_col = to_draw->turt_col;

    to_draw->turt_row += turt_vel_x;
    to_draw->turt_col += turt_vel_y;
    
    if( (to_draw->turt_col + 4) >= screenWidth ){
        to_draw->turt_col = 4;
    }

    if( (to_draw->turt_col - 4) <= 0 ){
        to_draw->turt_col = screenWidth - 4;
    }
}
