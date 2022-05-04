#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_
#include <stdbool.h>

typedef struct turtle_st {
  int turt_row;
  int turt_col;
  int old_turt_row;
  int old_turt_col;
} turtle;

void move_shapes();

void draw_right_turtle(int x, int y, bool erase);

void move_turtle(turtle *to_draw);

void init_shapes();

void drawDonut(int x_coord, int y_coord);

void drawHorizontalLine(u_int x_start, u_int x_end, u_int y, u_int colorBGR);

void drawLines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color);

void draw_circle(int x_coord, int y_coord, int r, u_int color);

#endif // _DRAW_SHAPES_H_
