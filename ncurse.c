#include "ncurse.h"

int window_rows, window_cols;
/* libncurse initialization function */
void ncurses_init(void)
{
	/* ncurse initialize */
	initscr();
	getmaxyx(stdscr, window_rows, window_cols);
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

static WINDOW *logwin;
/* Create the log window */
void logwin_init()
{
	logwin = newwin(LOGWIN_YLEN,       /* height */
			window_cols - 6,   /* width */
			window_rows - LOGWIN_YLEN,  /* start y */
			3                  /* start x */
		);
	/* Decorate the logwin */
	box(logwin, 0, 0);
	/* Print a LOG on boundary */
	mvwprintw(logwin, 0, 2, " LOG ");
	/* Remember to refresh the window */
	wrefresh(logwin);
}

void logwin_destroy()
{
	delwin(logwin);
}
