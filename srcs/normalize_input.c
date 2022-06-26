#include "push_swap.h"

int *set_to_array(char **argv, int size)
{

	int		i;
	int		*array;


	array = (int *)ft_calloc(sizeof(int), size);
	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	
    return (array);
}

int	*normalize_input(char **argv, int size)
{
	int		i;
	int		*original;
	int		*sorted;
	int		*normalized;
	int		j;

	original = set_to_array(argv, size);
	sorted = set_to_array(argv, size);
	normalized = set_to_array(argv, size);
	quick_sort(sorted, 0, size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (original[i] != sorted[j])
			j++;
		normalized[i] = j;
		i++;
	}
	free(original);
	free(sorted);
	return (normalized);
}
