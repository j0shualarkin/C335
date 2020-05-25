/*
 * Utilities to draw in our game
 * Note that since the board is flipped, x and y axis are flipped when 
 * f3d_lcd_sd drawing utilities are used.  
 *
 * These functions will draw everything in cartesian coordinate system!
 * */
#include <stm32f30x.h> 
#include <f3d_lcd_sd.h> 
#include <stdio.h> 
#include "util.h" 
#include "sprite.h" 
#include "constants.h"

// Function to draw sprite that lives in sprite.h
// A possible optimization is to fill buffer with
// colors and then push them altogether, but not sure how 
// to push alpha colors in the buffer.
// x and y correspond to the top left corner when the board is flipped
void draw_sprite(sprite* s) {
  uint8_t j, i;
  uint16_t y[s->height];
  // detect if rectangle overlaps with lines from either goal post
  // if so, redraw the parts of the lines which are missing

  f3d_lcd_setAddrWindow (s->y, s->x, s->y + s->height - 1, s->x + s->width - 1,MADCTLGRAPHICS); //pick LCD area, 
  for (i = 0; i < s->width; i++) {
    for (j = 0; j < s->height; j++) {
    	y[j] = s->img[s->width * (s->height - j - 1) + i];
    }
    f3d_lcd_pushColor(y,s->height);
  }
  return;
  /*int width = s->width; 
  int height = s->height; 
  int x = s->x;
  int y = s->y;
  const uint16_t* p = s->img;
  int i, j;
  for(i = 0; i < height; i++)
    for(j = 0; j < width; j++){  
      if(*p != X) {
        f3d_lcd_drawPixel(y - i, x + j, *p);
      }
      p++;
    }*/
}

// Function to draw a bar of specfic width, height, color, and at a specific position
// (x0, y0) top left corner of the bar
// (x1, y1) bottom right corner of the bar
void draw_bar(int x0, int y0, int x1, int y1, uint16_t color) {
  if (x1 <= x0 || y1 <= y0) return;
  if (x0 < 0) x0 = 0;
  if (y0 < 0) y0 = 0;
  if (x1 > lcd_w) x1 = lcd_w;
  if (y1 > lcd_h) y1 = lcd_h;
  if (y1 <= 0 || x1 <= 0 || x0 >= lcd_w || y0 >= lcd_h) return;
  int width = y1 - y0; 
  uint8_t y;
  uint16_t x[width];
  // detect if rectangle overlaps with lines from either goal post
  // if so, redraw the parts of the lines which are missing

  for (y = 0; y < width; y++) x[y] = color; //initialize pixel row
  f3d_lcd_setAddrWindow (y0, x0, y1 - 1, x1 - 1,MADCTLGRAPHICS); //pick LCD area, 
                                                                 //no fucking idea why we need -1 there
  for (y = x0;y<x1; y++) //push pixel row to the LCD
    f3d_lcd_pushColor(x,width);
}
// Function to initialize test screen
void init_screen(void) {
  printf("about to draw!\n");
  f3d_lcd_fillScreen(SKY);
  draw_bar(0, 0, lcd_w, GROUND_h, GROUND);
  printf("done drawing\n");
}

void update_sprite(sprite* s1){
              //  Make sprite with prev values
  if(s1->prev_x + s1->width < s1->x ||
	s1->prev_x > s1->x + s1->width ||
	s1->prev_y + s1->height < s1->y ||
	s1->prev_y > s1->y + s1->height) {
	draw_bar(s1->prev_x, s1->prev_y, s1->prev_x + s1->width, s1->prev_y + s1->height, X); //erase the prev
//for now, just handle left and right
  //  //int e_x1 = s2.x < s1->x ? s2.x - 1 : s1->x + s1->width; //find the left most x
  //  //int e_x2 = s2.x < s1->x ? s1->x : s2.x + s2.width + 1; //find the right most x
  //  //draw_bar(e_x1, s2.y+1, e_x2, s2.y - s2.height, X); //erase the prev
  } else {
       if (s1->prev_x < s1->x) draw_bar(s1->prev_x, s1->prev_y, s1->x, s1->prev_y + s1->height, X); 
       if (s1->prev_x > s1->x) draw_bar(s1->x + s1->width, s1->prev_y, s1->prev_x + s1->width, s1->prev_y + s1->height, X); 
       if (s1->prev_y < s1->y) draw_bar(s1->prev_x, s1->prev_y, s1->prev_x + s1->width, s1->y, X);
       if (s1->prev_y > s1->y) draw_bar(s1->prev_x, s1->y + s1->height, s1->prev_x + s1->width, s1->prev_y + s1->height, X);
  } 
  
  draw_sprite(s1);
}

/* gfx.c ends here */
