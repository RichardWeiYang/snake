#ifndef NCURSE_H
#define NCURSE_H
#include <ncurses.h>

extern int window_rows, window_cols;
void ncurses_init();
void ncurses_destroy();
#endif
