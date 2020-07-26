#ifndef BOX_H
#define BOX_H
#include <Arduboy2.h>
Arduboy2 arduboy;
#include "gfx.h"
int camerax = 0;
int cameray = 0;
int playerx = 0;
int playery = 0;
int playertiley = 0;

int box0_x = 48;
int box0_y = 16;
int box0_tiley = 0;
int box0_ground = 0;
int box1_x = 132;
int box1_y = 16;
int box1_tiley = 0;
int box1_ground = 0;
int box2_x = 48;
int box2_y = 48;
int box2_tiley = 0;
int box2_ground = 0;
int box3_x = 123;
int box3_y = 48;
int box3_tiley = 0;
int box3_ground = 0;

int levellayout[10][24] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
{0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0}
};

void boxes() {
  if (levellayout[box0_y / 16][(box0_x-7) / 16] == 1 || levellayout[box0_y / 16][(box0_x-8) / 16] == 2 || levellayout[box0_y / 16][(box0_x-8) / 16] == -1 )
	{
		box0_y = box0_y - 1;
		box0_ground = 1;
	}
	else
	{
	  box0_ground = 0;
	}
	
	if (levellayout[box1_y / 16][(box1_x-7) / 16] == 1 || levellayout[box1_y / 16][(box1_x-8) / 16] == 2 || levellayout[box1_y / 16][(box1_x-8) / 16] == -1)
	{
		box1_y = box1_y - 1;
		box1_ground = 1;
	}
	else
	{
	  box1_ground = 0;
	}
	
	if (levellayout[box2_y / 16][(box2_x-7) / 16] == 1 || levellayout[box2_y / 16][(box2_x-8) / 16] == 2 || levellayout[box2_y / 16][(box2_x-8) / 16] == -1)
	{
		box2_y = box2_y - 1;
		box2_ground = 1;
	}
	else
	{
	  box2_ground = 0;
	}
	
	if (levellayout[box3_y / 16][(box3_x-7) / 16] == 1 || levellayout[box3_y / 16][(box3_x-8) / 16] == 2 || levellayout[box3_y / 16][(box3_x-7) / 16] == -1)
	{
		box3_y = box3_y - 1;
		box3_ground = 1;
	}
	else
	{
	  box3_ground = 0;
	}
	
	if (box0_ground<=0) {
	  box0_y = box0_y + 2;
	}
	if (box1_ground<=0) {
	  box1_y = box1_y + 2;
	}
	if (box2_ground<=0) {
	  box2_y = box2_y + 2;
	}
	if (box3_ground<=0) {
	  box3_y = box3_y + 2;
	}
	box0_y = box0_y + 1;
	box1_y = box1_y + 1;
	box2_y = box2_y + 1;
	box3_y = box3_y + 1;
	//Wrapping:
	if (box0_y>84) {
	  box0_y = -24;
	}
	if (box1_y>84) {
	  box1_y = -24;
	}
	if (box2_y>84) {
	  box2_y = -24;
	}
	if (box3_y>84) {
	  box3_y = -24;
	}
	if (playery>84) {
	  playery = -24;
	}
	//Tile counting:
	playertiley=(playery-6)/16;
	box0_tiley=(box0_y-6)/16;
	box1_tiley=(box1_y-6)/16;
	box2_tiley=(box2_y-6)/16;
	box3_tiley=(box3_y-6)/16;
	//Pushing:
	////Box 0:
	if (playerx>box0_x-10 && playerx<box0_x && box0_ground>=1 && box0_tiley==playertiley) {
	  box0_x = box0_x + 1;
	}
	if (playerx<box0_x+10 && playerx>box0_x && box0_ground>=1 && box0_tiley==playertiley) {
	  box0_x = box0_x - 1;
	}
	////Box 1:
	if (playerx>box1_x-10 && playerx<box1_x && box1_ground>=1 && box1_tiley==playertiley) {
	  box1_x = box1_x + 1;
	}
	if (playerx<box1_x+10 && playerx>box1_x && box1_ground>=1 && box1_tiley==playertiley) {
	  box1_x = box1_x - 1;
	}
	////Box 2:
	if (playerx>box2_x-10 && playerx<box2_x && box2_ground>=1 && box2_tiley==playertiley) {
	  box2_x = box2_x + 1;
	}
	if (playerx<box2_x+10 && playerx>box2_x && box2_ground>=1 && box2_tiley==playertiley) {
	  box2_x = box2_x - 1;
	}
	////Box 3:
	if (playerx>box3_x-10 && playerx<box3_x && box3_ground>=1 && box3_tiley==playertiley) {
	  box3_x = box3_x + 1;
	}
	if (playerx<box3_x+10 && playerx>box3_x && box3_ground>=1 && box3_tiley==playertiley) {
	  box3_x = box3_x - 1;
	}
}
void boxgfx() {
  arduboy.fillRect((box0_x-8)-(camerax-64),(box0_y-8)-cameray,16,16,BLACK);
  arduboy.drawBitmap((box0_x-8)-(camerax-64),(box0_y-8)-cameray,box,16,16,WHITE);
  arduboy.fillRect((box1_x-8)-(camerax-64),(box1_y-8)-cameray,16,16,BLACK);
  arduboy.drawBitmap((box1_x-8)-(camerax-64),(box1_y-8)-cameray,box,16,16,WHITE);
  arduboy.fillRect((box2_x-8)-(camerax-64),(box2_y-8)-cameray,16,16,BLACK);
  arduboy.drawBitmap((box2_x-8)-(camerax-64),(box2_y-8)-cameray,box,16,16,WHITE);
  arduboy.fillRect((box3_x-8)-(camerax-64),(box3_y-8)-cameray,16,16,BLACK);
  arduboy.drawBitmap((box3_x-8)-(camerax-64),(box3_y-8)-cameray,box,16,16,WHITE);
}
#endif