#include "ncurses.h"

t_map	*test_init()
{
	t_map *map;
	t_map *ptr;
	int i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	ptr = map;
	
	//test par
	ptr->id = 1;
	ptr->symbol = 0;
	ptr->is_caret = (i % 17 == 0) ? 1 : 0;
	ptr->next = NULL;

	while(++i < 4096)
	{
		ptr->next = (t_map *)malloc(sizeof(t_map));
		ptr = ptr->next;
		// нумерация игроков от 1 до 4   0 - пустое поле
		ptr->id = i % 4 + 1;
		if (i > 2000)
			ptr->id = 0;
		ptr->symbol = (char)(i % 256);
		// printf("%d ", ptr->symbol);
		ptr->is_caret = (i % 17 == 0) ? 1 : 0;
		ptr->next = NULL;
	}
	// printf("\n");
	return (map);
}

t_map	*test_init1()
{
	t_map *map;
	t_map *ptr;
	int i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	ptr = map;
	
	//test par
	ptr->id = 1;
	ptr->symbol = 0;
	ptr->is_caret = (i % 17 == 0) ? 1 : 0;
	ptr->next = NULL;

	while(++i < 4096)
	{
		ptr->next = (t_map *)malloc(sizeof(t_map));
		ptr = ptr->next;
		// нумерация игроков от 1 до 4   0 - пустое поле
		ptr->id = i % 4 + 1;
		if (i > 4000)
			ptr->id = 0;
		ptr->symbol = (char)(i % 256);
		// printf("%d ", ptr->symbol);
		ptr->is_caret = (i % 17 == 0) ? 1 : 0;
		ptr->next = NULL;
	}
	// printf("\n");
	return (map);
}

int		main()
{
	t_var_game par;
	t_visual	vis;
	// halfdelay(2);

	// init
	initialisation_gp_pl(&vis);
	(!initscr()) ? (ft_error()) : 0;

	initialisation_win(&vis);

	start_color();

	initialisation_color_pair();

	// func_wrefresh(&vis);
	par.map = test_init();
	visual(&vis, &par);
	func_wrefresh(&vis);

	par.map = test_init1();
	visual(&vis, &par);
	func_wrefresh(&vis);

	par.map = test_init();
	visual(&vis, &par);
	func_wrefresh(&vis);

	par.map = test_init1();
	visual(&vis, &par);
	func_wrefresh(&vis);

	par.map = test_init();
	visual(&vis, &par);
	func_wrefresh(&vis);

	par.map = test_init1();
	visual(&vis, &par);
	func_wrefresh(&vis);

	par.map = test_init();
	visual(&vis, &par);
	func_wrefresh(&vis);

	par.map = test_init1();
	visual(&vis, &par);
	func_wrefresh(&vis);

	// sleep(3);
	// func_wrefresh(&vis);

	// par.map = test_init();
	// visual(&vis, &par);
	
	// while (1)
	getch();
	del_all_wins(&vis);
	return (0);
}