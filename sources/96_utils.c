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

int	push_lstsize(t_list_push *lst)
{
	size_t		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}