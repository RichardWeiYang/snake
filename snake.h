#ifndef SNAKE_H
#define SNAKE_H
#include <stdlib.h>

enum direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct snake {
	int length;
	enum direction dir;
	char c;
	int y;
	int x;
};

extern struct snake snake;
void snake_create();
#endif  //SNAKE_H
