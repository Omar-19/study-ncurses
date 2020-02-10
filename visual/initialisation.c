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
    pl_param->fraction = 0;
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
	init_pair(5, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_WHITE, COLOR_GREEN);
	init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(8, COLOR_WHITE, COLOR_CYAN);
    init_pair(9, COLOR_WHITE, COLOR_BLACK);
}

void	initialisation_win(t_visual *vis)
{
	vis->win = newwin(64 + 2, 191 + 4, 0, 0);
	vis->win_res = newwin(22, 59, 0, 196);
	vis->win_pl1 = newwin(11, 59, 22, 196);
	vis->win_pl2 = newwin(11, 59, 33, 196);
	vis->win_pl3 = newwin(11, 59, 44, 196);
	vis->win_pl4 = newwin(11, 59, 55, 196);
    vis->win_res_line = newwin(2, 255, 66, 0);
}