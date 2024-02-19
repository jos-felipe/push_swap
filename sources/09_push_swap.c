#include "../includes/push_swap.h"

void	push_swap(t_list_push **a, t_list_push **b, int *rotations)
{
	while (*b)
	{
		push_target_pos(*a, *b);
		push_comp_cost(*a, *b);
		push_cheapest_move(*b, rotations);
		push_sort(a, b, rotations);
	}
	
}