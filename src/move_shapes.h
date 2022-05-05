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

void init_shapes();
void move_shapes();

void move_turtle(turtle *to_draw);
void move_donut(donut *to_draw);

