#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_
#include <stdbool.h>

void draw_right_turtle(int x, int y, bool erase);
void draw_donut(int x_coord, int y_coord, bool erase);
void draw_barrel(int x, int y);

void draw_horizontal_line(u_int x_start, u_int x_end, u_int y, u_int colorBGR);
void draw_lines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color);
void draw_circle(int x_coord, int y_coord, int r, u_int color);

#endif // _DRAW_SHAPES_H_
