#include "snake.h"
#include "ncurse.h"

struct snake snake;
struct food food = {0, 0, '*'};

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

int check_food()
{
	if (food.y == snake.y && food.x == snake.x)
		return 1;
	return 0;
}

void create_food()
{
	do {
		food.y = random() % (window_rows - LOGWIN_YLEN - 4) + 1;
		food.x = random() % (window_cols - 8) + 1;
	} while (check_food());
}

