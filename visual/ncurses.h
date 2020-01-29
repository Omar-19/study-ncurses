#ifndef NCURSES_H
# define NCURSES_H
# define MEM_SIZE 4096

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct		s_game_param
{
	char	lim[24]; //"Cycles/second limit : \0"
	int		ilim;
	char	cycle[9];
	int		icycle;
	char	processes[13]; //"Processes : \0"
	int		iprocesses;
	char	c_t_d[17];//CYCLES_TO_DIE : \0
	int		ic_t_d;
	char	live[8];
	int		ilive;
	char	c_delta[15];//CYCLE_DELTA : \O
	int		ic_delta;
	char	nbr_l_max_checks[23];//NBR_LIVE MAX_CHECKS : \0
	int		inbr_l_max_checks;
	int		parts[5]; // 0 поле    1-4 игроки
}					t_game_param;

typedef struct		s_players_param
{
	char	player[10];//Player - \0
	int		num_player;
	char	*player_name;
	char	last_live[13];//Last live : \0
	int		ilast_live;
	char	l_in_current_p[27];//Lives in current period : \0
	int		il_in_current_p;
	int		color;
}					t_players_param;

typedef struct	s_map
{
	struct s_map	*next;
	char			symbol;
	int				id;
}				t_map;

typedef struct	s_var_game
{
	// t_list_car		*list_car;
	// t_list_champ	*list_champ;
	t_map 			*map;
	// int				count_player;
	// int				cur_cycl;
	// int				last_cycles_to_die;
	// int				live_player;
	// int 				count_live;
	// int				cycles_to_die;
	// int				count_check;
}				t_var_game;

typedef struct	s_visual
{
	t_game_param	game_param;
	t_players_param	pl1_param;
	t_players_param	pl2_param;
	t_players_param	pl3_param;
	t_players_param	pl4_param;
	WINDOW			*win;
	WINDOW			*win_res;
	WINDOW			*win_pl1;
	WINDOW			*win_pl2;
	WINDOW			*win_pl3;
	WINDOW			*win_pl4;
}				t_visual;


#endif