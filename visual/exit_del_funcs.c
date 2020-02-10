#include "ncurses.h"

void	del_all_wins(t_visual *vis)
{
	delwin(vis->win);
	endwin();
	delwin(vis->win_res);
	endwin();
	delwin(vis->win_pl1);
	endwin();
	delwin(vis->win_pl2);
	endwin();
	delwin(vis->win_pl3);
	endwin();
	delwin(vis->win_pl4);
	endwin();
    delwin(vis->win_res_line);
	endwin();
}

void	ft_error()
{
	fprintf(stderr, "Error initialising ncurses.\n");
	exit(1);
}