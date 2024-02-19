#include "../includes/push_swap.h"

void	push_cheapest_move(t_list_push *b, int *rotations)
{
	t_list_push *temp;
	int			total_cost;
	
	temp = b;
	total_cost = INT_MAX;
	while (b)
	{
		if (push_abs(b->cost_a) + push_abs(b->cost_b) < total_cost)
		{
			rotations[0] = b->cost_a;
			rotations[1] = b->cost_b;
			total_cost = push_abs(b->cost_a) + push_abs(b->cost_b);
		}
		b = b->next;
	}
}