#include <stdio.h>
#include <ncurses.h>
#include <sys/select.h>
#include "ncurse.h"
#include "snake.h"

int start_game()
{
	int key;
	fd_set set;

	/* monitor the standard input */
	FD_ZERO(&set);
	FD_SET(0, &set);
	if (select(1, &set, NULL, NULL, NULL) < 0)
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

	clear_snake();
	snake_move();
	draw_snake();

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
	draw_snake();

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
