#include "../includes/push_swap.h"

void	push_all_save_three(t_list_push **a, t_list_push **b)
{
	int stack_size;
	int	pushed;
	int	i;

	stack_size = push_lstsize(*a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && pushed <= stack_size / 2 && i < stack_size)
	{
		if ((*a)->index < stack_size / 2)
		{
			push_do_px(a, b, "pb");
			pushed++;
		}
		else
			push_do_rx(a, "ra");
		i++;
	}
	i = 0;
	stack_size = stack_size - pushed;
	while (i < stack_size - 3)
	{
		push_do_px(a, b, "pb");
		i++;
	}
}

void	push_tiny_sort(t_list_push **a)
{
	if ((*a)->next->index > (*a)->index && (*a)->next->index > (*a)->next->next->index)
		push_do_rrx(a, "rra");
	else if ((*a)->index > (*a)->next->index && (*a)->index > (*a)->next->next->index)
		push_do_rx(a, "ra");
	if (!push_is_sorted(*a))
		push_do_sx(a, "sa");
}