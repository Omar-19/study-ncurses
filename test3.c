#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ncurses.h"

int main()
{
	// ---EX3--- рамки + выравнивание окна по центру
	const int width = 50;
	const int height = 20;

	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}

	initscr();
	curs_set(0);
	refresh();

	int offsetx = (COLS - width) / 2;
	int offsety = (LINES - height) / 2;

	// инициализация окна
	// WINDOW *newwin(nlines, ncols, y0, x0)
	// nlines — это число строк;
	// ncols — число столбцов окна;
	// y0 и x0 — координаты верхнего левого угла окна.
	WINDOW *win = newwin(height, width, offsety, offsetx);

	char hello[] = "qwerty!";

	mvaddstr(LINES/2, (COLS - strlen(hello))/2, hello);
	box(win, 0, 0);

	wrefresh(win);
	getch();

	delwin(win);
	endwin();

	return (0);
}
// gcc -lncurses main.c