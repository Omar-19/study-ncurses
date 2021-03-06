 #include "ncurses.h"

int main()
{
	const int max_x = 7;
	const int max_y = max_x*max_x;

	initscr();
	curs_set(0);

	const int width = 50;
	const int height = 20;

	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}

	int offsetx = (COLS - width) / 2;
	int offsety = (LINES - height) / 2;


    WINDOW *win = newwin(height, width, offsety, offsetx);

    start_color();

    char hello[] = "X";
    mvaddstr(5, (COLS-strlen(hello))/2, hello);

    if (has_colors() && COLOR_PAIRS >= 13)
    {
		int n = 1;

		// Инициализация цветовых пар
		init_pair(1,  COLOR_RED,     COLOR_BLACK);
		init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
		init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
		init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
		init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
		init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
		init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
		init_pair(8,  COLOR_WHITE,   COLOR_RED);
		init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
		init_pair(10, COLOR_BLUE,    COLOR_YELLOW);
		init_pair(11, COLOR_WHITE,   COLOR_BLUE);
		init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
		init_pair(13, COLOR_BLACK,   COLOR_CYAN);

		while (n <= 13)
		{
			color_set(n, NULL);
			mvaddstr(5 + n, (COLS-strlen(hello))/2, hello);
			++n;
		}
    }

    box(win, 0, 0);

	getch();
	endwin();
    return (0);
}