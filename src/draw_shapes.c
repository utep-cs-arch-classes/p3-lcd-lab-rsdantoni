#include "lcdutils.h"
#include "lcddraw.h"

    int unit_height = 5, unit_width = 5;
    int center_row = screenWidth/2, center_col = screenWidth / 2;
    

void draw_turtle(){
    
    u_int shellColor = COLOR_DARK_GREEN;
    
    int left_col = center_col - (unit_width / 2);
    int top_row  = center_row - (unit_height / 2);
    
    fillRectangle(left_col, top_row, unit_width * 2, unit_height, shellColor);
}
