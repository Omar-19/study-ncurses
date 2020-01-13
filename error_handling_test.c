#include "ncurses.h"

int main()
{
	// ---EX2-- обработка ошибки
	if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
    }

    WINDOW *win = newwin(LINES, COLS, 0, 0);

    printw("Hello, world!");

    curs_set(0);
    refresh();
    getch();

    delwin(win);
    endwin();
	return (0);
}