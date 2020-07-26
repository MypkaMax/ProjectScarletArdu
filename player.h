#ifndef PLAYER_H
#define PLAYER_H
#include "scroll.h"
int direction = 0;
int walkframe = -1;
int idleframe = 0;
int ground = 0;
int pole = 0;
void player() {
  //arduboy.fillCircle(playerx, playery, 32, WHITE);
    if(arduboy.pressed(LEFT_BUTTON))
    {
      playerx = playerx - 1;
      direction = 1;
      walkframe = walkframe+1;
      idleframe = 0;
    }
    if(arduboy.pressed(RIGHT_BUTTON))
    {
      playerx = playerx + 1;
      direction = 0;
      walkframe = walkframe+1;
      idleframe = 0;
    }
    if(!arduboy.pressed(LEFT_BUTTON) || !arduboy.pressed(RIGHT_BUTTON))
    {
      walkframe = -1;
    }
    
    if((arduboy.pressed(UP_BUTTON)) && pole>0)
    {
      playery = playery - 1;
    }
    if (pole<=0){
    playery = playery + 1;
    }
if (playerx<8) {
    playerx = 8;
  }
if (playerx>208) {
    playerx = 208;
  }
if (walkframe>15) {
    walkframe = 0;
  }
if (walkframe<0) {
    idleframe = idleframe + 1;
  }
  arduboy.print(direction);
}
void playergfx() {
  if(direction = 0 && ground>=1)
  {
    Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunright_plus_mask,(walkframe/4));
  }
  if(direction = 1 && ground>=1)
  {
    Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunleft_plus_mask,(walkframe/4));
  }
  if(direction = 0 && ground<=0)
  {
    Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunright_plus_mask,0);
  }
  if(direction = 1 && ground<=0)
  {
    Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunleft_plus_mask,0);
  }
  if(arduboy.pressed(LEFT_BUTTON) && ground>=1)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunleft_plus_mask,(walkframe/4));
    }
    if(arduboy.pressed(RIGHT_BUTTON) && ground>=1)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunright_plus_mask,(walkframe/4));
    }
    if (direction = 0 && walkframe<0 && idleframe <40 && ground>=1) 
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxstandright_plus_mask,(walkframe/4));
    }
    if (direction = 1 && walkframe<0 && idleframe <40 && ground>=1) 
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxstandleft_plus_mask,(walkframe/4));
    }
    if (direction = 0 && ground<=0) 
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunright_plus_mask,0);
    }
    if (direction = 1 && ground<=0) {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunleft_plus_mask,0);
    }
    if (direction = 0 && idleframe>=40 && ground>=1) 
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxidle_plus_mask,0);
    }
    if (direction = 1 && idleframe>=40 && ground>=1) 
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxidle_plus_mask,0);
    }
if (direction == 0) {
  if (walkframe>=0 && idleframe<40 && ground>=1)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunright_plus_mask,(walkframe/4));
    }
  if (walkframe<0 && idleframe<40 && ground>=1)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxstandright_plus_mask,0);
    }
  else if (idleframe>=40 && ground>=1)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxidle_plus_mask,0);
    }
  else if (ground<=0)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunright_plus_mask,0);
    }
  }
if (direction == 1) {
  if (walkframe>=0 && idleframe<40 && ground>=1) 
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunleft_plus_mask,(walkframe/4));
    }
    if (walkframe<0 && idleframe<40 && ground>=1)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxstandleft_plus_mask,0);
    }
  else if (idleframe>=40 && ground>=1)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxidle_plus_mask,0);
    }
  else if (ground<=0)
    {
      Sprites::drawPlusMask((playerx-8)-(camerax-64),(playery-8)-cameray,maxrunleft_plus_mask,0);
    }
  }

}
#endif