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

struct food {
	int y;
	int x;
	char c;
};

extern struct snake snake;
extern struct food food;
void snake_create();
void snake_move();
int check_snake();
void create_food();
int check_food();
#endif  //SNAKE_H

