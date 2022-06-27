#include "push_swap.h"


void	sort_stack(t_game *game)
{
	if (game->len_total > 5)
		radix_sort(game);
}
