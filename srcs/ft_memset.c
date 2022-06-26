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