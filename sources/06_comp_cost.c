#include "../includes/push_swap.h"

void	push_comp_cost(t_list_push *a, t_list_push *b)
{
	t_list_push *temp;
	int	lstsize_a;
	int	lstsize_b;

	lstsize_a = push_lstsize(a);
	lstsize_b = push_lstsize(b);
	temp = b;
	while (b)
	{
		if (b->position > lstsize_b / 2)
			b->cost_b = b->position - lstsize_b;
		else
			b->cost_b = b->position;
		if (b->target_pos > lstsize_a / 2)
			b->cost_a = b->target_pos - lstsize_a;
		else
			b->cost_a = b->target_pos;
		b = b->next;
	}
}