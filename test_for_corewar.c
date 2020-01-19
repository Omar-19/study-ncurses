#include "ncurses.h"

int main()
{
	// задание размеров окна
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

    char test_str[192];

    int i = -1;
    while (i < 191)
    {
		(i % 3 == 0 || i % 3 == 1) ? (test_str[i] = '0') : (test_str[i] = ' ');
		++i;
    }
    test_str[191] = '\0';
    // printf("%s\n", test_str);
	// int offsetx = (COLS - width) / 2;
	// int offsety = (LINES - height) / 2;

	// инициализация окна
	// WINDOW *newwin(nlines, ncols, y0, x0)
	// nlines — это число строк;
	// ncols — число столбцов окна;
	// y0 и x0 — координаты верхнего левого угла окна.
	// WINDOW *win = newwin(height, width, offsety, offsetx);
    WINDOW *win;
	win = newwin(64 + 2, 191 + 4, 0, 0);
	WINDOW *win_res;
	win_res = newwin(22, 60, 0, 196);
	WINDOW *win_pl1 = newwin(11, 60, 22, 196);
	WINDOW *win_pl2 = newwin(11, 60, 33, 196);
	WINDOW *win_pl3 = newwin(11, 60, 44, 196);
	WINDOW *win_pl4 = newwin(11, 60, 55, 196);

	// char hello[] = "qwerty!";

	i = 1;
	while (i <= 64)
		mvaddstr(i++, 2, test_str);
	box(win, 0, 0);
	box(win_res, 0, 0);
	box(win_pl1, 0, 0);
	box(win_pl2, 0, 0);
	box(win_pl3, 0, 0);
	box(win_pl4, 0, 0);

	wrefresh(win);
	wrefresh(win_res);
	wrefresh(win_pl1);
	wrefresh(win_pl2);
	wrefresh(win_pl3);
	wrefresh(win_pl4);
	getch();

	delwin(win);
	endwin();
	delwin(win_res);
	endwin();
	delwin(win_pl1);
	endwin();
	delwin(win_pl2);
	endwin();
	delwin(win_pl3);
	endwin();
	delwin(win_pl4);
	endwin();

	return (0);
}
// gcc -lncurses main.c
