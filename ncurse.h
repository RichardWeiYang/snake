#ifndef NCURSE_H
#define NCURSE_H
#include <ncurses.h>

#define LOGWIN_YLEN      7

extern int window_rows, window_cols;
void ncurses_init();
void ncurses_destroy();
void logwin_init();
void logwin_destroy();
#endif
