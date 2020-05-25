
 //  draw_sprite(shape, 5, 11, 50, 50);
  //  draw_sprite(player1, 12, 27, 50, 50);
  //    draw_sprite(rb_rect, 9, 11, 50, 50);
  //  draw_sprite(bwy_sqr, 11, 11, 50, 50);
  // draw_sprite(rect2, sprite_wd, sprite_ht, 50, 50);

uint16_t rect1[] = {

  B,B,B,B,B,B,B,
  B,B,B,B,B,B,B,
  B,B,B,W,B,B,B,
  B,B,W,B,W,B,B,
  B,W,B,W,B,W,B,
  W,B,W,W,W,B,W,
  B,W,B,W,B,W,B,
  B,B,W,B,W,B,B,
  B,B,B,W,B,B,B,
  B,B,B,B,B,B,B,
  B,B,B,B,B,B,B


};


/*
// 7x11
uint16_t rect2[] = {

  B,W,B,B,B,W,B,
  W,W,B,B,B,W,W,
  B,B,B,W,B,B,B,
  B,B,W,B,W,B,B,
  B,W,B,W,B,W,B,
  W,B,W,W,W,B,W,
  B,W,B,W,B,W,B,
  B,B,W,B,W,B,B,
  B,B,B,W,B,B,B,
  W,W,B,B,B,W,W,
  B,W,B,B,B,W,B

};
*/

/*
// 7x11
uint16_t rect2[] = {

  B,W,B,B,B,W,B,
  W,W,B,B,B,W,W,
  B,B,B,W,B,B,B,
  B,B,W,B,W,B,B,
  B,W,B,W,B,W,B,
  W,B,W,W,W,B,W,
  B,W,B,W,B,W,B,
  B,B,W,B,W,B,B,
  B,B,B,W,B,B,B,
  R,R,B,B,B,R,R,
  B,R,B,B,B,R,B

};
*/

/*
// 7x11
uint16_t rect2[] = {

  R,B,W,B,B,B,W,R,R,
  R,W,W,B,B,B,W,R,R,
  R,  B,B,B,W,B,B,R,R,
  R,  B,B,W,B,W,B,R,R,
  R,  B,W,B,W,B,W,R,R,
  R,  W,B,W,W,W,B,R,R,
  R,  B,W,B,W,B,W,R,R,
  R,  B,B,W,B,W,B,R,R,
  R,  B,B,B,W,B,B,R,R,
  R,  W,W,B,B,B,W,R,R,
  R,  B,W,B,B,B,W,R,R

};
*/



uint16_t shoe[] = 
  { 
     3,3,3,3,3,3,B,B,B,3,3,3,3,3,3,3,3,3,3,3, // ···█▌·······
   3,3,B,B,3,3,B,R,R,B,3,3,3,3,3,3,3,3,3,3, // ·█·██·······
   3,3,B,R,R,R,R,R,W,B,3,3,3,3,3,3,3,3,3,3, // ·███▐·······
      3,3,B,R,R,R,R,R,W,B,B,3,3,3,3,3,3,3,3,3, // ·███▐▌······
   3,3,B,W,W,W,R,R,R,W,B,B,3,3,3,3,3,3,3,3, // ·▌·█▌█······
   3,B,R,W,W,W,R,R,R,R,W,B,B,3,3,3,3,3,3,3, // ▐▌·██▐▌·····
   3,B,R,W,W,W,R,R,R,R,R,W,W,B,B,B,B,B,3,3, // ▐▌·██▌▐▌█···
   3,B,R,R,R,R,R,R,R,R,R,R,W,R,R,W,W,W,B,3, // ▐█████▐▌·█··
   3,B,R,R,R,R,R,R,R,R,R,R,R,R,R,W,W,B,W,B, // ▐██████▌▐▐··
   3,B,R,R,R,R,R,R,R,R,R,R,R,R,R,R,W,W,W,B, // ▐███████·▐··
   3,B,W,W,W,R,W,R,R,W,W,R,W,W,W,W,B,B,B,3, // ▐·▐▐▌▐··▐▌··
   3,B,B,B,B,B,B,B,B,B,B,B,W,W,W,B,3,3,3,3 // ▐█████·▐····
};


