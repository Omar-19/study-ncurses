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
		if (i > 3000)
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

	par.map = test_init();
	visual(&par);
	int i = 0;
	t_map *ptr = par.map;
	// while (ptr)
	// {
	// 	++i;
	// 	printf("%d ", ptr->is_caret);
	// 	ptr = ptr->next;
	// }
	printf("\n");
	return (0);
}