#include "push_swap.h"

void	connect_nodes(t_node *first, t_node *second)
{
	first->previous = second;
	second->next = first;
}

t_node	*pop_node(t_node **stack)
{
	t_node	*pop;
	t_node	*tail;
	t_node	*head;

	head = *stack;
	if (!head)
		return (NULL);
	pop = head;
	if (head->next != head)
	{
		tail = head->previous;
		head = head->next;
		connect_nodes(head, tail);
	}
	else
		head = NULL;
	pop->previous = NULL;
	pop->next = NULL;
	*stack = head;
	return (pop);
}

void	push_node(t_node *pop, t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	head = *stack;
	if (!head)
		connect_nodes(pop, pop);
	else
	{
		tail = head->previous;
		pop->next = head;
		head->previous = pop;
		pop->previous = tail;
		tail->next = pop;
	}
	*stack = pop;
}


int	is_ordered(t_node *stack, int len)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack;
	while (i < len-1)
	{
		if (current->number > (current->next)->number)
		{
			return (0);
		}
		current = current->next;
		i++;
	}
	return (1);
}