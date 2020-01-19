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
	char	lim[23]; //"Cycles/second limit : \0"
	int		ilim;
	char	cycle[6];
	int		icycle;
	char	processes[13]; //"Processes : \0"
	int		iprocesses;
}					t_game_param;

typedef struct		s_players_param
{

}					t_players_param;

#endif