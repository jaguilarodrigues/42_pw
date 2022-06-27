#include "push_swap.h"

static void	list_to_int(int *first, int *second, int *third, t_node *stack)
{
	*first = stack->number;
	*second = (stack->next)->number;
	*third = (stack->previous)->number;
}

void	sort_three(t_game *game)
{
	int	first;
	int	second;
	int	third;

	list_to_int(&first, &second, &third, game->stack_a);
	if ((first > second && first < third && second < third)
		|| (first > second && first > third && second > third)
		|| (first < second && first < third && second > third))
		swap_a(game->stack_a, game->stack_a->next);
	if (is_ordered(game->stack_a, game->len_a) == 1)
		return ;
	list_to_int(&first, &second, &third, game->stack_a);
	if (first < second && first > third && second > third)
		reverse_rotate_a(&game->stack_a);
	if (first > second && first > third && second < third)
		rotate_a(&game->stack_a);
}

void	sort_two(t_game *game)
{
	if (game->stack_a->number > (game->stack_a->next)->number)
		rotate_a(&game->stack_a);
}

void	sort_stack(t_game *game)
{
	
	if (is_ordered(game->stack_a, game->len_a) == 1)
		return ;
	else if (game->len_total == 2)
		sort_two(game);
	else if (game->len_total == 3)
		sort_three(game);
	else if (game->len_total == 5)
		sort_five(game);
	else
		radix_sort(game);
}
