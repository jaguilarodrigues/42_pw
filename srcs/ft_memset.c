/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:59:23 by jaqrodri          #+#    #+#             */
/*   Updated: 2022/06/27 07:59:27 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			i;
	unsigned char	*ptr2;

	ptr2 = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		*ptr2 = (unsigned char)x;
		i++;
		ptr2++;
	}
	return (ptr);
}
