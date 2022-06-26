/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 01:40:27 by jaqrodri          #+#    #+#             */
/*   Updated: 2022/06/26 06:33:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i <  game->len_a)
	{
		printf("[%d] %d\n", i, (game->stack_a + i));
		i++;
	}
	free(stack->stack);
}
