#include "ncurses.h"

int main()
{
	const int max_x = 7;
	const int max_y = max_x*max_x;

	initscr();
	curs_set(0);

	for (int x = 0; x < 2 * max_x + 1; x++)
	{
		int y = (x-max_x) * (x-max_x);
		// mvaddch - вывод заданного символа
		mvaddch(max_y - y, x, 'o');
		refresh();
		sleep(1);
	}

	getch();
	endwin();
    return (0);
}