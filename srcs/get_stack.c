#include "push_swap.h"

int	only_digit(const char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	validate_input(const char *str)
{
	long int	num;

	if (!only_digit(str))
		return (0);
	num = ft_atoi(str);
	if ((num > INT_MAX) || (num < INT_MIN))
		return (0);
	return (1);
}

int	check_error(int argc, char *argv[])
{
	int	i;
	int	j;
	int	num;
	int	next;

	i = 1;
	while (i < argc)
	{
		if (!validate_input(argv[i]))
			return (0);
		num = (int)ft_atoi(argv[i]);
		j = 1;
		while (j < argc)
		{
			next = ft_atoi(argv[j]);
			if (i != j && num == next)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
