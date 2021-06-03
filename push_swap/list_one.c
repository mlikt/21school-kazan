#include "push_swap.h"

t_list	*new_elem(int i, t_list *prev)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->nbr = i;
	list->order = ~0;
	list->next = NULL;
	list->prev = prev;
	return (list);
}

t_list	*new_list(int *arr, int amount)
{
	t_list	*list;
	t_list	*tmp;
	int		i;

	i = 0;
	list = new_elem(arr[i++], 0);
	tmp = list;
	while (i < amount)
	{
		tmp->next = new_elem(arr[i], tmp);
		tmp = tmp->next;
		i++;
	}
	return (list);
}

t_list	*duplicate(t_list *list)
{
	t_list	*out;
	t_list	*tmp;

	out = new_elem(list->nbr, 0);
	list = list->next;
	tmp = out;
	while (list)
	{
		tmp->next = new_elem(list->nbr, tmp);
		list = list->next;
		tmp = tmp->next;
	}
	return (out);
}

unsigned int	count_elem(t_list *list)
{
	int	count;

	count = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

void	remove_elem(t_list **list, unsigned int i)
{
	t_list	*tmp;

	tmp = *list;
	while (i != tmp->order)
	{
		tmp = tmp->next;
	}
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else if (tmp->next)
		*list = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	free(tmp);
}
