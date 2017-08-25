#include <stdio.h>
#include <ncurses.h>
#include <sys/select.h>
#include <math.h>
#include "ncurse.h"
#include "snake.h"

int level = 0;

int start_game()
{
	int key;
	fd_set set;
	struct timeval timer;
	int old_y, old_x;

	/* monitor the standard input */
	FD_ZERO(&set);
	FD_SET(0, &set);
	timer.tv_sec = 0;
	timer.tv_usec = 1000000 / (sqrt(level) + 1);
	if (select(1, &set, NULL, NULL, &timer) < 0)
		return -1;

	/* detect the pressed key */
	if (FD_ISSET(0, &set)) {
		key = getch();

		switch (key) {
		case 'w':
			snake.dir = UP;
			break;
		case 's':
			snake.dir = DOWN;
			break;
		case 'a':
			snake.dir = LEFT;
			break;
		case 'd':
			snake.dir = RIGHT;
			break;
		case 'q':
			runlog("Quit Game!");
			return -1;
		default:
			return 0;
		}
	}

	old_y = snake.tail->y;
	old_x = snake.tail->x;
	clear_snake_tail();
	snake_move_tail_to_head();
	if (check_snake() == -1) {
		runlog("Game Over!");
		return -1;
	}

	if (check_food() == 1) {
		/* grow a tail on eating food */
		add_snake_tail(old_y, old_x);
		draw_snake_tail();
		create_food();
		draw_food();
		setlevel_gamewin(++level);
	}
	draw_snake_head();

	return 0;
}

int main()
{

	ncurses_init();

	/* Draw the window */
	refresh();

	logwin_init();
	runlog("Press 'w/s/a/d' to move or 'q' to quit");

	gamewin_init();

	snake_create();
	draw_snake_head();

	create_food();
	draw_food();

	/* start the game */
	while (start_game() != -1)
		;

	/* Wait for input */
	getch();

	gamewin_destroy();
	logwin_destroy();
	ncurses_destroy();
	return 0;
}
