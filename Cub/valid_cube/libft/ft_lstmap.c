/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlikt <mlikt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:58:40 by mlikt             #+#    #+#             */
/*   Updated: 2021/06/19 21:14:51 by mlikt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*map;
	t_list	*l_buf;

	if (lst == (void *)0)
		return ((void *)0);
	first = ft_lstnew(f(lst->content));
	map = first;
	lst = lst->next;
	while (lst)
	{
		l_buf = ft_lstnew(f(lst->content));
		first->next = l_buf;
		first = first->next;
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	return (map);
}
