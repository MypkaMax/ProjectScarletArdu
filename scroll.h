#ifndef SCROLL_H
#define SCROLL_H
void scroll() {
  camerax = playerx;
	if (cameray<2) {
		cameray = 2;
	}
	if (cameray>5) {
		cameray = 5;
	}
	if (camerax<64) {
		camerax = 64;
	}
	if (camerax>153) {
		camerax = 153;
	}
	if (playery<=32) {
		cameray=cameray-2;
	}
	if (playery>=32) {
		cameray=cameray+2;
	}
}
#endif