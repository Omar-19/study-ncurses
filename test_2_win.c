#include "ncurses.h"

int main()
{
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
	WINDOW *win = newwin(5, 5, 20, 20);
    WINDOW *win2 = newwin(5, 5, 0, 0);

	// char hello[] = "qwerty!";

	// mvaddstr(LINES/2, (COLS - strlen(hello))/2, hello);
	box(win, 0, 0);
    box(win2, 0, 0);

	wrefresh(win);
    // getch();
    wrefresh(win2);
	getch();

	delwin(win);
	endwin();

    delwin(win2);
    endwin();

	return (0);
}
// gcc -lncurses main.c