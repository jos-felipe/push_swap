#include "../includes/push_swap.h"

void	push_lstprintf_cost(t_list_push *lst)
{
	int	cost_a;
	int	cost_b;
	
	while (lst)
	{
		cost_a = lst->cost_a;
		cost_b = lst->cost_b;
		ft_printf("[%d,%d] ", cost_a, cost_b);
		lst = lst->next;
	}
	ft_printf("\n");
}