/*
uint16_t player1[324] = 
  { 
   0,0,0,0,0,0,B,B,B,0,0,0,0,0,0,0,0,0,0,0, // ···█▌·······
   0,0,B,B,0,0,B,G,G,B,0,0,0,0,0,0,0,0,0,0, // ·█·██·······
   0,0,B,G,G,G,G,G,W,B,0,0,0,0,0,0,0,0,0,0, // ·███▐·······
   0,0,B,G,G,G,G,G,W,B,B,0,0,0,0,0,0,0,0,0, // ·███▐▌······
   0,0,B,W,W,W,G,G,G,W,B,B,0,0,0,0,0,0,0,0, // ·▌·█▌█······
   0,B,G,W,W,W,G,G,G,G,W,B,B,0,0,0,0,0,0,0, // ▐▌·██▐▌·····
   0,B,G,W,W,W,G,G,G,G,G,W,W,B,B,B,B,B,0,0, // ▐▌·██▌▐▌█···
   0,B,G,G,G,G,G,G,G,G,G,G,W,G,G,W,W,W,B,0, // ▐█████▐▌·█··
   0,B,G,G,G,G,G,G,G,G,G,G,G,G,G,W,W,B,W,B, // ▐██████▌▐▐··
   0,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,W,W,W,B, // ▐███████·▐··
   0,B,W,W,W,G,W,G,G,W,W,G,W,W,W,W,B,B,B,0, // ▐·▐▐▌▐··▐▌··
   0,B,B,B,B,B,B,B,B,B,B,B,W,W,W,B,0,0,0,0, // ▐█████·▐····
};
*/



// rb_rect = 11x9
uint16_t rb_rect[] = {

  R,R,R,R,R,R,R,R,R,R,R,
  R,R,R,R,R,R,R,R,R,R,R,
  R,R,R,B,B,B,B,B,R,R,R,
  R,R,R,B,R,R,R,B,R,R,R,
  R,R,R,B,R,B,R,B,R,R,R,
  R,R,R,B,R,R,R,B,R,R,R,
  R,R,R,B,B,B,B,B,R,R,R,
  R,R,R,R,R,R,R,R,R,R,R,
  R,R,R,R,R,R,R,R,R,R,R,

};


// bw_sqr = 11x11
uint16_t bw_sqr[] = {

  B,B,B,B,B,B,B,B,B,B,B,
  B,W,W,W,W,W,W,W,W,W,B,
  B,W,B,B,B,B,B,B,B,W,B,
  B,W,B,W,W,W,W,W,B,W,B,
  B,W,B,W,B,B,B,W,B,W,B,
  B,W,B,W,B,W,B,W,B,W,B,
  B,W,B,W,B,B,B,W,B,W,B,
  B,W,B,W,W,W,W,W,B,W,B,
  B,W,B,B,B,B,B,B,B,W,B,
  B,W,W,W,W,W,W,W,W,W,B,
  B,B,B,B,B,B,B,B,B,B,B,
};


// by_sqr = 11x11
uint16_t by_sqr[] = {

  B,B,B,B,B,B,B,B,B,B,B,
  B,Y,Y,Y,Y,Y,Y,Y,Y,Y,B,
  B,Y,B,B,B,B,B,B,B,Y,B,
  B,Y,B,Y,Y,Y,Y,Y,B,Y,B,
  B,Y,B,Y,B,B,B,Y,B,Y,B,
  B,Y,B,Y,B,Y,B,Y,B,Y,B,
  B,Y,B,Y,B,B,B,Y,B,Y,B,
  B,Y,B,Y,Y,Y,Y,Y,B,Y,B,
  B,Y,B,B,B,B,B,B,B,Y,B,
  B,Y,Y,Y,Y,Y,Y,Y,Y,Y,B,
  B,B,B,B,B,B,B,B,B,B,B,
};

// bwy_sqr = 11x11
uint16_t bwy_sqr[] = {

  B,B,B,B,B,B,B,B,B,B,B,
  B,Y,Y,Y,Y,Y,Y,Y,Y,Y,B,
  B,Y,B,B,B,B,B,B,B,Y,B,
  B,Y,B,W,W,W,W,W,B,Y,B,
  B,Y,B,W,B,B,B,W,B,Y,B,
  B,Y,B,W,B,Y,B,W,B,Y,B,
  B,Y,B,W,B,B,B,W,B,Y,B,
  B,Y,B,W,W,W,W,W,B,Y,B,
  B,Y,B,B,B,B,B,B,B,Y,B,
  B,Y,Y,Y,Y,Y,Y,Y,Y,Y,B,
  B,B,B,B,B,B,B,B,B,B,B,
};




