#include <stdio.h>
#include <ncurses.h>
#include "ncurse.h"

int main()
{
	ncurses_init();

	/* Print message at (0, 0) */
	printw("Hello world\n");
	/* Draw the window */
	refresh();
	/* Wait for input */
	getch();

	ncurses_destroy();
	return 0;
}
