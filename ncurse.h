#ifndef NCURSE_H
#define NCURSE_H
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

#define LOGWIN_YLEN      7
#define LOGBUF_NUM       (LOGWIN_YLEN-2)

extern int window_rows, window_cols;
void ncurses_init();
void ncurses_destroy();
void logwin_init();
void logwin_destroy();
void runlog(char *str);
void gamewin_init();
void gamewin_destroy();
void draw_snake();
#endif
