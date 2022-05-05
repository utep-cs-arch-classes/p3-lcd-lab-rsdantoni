#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"
#include "switches.h"
#include <stdbool.h>

const int unit_height = 5, unit_width = 5;

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
