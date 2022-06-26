#include "push_swap.h"

void	setup_stacks(t_game	*game, int *normalized)
{
	int 	i;
	t_node 	*new_node;

	game->len_a = 0;
	game->len_b = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
	i = 0;
	while(i < game->len_total)
	{
		new_node = (t_node *)ft_calloc(sizezof(t_node), 1);
		new_node->number = normalized[i];
		if game->stack_a == NULL
		{
			new_node->next = NULL;
			new_node->previous = NULL;
			game->stack_a = new_node;
		}else{
			last_node = game->stack_a->previous;

			new_node->previous = last_node;
			last_node->next = new_node;
			new_node->next = game->stack_a;
		}
		game->len_a++;
		i++;
	}
}


int		main(int argc, char *argv[])
{
	int *normalized;
	(void)argv;
	(void)argc;

	t_game	*game;

	if (argc <= 1)
		return (error());
	if (!check_error(argc, argv))
		return (error());
	normalized = normalize_input(argv, argc - 1);
	set_stack(game, normalized);
	print_stack(game);

	free(normalized);
	return (0);
}