uint16_t player1[324] = 
  { 
   0,0,0,0,0,0,B,B,B,0,0,0,0,0,0,0,0,0,0,0, // ···█▌·······
   0,0,B,B,0,0,B,G,G,B,0,0,0,0,0,0,0,0,0,0, // ·█·██·······
   0,0,B,G,G,G,G,G,W,B,0,0,0,0,0,0,0,0,0,0, // ·███▐·······
   0,0,B,G,G,G,G,G,W,B,B,0,0,0,0,0,0,0,0,0, // ·███▐▌······
   0,0,B,W,W,W,G,G,G,W,B,B,0,0,0,0,0,0,0,0, // ·▌·█▌█······
   0,B,G,W,W,W,G,G,G,G,W,B,B,0,0,0,0,0,0,0, // ▐▌·██▐▌·····
   0,B,G,W,W,W,G,G,G,G,G,W,W,B,B,B,B,B,0,0, // ▐▌·██▌▐▌█···
   0,B,G,G,G,G,G,G,G,G,G,G,W,G,G,W,W,W,B,0, // ▐█████▐▌·█··
   0,B,G,G,G,G,G,G,G,G,G,G,G,G,G,W,W,B,W,B, // ▐██████▌▐▐··
   0,B,G,G,G,G,G,G,G,G,G,G,G,G,G,G,W,W,W,B, // ▐███████·▐··
   0,B,W,W,W,G,W,G,G,W,W,G,W,W,W,W,B,B,B,0, // ▐·▐▐▌▐··▐▌··
   0,B,B,B,B,B,B,B,B,B,B,B,W,W,W,B,0,0,0,0 // ▐█████·▐····
};


uint16_t player1_att2[324] = 
  { 
   3,3,3,3,3,3,B,B,B,3,3,3,3,3,3,3,3,3,3,3, // ···█▌·······
   3,3,B,B,3,3,B,R,R,B,3,3,3,3,3,3,3,3,3,3, // ·█·██·······
   3,3,B,R,R,R,R,R,W,B,3,3,3,3,3,3,3,3,3,3, // ·███▐·······
   3,3,B,R,R,R,R,R,W,B,B,3,3,3,3,3,3,3,3,3, // ·███▐▌······
   3,3,B,W,W,W,R,R,R,W,B,B,3,3,3,3,3,3,3,3, // ·▌·█▌█······
   3,B,R,W,W,W,R,R,R,R,W,B,B,3,3,3,3,3,3,3, // ▐▌·██▐▌·····
   3,B,R,W,W,W,R,R,R,R,R,W,W,B,B,B,B,B,3,3, // ▐▌·██▌▐▌█···
   3,B,R,R,R,R,R,R,R,R,R,R,W,R,R,W,W,W,B,3, // ▐█████▐▌·█··
   3,B,R,R,R,R,R,R,R,R,R,R,R,R,R,W,W,B,W,B, // ▐██████▌▐▐··
   3,B,R,R,R,R,R,R,R,R,R,R,R,R,R,R,W,W,W,B, // ▐███████·▐··
   3,B,W,W,W,R,W,R,R,W,W,R,W,W,W,W,B,B,B,3, // ▐·▐▐▌▐··▐▌··
   3,B,B,B,B,B,B,B,B,B,B,B,W,W,W,B,3,3,3,3 // ▐█████·▐····
};




// shape is 11x5 = 55
uint16_t shape[] = {
  
  B,B,B,GB,B,R,B,GB,B,B,B,
  B,B,GB,B,R,B,R,B,GB,B,B,
  B,GB,B,R,B,B,B,R,B,GB,B,
  B,B,GB,B,R,B,R,B,GB,B,B,
  B,B,B,GB,B,R,B,GB,B,B,B,
  
};



uint16_t test_plyr[324] = 
  { 
   3,3,3,3,3,3,R,R,R,3,3,3,3,3,3,3,3,3,3,3, 
   3,3,R,R,3,3,R,GB,GB,R,3,3,3,3,3,3,3,3,3,3,
   3,3,R,GB,GB,GB,GB,GB,W,R,3,3,3,3,3,3,3,3,3,3,
   3,3,R,GB,GB,GB,GB,GB,W,R,R,3,3,3,3,3,3,3,3,3,
   3,3,R,W,W,W,GB,GB,GB,W,R,R,3,3,3,3,3,3,3,3,
   3,R,GB,W,W,W,GB,GB,GB,GB,W,R,R,3,3,3,3,3,3,3,
   3,R,GB,W,W,W,GB,GB,GB,GB,GB,W,W,R,R,R,R,R,3,3,
   3,R,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,W,GB,GB,W,W,W,R,3,
   3,R,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,W,W,R,W,R,
   3,R,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,GB,W,W,W,R,
   3,R,W,W,W,GB,W,GB,GB,W,W,GB,W,W,W,W,R,R,R,3,
   3,R,R,R,R,R,R,R,R,R,R,R,W,W,W,R,3,3,3,3 };
