#include <stdio.h>
#include <ncurses.h>
#include "ncurse.h"

int main()
{

	ncurses_init();

	/* Draw the window */
	refresh();

	logwin_init();

	/* Wait for input */
	getch();

	logwin_destroy();
	ncurses_destroy();
	return 0;
}
