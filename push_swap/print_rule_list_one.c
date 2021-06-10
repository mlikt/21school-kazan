#include "push_swap.h"

void	sa(t_list **A)
{
	swap(A);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list **B)
{
	swap(B);
	ft_putendl_fd("sb", 1);
}

void	ra(t_list **A)
{
	rotate(A);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **B)
{
	rotate(B);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **A, t_list **B)
{
	rotate(A);
	rotate(B);
	ft_putendl_fd("rr", 1);
}

void	ss(t_list **A, t_list **B)
{
	swap(A);
	swap(B);
	ft_putendl_fd("ss", 1);
}