#include "push_swap.h"

void	push_a(t_game	*game)
{
	t_node	*pop;

	pop = pop_node(&game->stack_b);
	push_node(pop, &game->stack_a);
	game->len_a += 1;
	game->len_b -= 1;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_game	*game)
{
	t_node	*pop;

	pop = pop_node(&game->stack_a);
	push_node(pop, &game->stack_b);
	game->len_a -= 1;
	game->len_b += 1;
	ft_putstr_fd("pb\n", 1);
}

void	rotate_a(t_node **stack)
{
	t_node	*head;

	head = *stack;
	if (head != NULL)
	{
		head = head->next;
		*stack = head;
		ft_putstr_fd("ra\n", 1);
	}
}