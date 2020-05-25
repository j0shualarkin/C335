#pragma once //includes this in compilation once. Ask someone about this
#include "constants.h"

#define sprite_wd 17
#define sprite_ht 10

#define ball_wd 9
#define ball_ht 9

#define test_wd 11
#define test_ht 9

#define goal_wd 16
#define goal_ht 34



// structure to represent a sprite
// sprite includes everything that could affect collision
typedef struct sprite_data{
  short x; //left most
  short prev_x;
  short y; //top most
  short prev_y;
  short width;
  short height;
  short x_dir;
  short y_dir;
  const uint16_t* img; //pointer to sprite image
} sprite;

void move_x(sprite*, int);

extern const uint16_t shoe[];

extern const uint16_t shoe2[];

extern const uint16_t ball[];

extern const uint16_t tst[];

extern const uint16_t goal[];

