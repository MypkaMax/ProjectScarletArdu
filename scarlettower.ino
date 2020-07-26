#include <Arduboy2.h>
#include "gfx.h"
#include "player.h"
#include "level.h"
#include "scroll.h"
#include "box.h"
#include "waterclearvisual.h"
//#include "screenbrightness.h"

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(60);
}

void loop() {
  arduboy.clear();
  delay(15);
  //I added the delay command above, so that the game is not too fast for the player, which may ruin the experience since the enemies would be too fast.
  scroll();
  player();
  playergfx();
  levels();
  tilecollision();
  boxes();
  boxgfx();
  //setContrast();
  arduboy.display();
}