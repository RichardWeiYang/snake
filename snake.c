#include "snake.h"
#include "ncurse.h"

struct snake snake;
struct food food = {0, 0, '*'};

void snake_create()
{

	snake.dir = LEFT;
	snake.length = 1;
	snake.c = '@';

	snake.tail = malloc(sizeof(struct snake_body));
	snake.tail->y = 10;
	snake.tail->x = 15;
	snake.tail->front = NULL;
}

void snake_move()
{
	switch (snake.dir) {
	case UP:
		snake.tail->y--;
		break;
	case DOWN:
		snake.tail->y++;
		break;
	case LEFT:
		snake.tail->x--;
		break;
	case RIGHT:
		snake.tail->x++;
		break;
	}
}

int check_snake()
{
	if (snake.tail->y == 0 || snake.tail->y == (window_rows - LOGWIN_YLEN - 3)
	    || snake.tail->x == 0 || snake.tail->x == (window_cols - 7))
		return -1;
	return 0;
}

int check_food()
{
	if (food.y == snake.tail->y && food.x == snake.tail->x)
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

