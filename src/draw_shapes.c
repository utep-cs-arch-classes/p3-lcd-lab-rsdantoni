#include "lcdutils.h"
#include "lcddraw.h"
#include "draw_shapes.h"

int unit_height = 5, unit_width = 5;
turtle turt;

void draw_right_turtle(int x, int y){
   
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

void init_shapes(){
    turt.turt_row = screenHeight / 2;
    turt.turt_col = screenWidth / 2;
    turt.old_turt_row = screenHeight / 2;
    turt.old_turt_col = screenHeight / 2;
}

void move_turtle(turtle *to_draw, int x_vel, int y_vel){
    
    if(x_vel > 0){
        draw_right_turtle(to_draw->turt_row, to_draw->turt_col);
    }

    to_draw-> old_turt_row = to_draw->turt_row;
    to_draw->old_turt_col = to_draw->turt_col;

    to_draw->turt_row += y_vel;
    to_draw->turt_col += x_vel;
    
    if( (to_draw->turt_col + 4) >= screenWidth ){
        to_draw->turt_col = 4;
    }

    if( (to_draw->turt_col - 4) <= 0 ){
        to_draw->turt_col = screenWidth - 4;
    }
}
