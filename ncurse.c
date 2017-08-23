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
static char *logbuf[LOGBUF_NUM];
static char *emptyline;
void logwin_init()
{
	int i;
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

	/* Initialize logbuf */
	for (i = 0; i < LOGBUF_NUM; i++) {
		logbuf[i] = (char*)malloc(window_cols - 8);
		logbuf[i][0] = 0;
	}

	emptyline = malloc(window_cols);
	memset(emptyline, ' ', window_cols - 9);
	emptyline[window_cols - 9] = 0;
}

void logwin_destroy()
{
	int i;

	/* Free logbuf */
	for (i = 0; i < LOGBUF_NUM; i++)
		free(logbuf[i]);
	free(emptyline);
	delwin(logwin);
}

void runlog(char *str)
{
	static int index = 0;
	int i;

	strncpy(logbuf[index], str, window_cols - 10);
	logbuf[index][window_cols - 9] = 0;

	for (i = 0; i < LOGBUF_NUM; i++) {
		mvwprintw(logwin, i+1, 1, emptyline);
		mvwprintw(logwin, i+1, 1, logbuf[(index+i) % LOGBUF_NUM]);
		wrefresh(logwin);
	}

	index = (index + LOGBUF_NUM - 1) % LOGBUF_NUM;
}

static WINDOW *gmwin;
void gamewin_init()
{
	gmwin = newwin(window_rows - LOGWIN_YLEN - 2,   /* height */
			window_cols - 6,   /* width */
			1,                 /* start y */
			3                  /* start x */
		);
	/* Decorate the gmwin */
	box(gmwin, 0, 0);
	/* Print a logo on boundary */
	mvwprintw(gmwin, 0, 2, " Snake ");
	mvwprintw(gmwin, window_rows - LOGWIN_YLEN - 3 , 2, " Level: 0 ");
	/* Remember to refresh the window */
	wrefresh(gmwin);
}

void gamewin_destroy()
{
	delwin(gmwin);
}

