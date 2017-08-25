#ifndef SNAKE_H
#define SNAKE_H
#include <stdlib.h>

enum direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

struct snake_body {
	int y;
	int x;
	struct snake_body *front;
};

struct snake {
	int length;
	enum direction dir;
	char c;
	struct snake_body *tail;
};

struct food {
	int y;
	int x;
	char c;
};

extern struct snake snake;
extern struct food food;
void snake_create();
void snake_move_tail_to_head();
int check_snake();
void create_food();
int check_food();
#endif  //SNAKE_H

