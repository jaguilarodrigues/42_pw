#include "push_swap.h"

void	print_stack(t_node *stack, int len)
{
	int	i;
	t_node *current;

	i = 0;
	current = stack;
	while (i < len)
	{
		
		printf("[%d] %d\n", i, current->number);
		current = current->next;
		i++;
	}
}
