#include "ncurses.h"

char	hex_part(int num)
{
	if (num == 10)
		return ('a');
	if (num == 11)
		return ('b');
	if (num == 12)
		return ('c');
	if (num == 13)
		return ('d');
	if (num == 14)
		return ('e');
	if (num == 15)
		return ('f');
	if (num >= 0 && num <= 9)
		return ('0' + num);
	return ('Z');
}

char	*char_to_hex(unsigned char c)
{
	int		symb;
	char	*str;

	str = (char *)malloc(4);
	str[2] = ' ';
	str[3] = '\0';
	symb = c;
	str[0] = hex_part(symb / 16);
	str[1] = hex_part(symb % 16);
	return (str);
}

void	fraction_add(t_visual *vis, t_map *ptr)
{
	(ptr->id == 1) ? (++vis->pl1_param.fraction) : 0;
	(ptr->id == 2) ? (++vis->pl2_param.fraction) : 0;
	(ptr->id == 3) ? (++vis->pl3_param.fraction) : 0;
	(ptr->id == 4) ? (++vis->pl4_param.fraction) : 0;
}

void	write_tab(t_visual *vis, t_var_game *par)
{
	int		i;
	int		j;
	t_map	*ptr;

	i = 0;
	ptr = par->map;
	while (++i <= 64)
	{
		j = -1;
		while (++j < 64)
		{
			if (ptr->id)
			{
				fraction_add(vis, ptr);
				(!ptr->is_caret) ? (color_set(ptr->id, NULL)) : (color_set(ptr->id + 4, NULL));
				mvaddstr(i, 2 + j * 3, char_to_hex(ptr->symbol));
			}
			else
				mvaddstr(i, 2 + j * 3, char_to_hex(0));
			color_set(9, NULL);
			ptr = ptr->next;
		}
	}
}

void	visual(t_var_game *par)
{
	t_visual	vis;

	// init
	initialisation_gp_pl(&vis);

	(!initscr()) ? (ft_error()) : 0;

	curs_set(0);
	refresh();

    // char test_str[192];

    // int i = -1;
    // while (i < 191)
    // {
	// 	(i % 3 == 0 || i % 3 == 1) ? (test_str[i] = '0') : (test_str[i] = ' ');
	// 	++i;
    // }
    // test_str[191] = '\0';
	
	// init
	initialisation_win(&vis);

	start_color();
	// init
	initialisation_color_pair();

	write_tab(&vis, par);
	// i = 1;
	// while (i <= 64)
	// {
	// 	(i % 2) ? (color_set(1, NULL)) : (color_set(2, NULL));
	// 	mvaddstr(i++, 2, test_str);
	// }

	// usleep(300000); ???

	
	// Вывод для блока основной информации:
	white_win_write(&vis);
	
	// Вывод цветных блоков
	color_win_write(&vis);

	func_box(&vis);

	func_wrefresh(&vis);

	del_all_wins(&vis);
}
// gcc -lncurses main.c
