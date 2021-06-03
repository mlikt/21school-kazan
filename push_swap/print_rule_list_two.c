#include "push_swap.h"

void	rra(t_list **A)
{
	rotate_revers(A);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **B)
{
	rotate_revers(B);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **A, t_list **B)
{
	rotate_revers(A);
	rotate_revers(B);
	ft_putendl_fd("rrr", 1);
}

void	pa(t_list **A, t_list **B)
{
	push(A, B);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **A, t_list **B)
{
	push(B, A);
	ft_putendl_fd("pb", 1);
}
