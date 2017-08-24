#include "snake.h"
#include "ncurse.h"

struct snake snake;

void snake_create()
{

	snake.dir = LEFT;
	snake.length = 1;
	snake.c = '@';

	snake.y = 10;
	snake.x = 15;
}

void snake_move()
{
	switch (snake.dir) {
	case UP:
		snake.y--;
		break;
	case DOWN:
		snake.y++;
		break;
	case LEFT:
		snake.x--;
		break;
	case RIGHT:
		snake.x++;
		break;
	}
}

int check_snake()
{
	if (snake.y == 0 || snake.y == (window_rows - LOGWIN_YLEN - 3)
	    || snake.x == 0 || snake.x == (window_cols - 7))
		return -1;
	return 0;
}
