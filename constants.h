/*
 * Contants used in our game
 */
#include <stm32f30x.h>
#include <f3d_lcd_sd.h>

#define lcd_h ST7735_width //LCD length
#define lcd_w ST7735_height //LCD height
#define JMID 127
#define JTHOLD 32
#define GROUND GREEN 
#define GROUND_h 26 
#define SKY 0xFF00//0xFD16
#define GOAL_H (((lcd_h / 2)-(lcd_h / 6))) //Maybe delete?
#define GOAL_W 20
#define X SKY // NULL value for colors
#define G 0x3333
#define B BLACK
#define W WHITE 
#define R RED
#define L BLUE   //first player color
#define O 0x071F //second player color
#define Y YELLOW
