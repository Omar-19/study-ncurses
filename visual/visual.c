#include "ncurses.h"

void	init_gp(t_game_param *game_param)
{
	memmove(game_param->lim, "Cycles/seconds limit : \0", 23);
	memmove(game_param->cycle, "Cycle : \0", 9);
	memmove(game_param->processes, "Processes : \0", 13);
	memmove(game_param->c_t_d, "CYCLES_TO_DIE : \0", 17);
	memmove(game_param->live, "Live : \0", 8);
	memmove(game_param->c_delta, "CYCLE_DELTA : \0", 15);
	memmove(game_param->nbr_l_max_checks, "NBR_LIVE MAX_CHECKS : \0", 23);
	game_param->icycle = 0;
	game_param->iprocesses = 0;
	game_param->ilim = 0;
	game_param->ic_delta = 0;
	game_param->ic_t_d = 0;
	game_param->ilive = 0;
	game_param->inbr_l_max_checks = 0;
}

void	init_pl(t_players_param *pl_param, int num)
{
	memmove(pl_param->player, "Player - \0", 10);
	memmove(pl_param->last_live, "Last live : \0", 13);
	memmove(pl_param->l_in_current_p, "Lives in current period : \0", 27);
	pl_param->num_player = num;
	pl_param->il_in_current_p = 0;
	pl_param->ilast_live = 0;
	(num == 1) ? (pl_param->color = 0) : 0;
	(num == 2) ? (pl_param->color = 0) : 0;
	(num == 3) ? (pl_param->color = 0) : 0;
	(num == 4) ? (pl_param->color = 0) : 0;
}

void	initialisation_gp_pl(t_visual *vis)
{
	init_gp(&vis->game_param);
	init_pl(&vis->pl1_param, 1);
	init_pl(&vis->pl2_param, 2);
	init_pl(&vis->pl3_param, 3);
	init_pl(&vis->pl4_param, 4);
}

void	initialisation_color_pair()
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_YELLOW);
	init_pair(6, COLOR_GREEN, COLOR_CYAN);
	init_pair(7, COLOR_MAGENTA, COLOR_YELLOW);
	init_pair(8, COLOR_CYAN, COLOR_WHITE);
}

void	initialisation_win(t_visual *vis)
{
	vis->win = newwin(64 + 2, 191 + 4, 0, 0);
	vis->win_res = newwin(22, 60, 0, 196);
	vis->win_pl1 = newwin(11, 60, 22, 196);
	vis->win_pl2 = newwin(11, 60, 33, 196);
	vis->win_pl3 = newwin(11, 60, 44, 196);
	vis->win_pl4 = newwin(11, 60, 55, 196);
}

int main()
{
	t_visual	vis;

	initialisation_gp_pl(&vis);

	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}

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

	initialisation_win(&vis);
    // WINDOW *win = newwin(64 + 2, 191 + 4, 0, 0);
	// WINDOW *win_res = newwin(22, 60, 0, 196);
	// WINDOW *win_pl1 = newwin(11, 60, 22, 196);
	// WINDOW *win_pl2 = newwin(11, 60, 33, 196);
	// WINDOW *win_pl3 = newwin(11, 60, 44, 196);
	// WINDOW *win_pl4 = newwin(11, 60, 55, 196);

	start_color();
	initialisation_color_pair();

	i = 1;
	while (i <= 64)
	{
		(i % 2) ? (color_set(1, NULL)) : (color_set(2, NULL));
		mvaddstr(i++, 2, test_str);
	}

	// usleep(300000);

	// mvaddstr(LINES/2, (COLS - strlen(hello))/2, hello);

	// color_set(n, NULL);
	// mvaddstr(5 + n, (COLS-strlen(hello))/2, hello);

	// Вывод для блока основной информации:
	mvwprintw(vis.win_res, 4, 8, vis.game_param.lim);
	mvwprintw(vis.win_res, 7, 8, vis.game_param.processes);
	mvwprintw(vis.win_res, 10, 8, vis.game_param.c_t_d);
	mvwprintw(vis.win_res, 13, 8, vis.game_param.c_delta);
	mvwprintw(vis.win_res, 16, 8, vis.game_param.nbr_l_max_checks);
	
	//Вывод для блока player 1
	wbkgd(vis.win_pl1, COLOR_PAIR(vis.pl1_param.num_player));
	mvwprintw(vis.win_pl1, 2, 8, vis.pl1_param.player);
	mvwprintw(vis.win_pl1, 5, 8, vis.pl1_param.last_live);
	mvwprintw(vis.win_pl1, 8, 8, vis.pl1_param.l_in_current_p);

	//Вывод для блока player 2
	wbkgd(vis.win_pl2, COLOR_PAIR(vis.pl2_param.num_player));
	mvwprintw(vis.win_pl2, 2, 8, vis.pl1_param.player);
	mvwprintw(vis.win_pl2, 5, 8, vis.pl1_param.last_live);
	mvwprintw(vis.win_pl2, 8, 8, vis.pl1_param.l_in_current_p);

	//Вывод для блока player 3
	wbkgd(vis.win_pl3, COLOR_PAIR(vis.pl3_param.num_player));
	mvwprintw(vis.win_pl3, 2, 8, vis.pl1_param.player);
	mvwprintw(vis.win_pl3, 5, 8, vis.pl1_param.last_live);
	mvwprintw(vis.win_pl3, 8, 8, vis.pl1_param.l_in_current_p);

	//Вывод для блока player 4
	wbkgd(vis.win_pl4, COLOR_PAIR(vis.pl4_param.num_player));
	mvwprintw(vis.win_pl4, 2, 8, vis.pl1_param.player);
	mvwprintw(vis.win_pl4, 5, 8, vis.pl1_param.last_live);
	mvwprintw(vis.win_pl4, 8, 8, vis.pl1_param.l_in_current_p);

	box(vis.win, 0, 0);
	box(vis.win_res, 0, 0);
	box(vis.win_pl1, 0, 0);
	box(vis.win_pl2, 0, 0);
	box(vis.win_pl3, 0, 0);
	box(vis.win_pl4, 0, 0);

	wrefresh(vis.win);
	wrefresh(vis.win_res);
	wrefresh(vis.win_pl1);
	wrefresh(vis.win_pl2);
	wrefresh(vis.win_pl3);
	wrefresh(vis.win_pl4);
	getch();

	delwin(vis.win);
	endwin();
	delwin(vis.win_res);
	endwin();
	delwin(vis.win_pl1);
	endwin();
	delwin(vis.win_pl2);
	endwin();
	delwin(vis.win_pl3);
	endwin();
	delwin(vis.win_pl4);
	endwin();

	return (0);
}
// gcc -lncurses main.c
