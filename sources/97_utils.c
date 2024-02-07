#include "../includes/push_swap.h"

void	push_lstprintf_value(t_list_push *lst)
{
	int	value;
	
	while (lst)
	{
		value = lst->value;
		ft_printf("%d ", value);
		lst = lst->next;
	}
	ft_printf("\n");
}