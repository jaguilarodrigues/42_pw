/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:58:47 by jaqrodri          #+#    #+#             */
/*   Updated: 2022/06/27 07:58:48 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*f_pointer(char const *s, char c)
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	i = 0;
	str = (char *)malloc(len * sizeof(char) + 1);
	str[len] = '\0';
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

char	*f_findword(char const *s, char c, unsigned int word)
{
	unsigned int	words;
	int				trigger;

	trigger = 0;
	words = 0;
	while (*s || word == words)
	{
		if (word == words)
			return (f_pointer(--s, c));
		else if (*s != c && trigger == 0)
		{
			words++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (0);
}

unsigned int	f_countw(char const *s, char c)
{
	unsigned int	words;
	int				trigger;

	trigger = 0;
	words = 0;
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			words++;
			trigger = 1;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**str;
	unsigned int	words;

	if (!s)
		return (NULL);
	words = f_countw(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[words] = NULL;
	i = 0;
	while (i < words)
	{
		str[i] = f_findword(s, c, i + 1);
		i++;
	}
	return (str);
}
