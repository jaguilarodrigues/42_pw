/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:57:01 by jaqrodri          #+#    #+#             */
/*   Updated: 2022/06/27 07:57:02 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isaccept(int c)
{
	if ((c >= 8 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	else
		return (1);
}

long int	ft_atoi(const char *str)
{
	int			sinal;
	long int	num;

	sinal = 1;
	num = 0;
	while (ft_isaccept(*str))
		str++;
	if (*str == '-')
	{
		sinal = sinal * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sinal);
}
