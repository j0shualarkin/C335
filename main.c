#include <stm32f30x.h> // Pull in include files for F30x standard drivers 
#include <f3d_nunchuk.h>
#include <f3d_i2c.h>
#include <f3d_lcd_sd.h>
#include <stdio.h>
#include "gfx.h"
#include "sprite.h"
#include "constants.h"

void init_board(void) {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);

  f3d_uart_init();
  printf("uart init\n");
  delay(100);

  f3d_lcd_init();
  printf("lcd init\n");
  delay(100);

  f3d_i2c1_init();
  printf("i2c1 init\n");
  delay(100);

  f3d_i2c2_init();
  printf("i2c2 init\n");
  delay(100);

  printf("done with second delay\n");
  f3d_nunchuk_init();
  printf("nun init\n");
  delay(100);


  //f3d_rtc_init();
  //f3d_systick_init(1);
  //f3d_timer2_init();
  //f3d_dac_init();
  //f3d_delay_init();

  printf("Reset\n");
}

int stick_dir(nunchuk_t* vals) {
  if(vals->jx < JMID - JTHOLD){
    return -1; }
  if(vals->jx > JMID + JTHOLD){
    return 1; }
  return 0;
}

void one_nun(){
  nunchuk_t n1;
  sprite p1 = {40, 0, GROUND_h, GROUND_h, sprite_wd, sprite_ht, 0,0,shoe};
  sprite p2 = {70, 0, GROUND_h, GROUND_h, sprite_wd, sprite_ht, 0,0,shoe2};
  sprite b = {70, 0, GROUND_h, GROUND_h, ball_wd, ball_ht, 0,0,ball};
  sprite gp1 = {0, 0, GROUND_h, 0, goal_wd, goal_ht, 0,0,goal};
  sprite gp2 = {lcd_w - goal_wd, 0, GROUND_h + goal_ht - 1, 0, goal_wd, goal_ht, 0,0,goal};
  draw_sprite(&p1); draw_sprite(&p2); draw_sprite(&b); draw_sprite(&gp1); draw_sprite(&gp2);
  while(1) {
    f3d_nunchuk_read(&n1);
    move_x(&p1, stick_dir(&n1));
    update_sprite(&p1);
    delay(1);
    //if(p1.x != p1.prev_x) update_sprites(&p1, BLACK, sprite_wd, sprite_ht);
    
  }
}

void handle_collisions(sprite* s1, sprite* s2) {
  if(intersect(s1, s2)) {
    sprite* min_x = s1->x < s2->x? s1 : s2;	
    sprite* max_x = s1->x < s2->x? s2 : s1;
    move_x(min_x, -1);
    move_x(max_x, 1);
  }
}

void two_nun(){

  nunchuk_t n1;
  nunchuk_t n2;
   sprite p1 = {40, 40, GROUND_h, GROUND_h, sprite_wd, sprite_ht, 0,0,shoe};
  sprite p2 = {70, 70, GROUND_h, GROUND_h, sprite_wd, sprite_ht, 0,0,shoe2};
  sprite b = {70, 70, GROUND_h, GROUND_h, ball_wd, ball_ht, 0,0,ball};
  sprite gp1 = {0, 0, GROUND_h, GROUND_h, goal_wd, goal_ht, 0,0,goal};
  sprite gp2 = {lcd_w - goal_wd, lcd_w - goal_wd, GROUND_h, GROUND_h, goal_wd, goal_ht, 0,0,goal};
  draw_sprite(&p1); draw_sprite(&p2); draw_sprite(&b); draw_sprite(&gp1); draw_sprite(&gp2);
  while(1) {
    f3d_nunchuk_read(&n1);
    f3d_nunchuk_read2(&n2);
    move_x(&p1, stick_dir(&n1));
    move_x(&p2, stick_dir(&n2));
    handle_collisions(&p1, &p2);
    handle_collisions(&p1, &p2);
    update_sprite(&b);
    update_sprite(&p1);
    update_sprite(&p2);
    update_sprite(&gp1);
    update_sprite(&gp2);
    delay(1);
    //if(p1.x != p1.prev_x) update_sprites(&p1, BLACK, sprite_wd, sprite_ht);
  }

}

void test_main() {
  sprite test_struct = {0, 0, 0, 0, test_wd, test_ht, 1,1, tst};
  draw_sprite(&test_struct);
  while(1) {
    test_struct.x += test_struct.x_dir;
    test_struct.y += test_struct.y_dir;
    
    if(test_struct.x <= 0) {
      test_struct.x = 0; test_struct.x_dir = -test_struct.x_dir;
    } if(test_struct.x >= lcd_w) {
      test_struct.x = lcd_w; test_struct.x_dir = -test_struct.x_dir;
    } if(test_struct.y <= 0) {
      test_struct.y = 0; test_struct.y_dir = -test_struct.y_dir;
    } if(test_struct.y >= lcd_h) {
      test_struct.y = lcd_h; test_struct.y_dir = -test_struct.y_dir;
    }
    update_sprite(&test_struct);
    test_struct.prev_x = test_struct.x;
    test_struct.prev_y = test_struct.y;
  }
}


// currently: 

int main(void) {
  init_board();
  init_screen();
  //one_nun();
  two_nun();
  //test_main();
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t * file, uint32_t line) {
  /* Infinite loop */
  /* Use GDB to find out why we're here */
  while (1);
}
#endif

/* main.c ends here */
