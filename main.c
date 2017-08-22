#include <stdio.h>
#include <ncurses.h>
#include "ncurse.h"

int main()
{

	ncurses_init();

	/* Print message at (0, 0) */
	printw("Hello world\n");

	/* Print message at (5, 5) */
	mvprintw(5, 5, "Hello world\n");
	/* Print message at the middle */
	mvprintw(window_rows / 2, window_cols / 2, "Hello world\n");

	/* Draw the window */
	refresh();
	/* Wait for input */
	getch();

	ncurses_destroy();
	return 0;
}
