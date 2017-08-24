#include <stdio.h>
#include <ncurses.h>
#include "ncurse.h"
#include "snake.h"

int main()
{

	ncurses_init();

	/* Draw the window */
	refresh();

	logwin_init();
	runlog("Press");

	gamewin_init();

	snake_create();
	draw_snake();

	/* Wait for input */
	getch();

	gamewin_destroy();
	logwin_destroy();
	ncurses_destroy();
	return 0;
}
