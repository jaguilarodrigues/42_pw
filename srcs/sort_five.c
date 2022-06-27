/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:57:56 by jaqrodri          #+#    #+#             */
/*   Updated: 2022/06/27 07:58:02 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_second_smallest_to_b(t_game *game, int position)
{
	if (position == 2)
		swap_a(game->stack_a, game->stack_a->next);
	if (position == 3)
	{
		rotate_a(&game->stack_a);
		swap_a(game->stack_a, game->stack_a->next);
	}
	if (position == 4)
		reverse_rotate_a(&game->stack_a);
	push_b(game);
}

static void	push_smallest_to_b(t_game *game, int position)
{
	if (position == 2)
		swap_a(game->stack_a, game->stack_a->next);
	if (position == 3)
	{
		rotate_a(&game->stack_a);
		swap_a(game->stack_a, game->stack_a->next);
	}
	if (position == 4)
	{
		reverse_rotate_a(&game->stack_a);
		reverse_rotate_a(&game->stack_a);
	}
	if (position == 5)
		reverse_rotate_a(&game->stack_a);
	push_b(game);
}

static int	find_smallest(t_game *game, int len)
{
	int		i;
	int		smallest;
	t_node	*current;

	i = 0;
	smallest = game->number_max;
	current = game->stack_a;
	while (i < len)
	{
		if (current->number < smallest)
			smallest = current->number;
		current = current->next;
		i++;
	}
	return (smallest);
}

static int	find_smallest_position(t_game *game, int len)
{
	int		i;
	int		smallest;
	t_node	*current;

	i = 1;
	smallest = find_smallest(game, len);
	current = game->stack_a;
	while (i < game->len_total)
	{
		if (current->number == smallest)
			break ;
		i++;
		current = current->next;
	}
	return (i);
}

void	sort_five(t_game *game)
{
	int	position;

	position = find_smallest_position(game, 5);
	push_smallest_to_b(game, position);
	position = find_smallest_position(game, 4);
	push_second_smallest_to_b(game, position);
	sort_three(game);
	push_a(game);
	push_a(game);
}
