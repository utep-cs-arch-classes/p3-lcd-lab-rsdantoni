#ifndef _DRAW_SHAPES_H_
#define _DRAW_SHAPES_H_

typedef struct turtle_st {
  int turt_row;
  int turt_col;
  int old_turt_row;
  int old_turt_col;
} turtle;

void move_shapes();

void draw_right_turtle(int x, int y);

void move_turtle(turtle *to_draw, int x_vel, int y_vel);

void init_shapes();

#endif // _DRAW_SHAPES_H_
