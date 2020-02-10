#include "ncurses.h"

void	white_win_write(t_visual *vis)
{
	mvwprintw(vis->win_res, 4, 8, vis->game_param.lim);
	mvwprintw(vis->win_res, 7, 8, vis->game_param.processes);
	mvwprintw(vis->win_res, 10, 8, vis->game_param.c_t_d);
	mvwprintw(vis->win_res, 13, 8, vis->game_param.c_delta);
	mvwprintw(vis->win_res, 16, 8, vis->game_param.nbr_l_max_checks);
}

void	color_one_win_write(WINDOW *win, t_players_param *pl_par)
{
	//Вывод для блока player
	wbkgd(win, COLOR_PAIR(pl_par->num_player));
	mvwprintw(win, 2, 8, pl_par->player);
	mvwprintw(win, 5, 8, pl_par->last_live);
	mvwprintw(win, 8, 8, pl_par->l_in_current_p);
}

// void	color_line(int *x, vis, )
// {}

void	win_fraction(t_visual *vis)
{
	int white;
	int i;

	i = 0;
	// написать функцию распределения цветов в строке долей
	white = 255 - (255 * (vis->pl1_param.fraction + vis->pl2_param.fraction +
		vis->pl3_param.fraction + vis->pl4_param.fraction)) / 4096;
	// color_line(1, vis->pl1_param.fraction, &i);
	// color_line(2, vis->pl2_param.fraction, &i);
	// color_line(3, vis->pl3_param.fraction, &i);
	// color_line(4, vis->pl4_param.fraction, &i);
	// color_line(0, white, &i);
	// (!ptr->is_caret) ? (color_set(ptr->id, NULL)) : (color_set(ptr->id + 4, NULL));
	// mvaddstr(i, 2 + j * 3, char_to_hex(ptr->symbol));
}

void	color_win_write(t_visual *vis)
{
	color_one_win_write(vis->win_pl1, &vis->pl1_param);
	color_one_win_write(vis->win_pl2, &vis->pl2_param);
	color_one_win_write(vis->win_pl3, &vis->pl3_param);
	color_one_win_write(vis->win_pl4, &vis->pl4_param);
	win_fraction(vis);
}

void	func_box(t_visual *vis)
{
	box(vis->win, 0, 0);
	box(vis->win_res, 0, 0);
	box(vis->win_pl1, 0, 0);
	box(vis->win_pl2, 0, 0);
	box(vis->win_pl3, 0, 0);
	box(vis->win_pl4, 0, 0);
    box(vis->win_res_line, 0, 0);
}

void	func_wrefresh(t_visual *vis)
{
	wrefresh(vis->win);
	wrefresh(vis->win_res);
	wrefresh(vis->win_pl1);
	wrefresh(vis->win_pl2);
	wrefresh(vis->win_pl3);
	wrefresh(vis->win_pl4);
    wrefresh(vis->win_res_line);
	getch();
}
