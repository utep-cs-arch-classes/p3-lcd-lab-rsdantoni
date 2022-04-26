#include "lcdutils.h"
#include "lcddraw.h"

    int unit_height = 5, unit_width = 5;
    int center_row = screenWidth/2, center_col = screenWidth / 2;
    int left_col = col - (width / 2);
    int top_row  = row - (height / 2);

void draw_turtle(){
    
    u_int shellColor = COLOR_DARK_GREEN;
    

    fillRectangle(left_col, top_row, width, height, shellColor);
    fillRectangle(    
}
