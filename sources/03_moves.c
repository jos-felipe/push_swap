#include "../includes/push_swap.h"

void	push_baby_moves(t_list_push **a, t_list_push **b)
{
	int	i;

	push_gateway(RRA, a, b);
	push_lstprintf_moves(*a);
	// push_gateway(RA, a, b);
	// push_gateway(SA, a, b);
	// push_lstprintf_moves(*a);
	// push_gateway(SA, a, b);
	// i = 0;
	// while (i++ < 6)
	// 	push_gateway(PB, a, b);
	// push_gateway(RB, a, b);
	// push_gateway(RRB, a, b);
	// push_gateway(SB, a, b);
	// push_gateway(SB, a, b);
	// i = 0;
	// while (i++ < 3)
	// 	push_gateway(PA, a, b);
	// push_gateway(RR, a, b);
	// push_gateway(RRR, a, b);
	// push_gateway(SS, a, b);
}

void	push_gateway(int op, t_list_push **a, t_list_push **b)
{
	if (op == SA)
		push_do_sx(a, "sa");
	else if (op == SB)
		push_do_sx(b, "sb");
	// else if (op == SS)
	// 	push_do_ss(a, b);
	// else if (op == RA)
	// 	push_do_ra(a);
	// else if (op == RB)
	// 	push_do_rb(b);
	// else if (op == RR)
	// 	push_do_rr(a, b);
	else if (op == RRA)
		push_do_rrx(a, "rra");
	// else if (op == RRB)
	// 	push_do_rrb(b);
	// else if (op == RRR)
	// 	push_do_rrr(a, b);
	// else if (op == PA)
	// 	push_do_pa(a, b);
	// else if (op == PB)
	// 	push_do_pb(a, b);
}

void	push_do_sx(t_list_push **stack, char *sx)
{
	t_list_push *node_1;
	t_list_push *node_2;
	t_list_push *node_3;

	node_1 = (*stack)->next;
	node_2 = *stack;
	node_3 = (*stack)->next->next;
	*stack = node_1;
	(*stack)->next = node_2;
	(*stack)->next->next = node_3;
	ft_printf("%s\n", sx);
}

void	push_do_rrx(t_list_push **stack, char *rrx)
{
	t_list_push *node_1;
	t_list_push *node_2;
	t_list_push *node_n;

	node_1 = push_lstlast(*stack);
	node_2 = *stack;
	node_n = push_lst_n_1(*stack);
	*stack = node_1;
	(*stack)->next = node_2;
	node_n->next = NULL;
	ft_printf("%s\n", rrx);
}

void	push_lstprintf_moves(t_list_push *lst)
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

t_list_push	*push_lst_n_1(t_list_push *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

// t_list_push	*push_lstlast(t_list_push *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }