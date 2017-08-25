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

void snake_move_tail_to_head()
{
	struct snake_body *head = snake.tail;

	while (head->front)
		head = head->front;

	snake.tail->y = head->y;
	snake.tail->x = head->x;
	head->front = snake.tail;
	head = snake.tail;
	snake.tail = snake.tail->front;
	head->front = NULL;

	switch (snake.dir) {
	case UP:
		head->y--;
		break;
	case DOWN:
		head->y++;
		break;
	case LEFT:
		head->x--;
		break;
	case RIGHT:
		head->x++;
		break;
	}
}

int check_snake()
{
	struct snake_body *head = snake.tail;

	while (head->front)
		head = head->front;

	if (head->y == 0 || head->y == (window_rows - LOGWIN_YLEN - 3)
	    || head->x == 0 || head->x == (window_cols - 7))
		return -1;
	return 0;
}

void add_snake_tail(int y, int x)
{
	struct snake_body *body;

	body = malloc(sizeof(struct snake_body));
	body->y = y;
	body->x = x;
	body->front = snake.tail;
	snake.tail = body;
}

int check_food()
{
	struct snake_body *head = snake.tail;

	while (head->front)
		head = head->front;

	if (food.y == head->y && food.x == head->x)
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

