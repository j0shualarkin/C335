/**
 * Utlities for player 
 */
#include "sprite.h"
#include "constants.h"

void move_x(sprite* s, int d) {
 s->prev_x = s->x;
 s->prev_y = s->y;
 s->x += d;
 s->x = s->x + s->width >= lcd_w ? lcd_w - s->width - 1 : 
        (s->x < 0 ? 0 : s->x);
}

int intersect(sprite* s1, sprite* s2) {
  if(s1->x + s1->width < s2->x)  return 0; //s1 is strictly on the left of s2
  if(s1->x > s2->x + s2->width) return 0;//s1 is strictly on the right of s2
  if(s1->y < s2->y - s2->height) return 0;//s1 is strictly below s2
  if(s1->y - s1->height > s2->y) return 0;//s1 is strictly above s2
  else                          return 1; //it was neither of the above
}


const uint16_t shoe[] = 
  { 
   X,X,X,X,X,L,L,X,X,X,X,X,X,X,X,X,X,
   X,L,L,L,L,L,W,X,X,X,X,X,X,X,X,X,X,
   X,L,L,L,L,L,W,X,X,X,X,X,X,X,X,X,X,
   X,W,W,W,L,L,L,W,X,X,X,X,X,X,X,X,X,
   L,W,W,W,L,L,L,L,W,X,X,X,X,X,X,X,X,
   L,W,W,W,L,L,L,L,L,W,W,X,X,X,X,X,X,
   L,L,L,L,L,L,L,L,L,L,W,L,L,W,W,W,X,
   L,L,L,L,L,L,L,L,L,L,L,L,L,W,W,W,W,
   L,L,L,L,L,L,L,L,L,L,L,L,L,L,W,W,W,
   B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
};


const uint16_t shoe2[] = 
  { 
   X,X,X,X,X,X,X,X,X,X,O,O,X,X,X,X,X,
   X,X,X,X,X,X,X,X,X,X,W,O,O,O,O,O,X,
   X,X,X,X,X,X,X,X,X,X,W,O,O,O,O,O,X,
   X,X,X,X,X,X,X,X,X,W,O,O,O,W,W,W,X,
   X,X,X,X,X,X,X,X,W,O,O,O,O,W,W,W,O,
   X,X,X,X,X,X,W,W,O,O,O,O,O,W,W,W,O,
   X,W,W,W,O,O,W,O,O,O,O,O,O,O,O,O,O,
   W,W,W,W,O,O,O,O,O,O,O,O,O,O,O,O,O,
   W,W,W,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
   B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B, 
};

const uint16_t ball[] = {

  X,X,X,B,B,B,X,X,X,
  X,X,W,W,W,W,W,X,X,
  X,W,W,B,B,B,W,W,X,
  B,W,B,W,W,W,B,W,B,
  B,W,B,W,B,W,B,W,B,
  B,W,B,W,W,W,B,W,B,
  X,W,W,B,B,B,W,W,X,
  X,X,W,W,W,W,W,X,X,
  X,X,X,B,B,B,X,X,X,
};

const uint16_t tst[] = {

  B,B,B,B,B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,B,B,B,B,
};

const uint16_t goal[] = {
  
  W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,
  W,X,W,X,W,X,W,X,W,X,W,X,W,X,W,W,
  W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,
                                                   
};

