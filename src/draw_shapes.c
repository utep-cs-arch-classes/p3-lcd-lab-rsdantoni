#include "lcdutils.h"
#include "lcddraw.h"


void draw_turtle(){
    
    u_int shellColor = COLOR_DARK_GREEN;
    int height = 5;
    int width = 10;
    int row = 20, col = screenWidth / 2;
    int left_col = col - (width / 2);
    int top_row  = row - (height / 2);

    fillRectangle(left_col, top_row, width, height, shellColor);
    
}