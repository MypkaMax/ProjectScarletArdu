#ifndef LEVEL_H
#define LEVEL_H
//-1 - box solid (max can fall through the pit, but the box cant, allowing max to cross the pit)
//0 - air
//1 - platform 1

void levels() {
for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 24; x++) {
      if (levellayout[y][x] == 1) {
		//arduboy.fillRect((x * 16) - (camerax-64), ((y * 16) + 8) - cameray, 16, 8, BLACK);
        arduboy.drawBitmap((x * 16) - (camerax-64), ((y * 16) + 8) - cameray,girder,8,8,WHITE);
		arduboy.drawBitmap(((x * 16) + 8) - (camerax-64), ((y * 16) + 8) - cameray,girder,8,8,WHITE);
      }
	  }
  }
}
void tilecollision() {
	if (levellayout[playery / 16][(playerx-7) / 16] == 1 || levellayout[playery / 16][(playerx-8) / 16] == 2)
	{
		playery = playery - 1;
		ground = 1;
	}
	else {
	  ground = 0;
	}
	if (ground<=0) {
	  playery = playery + 2;
	}
}
#endif