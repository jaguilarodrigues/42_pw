#include "push_swap.h"

void	start_game(t_game *game, int argc)
{
	game->len_total = argc - 1;
	game->len_a = 0;
	game->len_b = 0;
	game->number_max = 0;
	game->stack_a = NULL;
	game->stack_b = NULL;
}

t_node	*last_node(t_node *stack)
{
	t_node *current;

	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	set_stack(t_game *game, int *normalized)
{
	int		i;
	t_node	*new_node;
	t_node	*end_node;

	i = 0;
	while (i < (game->len_total))
	{
		new_node = (t_node *)ft_calloc(sizeof(t_node), 1);
		new_node->number = normalized[i];
		new_node->next = NULL;
		new_node->previous = NULL;
		if (game->stack_a == NULL)
			game->stack_a = new_node;
		else
		{
			end_node = last_node(game->stack_a);
			end_node->next = new_node;
			new_node->previous = end_node;
		}
		if (new_node->number > game->number_max)
			game->number_max = new_node->number;
		game->len_a++;
		i++;
	}
	connect_nodes(game->stack_a, last_node(game->stack_a));
}

int	main(int argc, char *argv[])
{
	int		*normalized;
	t_game	*game;

	(void)argv;
	(void)argc;
	game = (t_game *)ft_calloc(sizeof(t_game), 1);
	start_game(game, argc);
	if (argc <= 1)
		exit(error());
	if (!check_error(argc, argv))
		exit(error());
	normalized = normalize_input(argv, argc - 1);
	set_stack(game, normalized);

	//print_stack(game->stack_a, game->len_a);
	sort_stack(game);
	//print_stack(game->stack_a, game->len_a);
	//printf("\n");
	//print_stack(game->stack_b, game->len_b);
	free(normalized);
	exit (0);
}
