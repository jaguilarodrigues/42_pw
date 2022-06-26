#include "push_swap.h"

void	print_stack(t_game *game)
{
	int	i;

	i = 0;
	while (i <  game->len_a)
	{
		printf("[%d] %d\n", i, (game->stack_a + i));
		i++;
	}
}
