#include "lcdutils.h"
#include "lcddraw.h"

    int unit_height = 5, unit_width = 5;

void draw_turtle(int x, int y){
   
    u_int shellColor = COLOR_DARK_GREEN;
    u_int fleshColor = COLOR_TAN;
    
    int left_col = x - (6 * unit_width / 2);
    int top_row  =  y;
    top_row -= (3 * unit_height / 2);
    fillRectangle(left_col, top_row, unit_width * 6, unit_height * 3, shellColor);

    left_col = x - (4 * unit_width / 2); 
    top_row -= unit_height;
    fillRectangle(left_col, top_row, unit_width * 4, unit_height, shellColor);

    left_col = x - (2 * unit_width / 2);
    top_row -= unit_height;
    fillRectangle(left_col, top_row, 2 * unit_width, unit_height, shellColor);

    left_col = x - (6 * unit_height / 2);
    top_row += unit_height * 5;
    fillRectangle(left_col, top_row, 2 * unit_width, 2 * unit_height, fleshColor);

    left_col = x - (2 * unit_width / 2);
    fillRectangle(left_col, top_row, 2 * unit_width, unit_height, fleshColor);

    left_col = x + (2 * unit_width / 2);
    fillRectangle(left_col, top_row, 2 * unit_width, 2 * unit_height, fleshColor);

    left_col = x + (6 * unit_width / 2);
    top_row -= 4 * unit_height;
    fillRectangle(left_col, top_row, 2 * unit_width, 4 * unit_height, fleshColor);

    left_col = x + (8 * unit_width / 2);
    top_row += unit_height;
    fillRectangle(left_col, top_row, unit_width, unit_height, COLOR_BLACK);
  
}
