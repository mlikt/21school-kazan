#include "push_swap.h"

void	list_join(t_list **first, t_list *second)
{
	t_list	*last;

	if (*first)
	{
		last = last_elem(*first);
		last->next = second;
		second->prev = last;
	}
	else
		*first = second;
}

t_list	*get_list(int argc, char **argv, t_list *list)
{
	t_list	*tmp;
	int		i;

	tmp = NULL;
	i = 1;
	while (i < argc)
	{
		tmp = get_list_from_argv(argv[i]);
		list_join(&list, tmp);
		i++;
	}
	return (list);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}

void	push_swap(t_list **list, unsigned int count)
{
	get_order(*list);
	if (check_sort(*list, 1))
	{
		free_list(list);
		exit(0);
	}
	if (count > 5)
		sort(list);
	else
		sort_small_list(list, count);
	free_list(list);
}

int	main(int argc, char **argv)
{
	t_list			*list;
	unsigned int	count;

	list = NULL;
	if (argc == 1)
		exit(0);
	if (validation_argv(argc, argv))
	{
		list = get_list(argc, argv, list);
		count = count_elem(list);
		if (validation_list(list))
			push_swap(&list, count);
		else
			ft_putendl_fd("Error", 1);
	}
	else
		ft_putendl_fd("Error", 1);
	return (0);
}
