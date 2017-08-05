#include "ncurse.h"

/* libncurse initialization function */
void ncurses_init(void)
{
	/* ncurse initialize */
	initscr();
	/* disabling line buffer */
	cbreak();
	/* disable character echoing */
	noecho();
	/* enable function keys */
	keypad(stdscr, TRUE);
	/* make cursor invisible */
	curs_set(0);
}

/* libncurse destroy function */
void ncurses_destroy()
{
	/* ncurse cleanup */
	endwin();
}
