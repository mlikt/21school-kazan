/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:08:25 by mlikt             #+#    #+#             */
/*   Updated: 2021/04/23 14:56:40 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first_p;
	t_list	*tmp;

	first_p = *lst;
	if (*lst == (void *)0)
		return ;
	while (first_p)
	{
		del(first_p->content);
		first_p->content = (void *)0;
		first_p = first_p->next;
	}
	while ((*lst))
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = (void *)0;
}
