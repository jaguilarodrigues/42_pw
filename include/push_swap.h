/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 07:52:18 by jaqrodri          #+#    #+#             */
/*   Updated: 2022/06/27 07:53:18 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*previous;
}						t_node;

typedef struct s_game
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		len_total;
	int		len_a;
	int		len_b;
	int		number_max;
}				t_game;

size_t		ft_strlen(const char *s);
int			check_error(int argc, char *argv[]);
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			*normalize_input(char **argv, int size);
void		quick_sort(int *array, int start, int end);
void		*ft_calloc(size_t count, size_t size);
void		*ft_bzero(void *b, size_t n);
void		*ft_memset(void *ptr, int x, size_t n);
void		print_stack(t_node *stack, int len);
void		set_stack(t_game *game, int *normalized);
void		start_game(t_game *game, int argc);
void		connect_nodes(t_node *first, t_node *second);
void		sort_stack(t_game *game);
void		radix_sort(t_game *game);
void		push_a(t_game	*game);
void		push_b(t_game	*game);
t_node		*pop_node(t_node **stack);
void		push_node(t_node *pop, t_node **stack);
void		ft_putstr_fd(char *s, int fd);
void		rotate_a(t_node **stack);
void		reverse_rotate_a(t_node **stack);
int			is_ordered(t_node *stack, int len);
void		swap_a(t_node *n1, t_node *n2);
void		sort_five(t_game *game);
void		sort_three(t_game *game);

#endif