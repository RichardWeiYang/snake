#include "snake.h"

struct snake snake;

void snake_create()
{

	snake.dir = LEFT;
	snake.length = 1;
	snake.c = '@';

	snake.y = 10;
	snake.x = 15;
}
