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
  drawDonut(50,50);
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

void drawDonut(int x_coord, int y_coord){
  draw_circle(x_coord, y_coord, 20, COLOR_TAN);
  draw_circle(x_coord, y_coord, 18, COLOR_PINK);
  draw_circle(x_coord, y_coord, 10, COLOR_WHITE);
}


void drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR) {
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
  
}

void drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color) {
  // bottom
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  drawHorizontalLine(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  drawHorizontalLine(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

void draw_circle(int x_coord, int y_coord, int r, u_int color) {
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  drawLines(x_coord, y_coord, x_point, y_point, color);

  while (y_point >= x_point) {
    // move x over one
    x_point++;

    // check decision point
    if (decision > 0) {
      // move y down one
      y_point--;
      decision = decision + 4 * (x_point - y_point) + 10;
    } else {
      decision = decision + 4 * x_point + 6;
    }
    drawLines(x_coord, y_coord, x_point, y_point, color);
  }
}
