#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#define INT_MIN  -2147483648
#define INT_MAX  2147483647

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

size_t  	ft_strlen(const char *s);
void		print_stack(t_stack *stack);
int			check_error(int argc, char *argv[]);
int     	error(void);
void		free_stack(t_stack *stack);
long int	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			*normalize_input(char **argv, int size);
void		quick_sort(int *array, int start, int end);
void		*ft_calloc(size_t count, size_t size);
void		*ft_bzero(void *b, size_t n);
void		*ft_memset(void *ptr, int x, size_t n);


#endif