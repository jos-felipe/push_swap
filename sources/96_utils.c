#include "../includes/push_swap.h"

int	push_is_sorted(t_list_push *node)
{
	int	a;
	int	b;

	while (node->next)
	{
		a = node->value;
		b = node->next->value;
		if (b < a)
			return (0);
		node = node->next;
	}
	return (1);
}