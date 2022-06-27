#include "push_swap.h"

int	get_bit(int largest_number, int i)
{
	return ((largest_number >> i) & 1);
}

int	len_bits_iterator(int biggest_num)
{
	int	i;

	i = 31;
	while (get_bit(biggest_num, i) != 1)
		i--;
	return (i);
}

void	push_zero_bits(t_game *game, int bit_position)
{
	int	i;

	i = 0;
	while (i < game->len_total)
	{
		if (get_bit(game->stack_a->number, bit_position) == 0)
			push_b(game);
		else
			rotate_a(&game->stack_a);
		i++;
	}
}

void	return_nodes_to_a(t_game *game)
{
	while (game->stack_b != NULL)
		push_a(game);
}

void	radix_sort(t_game *game)
{
	int	i;
	int	bits_iterator;

	i = 0;
	bits_iterator = len_bits_iterator(game->len_total);
	while (i <= bits_iterator)
	{
		push_zero_bits(game, i);
		return_nodes_to_a(game);
		i++;
	}

}