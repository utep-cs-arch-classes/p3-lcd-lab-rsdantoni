#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include <stdbool.h>

const int unit_height = 5, unit_width = 5;
int turtle_x = screenWidth/2, turtle_y = screenHeight/2;
int donut_x = 20, donut_y = 20;
int barrel_x = screenWidth - 30, barrel_y = screenHeight - 30;

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
}

void draw_right_turtle(int x, int y, bool erase){
   
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
  
  int left_col = x - (6 * unit_width / 2);
  int top_row  =  y;
  top_row -= (3 * unit_height / 2);
  fillRectangle(left_col, top_row, unit_width * 6, unit_height * 3, shell_color);

  left_col = x - (4 * unit_width / 2); 
  top_row -= unit_height;
  fillRectangle(left_col, top_row, unit_width * 4, unit_height, shell_color);

  left_col = x - (2 * unit_width / 2);
  top_row -= unit_height;
  fillRectangle(left_col, top_row, 2 * unit_width, unit_height, shell_color);

  left_col = x - (6 * unit_height / 2);
  top_row += unit_height * 5;
  fillRectangle(left_col, top_row, 2 * unit_width, 2 * unit_height, flesh_color);

  left_col = x - (2 * unit_width / 2);
  fillRectangle(left_col, top_row, 2 * unit_width, unit_height, flesh_color);

  left_col = x + (2 * unit_width / 2);
  fillRectangle(left_col, top_row, 2 * unit_width, 2 * unit_height, flesh_color);

  left_col = x + (6 * unit_width / 2);
  top_row -= 4 * unit_height;
  fillRectangle(left_col, top_row, 2 * unit_width, 4 * unit_height, flesh_color);

  left_col = x + (8 * unit_width / 2);
  top_row += unit_height;
  fillRectangle(left_col, top_row, unit_width, unit_height, eye_color);

}

void move_turtle(turtle *to_draw){
    
  if(switch1_state == 1){
    turt_vel_x = -5;
    drawString5x7(screenWidth - 20, screenHeight - 20, "Left", COLOR_BLACK, COLOR_WHITE);
  }

  if(switch2_state == 1){
    turt_vel_y = 5;
    drawString5x7(screenWidth - 20, screenHeight - 20, "Down", COLOR_BLACK, COLOR_WHITE);

  }
  
  if (switch3_state == 1){
    turt_vel_x = 5;
     drawString5x7(screenWidth - 20, screenHeight - 20, "Right", COLOR_BLACK, COLOR_WHITE);

  } 


  if(switch4_state == 1){
    turt_vel_y = -5;
    drawString5x7(screenWidth - 20, screenHeight - 20, "Up", COLOR_BLACK, COLOR_WHITE);
 }

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

void draw_donut(int x_coord, int y_coord, bool erase){
  
  u_int frosting_color, bread_color;

  if(erase){
    frosting_color = COLOR_WHITE;
    bread_color = COLOR_WHITE;
  } else {
    frosting_color = COLOR_PINK;
    bread_color = COLOR_TAN;
  }
  
  draw_circle(x_coord, y_coord, 20, bread_color);
  draw_circle(x_coord, y_coord, 18, frosting_color);
  draw_circle(x_coord, y_coord, 10, COLOR_WHITE);
}

void draw_barrel(int x, int y){
  u_int barrel_color = COLOR_BLACK;
  u_int warning_color = COLOR_YELLOW;

  int top_row = y - (7 * unit_height / 2);
  int left_col = x - (4 * unit_height / 2);

  fillRectangle(left_col, top_row, 4 * unit_width, 7 * unit_height, barrel_color);
  draw_circle(x, y, 5, warning_color);
}


void draw_horizontal_line(u_int x_start, u_int x_end, u_int y, u_int colorBGR) {
  u_int length = x_end - x_start;
  // set the draw area from the start of the line to the end
  // height is 1 since its a line
  lcd_setArea(x_start, y, x_end, y);
  for (u_int i = 0; i < length; i++) {
    lcd_writeColor(colorBGR);
  }
  
}

void draw_lines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color) {
  // bottom
  draw_horizontal_line(x_coord - x_point, x_coord + x_point, y_coord + y_point, color);
  // top
  draw_horizontal_line(x_coord - x_point, x_coord + x_point, y_coord - y_point, color);
  // and the middle two
  draw_horizontal_line(x_coord - y_point, x_coord + y_point, y_coord + x_point, color);
  draw_horizontal_line(x_coord - y_point, x_coord + y_point, y_coord - x_point, color);
					  
}

void draw_circle(int x_coord, int y_coord, int r, u_int color) {
  int x_point = 0;
  int y_point = r;
  int decision = 3 - (2 * r);

  draw_lines(x_coord, y_coord, x_point, y_point, color);

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
    draw_lines(x_coord, y_coord, x_point, y_point, color);
  }
}
