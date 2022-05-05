#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_
#include <stdbool.h>

typedef struct turtle_st {
  int turt_row;
  int turt_col;
  int old_turt_row;
  int old_turt_col;
} turtle;

typedef struct donut_st {
  int donut_row;
  int donut_col;
  int old_donut_row;
  int old_donut_col;
} donut;

typedef struct barrel_st {
  int barrel_row;
  int_barrel_col;
  int old_barrel_row;
  int old_barrel_col;
}


void init_shapes();
void move_shapes();

void draw_right_turtle(int x, int y, bool erase);
void move_turtle(turtle *to_draw);


void draw_donut(int x_coord, int y_coord, bool erase);
void move_donut(donut *to_draw);

void draw_barrel(int x, int y, bool erase);
void move_barrel(barrel *to_draw);

void draw_horizontal_line(u_int x_start, u_int x_end, u_int y, u_int colorBGR);
void draw_lines(u_int x_coord, u_int y_coord, u_int x_point, u_int y_point, u_int color);
void draw_circle(int x_coord, int y_coord, int r, u_int color);

#endif // _DRAW_SHAPES_H_
