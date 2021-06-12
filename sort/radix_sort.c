#include <stdio.h>

typedef struct s_list
{
	unsigned int	order;
	int			nbr;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

t_list	*new_elem(int i, t_list *prev)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->nbr = i;
	if (i >= 0)
		list->order = i | 0x80000000;
	else
		list->order = i & 0x7FFFFFFF;
	list->next = NULL;
	list->prev = prev;
	return (list);
}

int	check_sort(t_list *list, int direction)
{
	while (list->next)
	{
		if (direction == 1)
		{
			if (list->nbr > list->next->nbr)
				return (0);
		}
		else if (direction == -1)
		{
			if (list->nbr < list->next->nbr)
				return (0);
		}
		else
			return (-1);
		list = list->next;
	}
	return (1);
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

void	push(t_list **rec, t_list **src)
{
	t_list	*buf;

	buf = *src;
	if (*src)
	{
		if ((*src)->next)
		{
			*src = (*src)->next;
			(*src)->prev = NULL;
		}
		else
			*src = NULL;
		buf->next = NULL;
		if (!*rec)
			*rec = buf;
		else
		{
			(*rec)->prev = buf;
			buf->next = *rec;
			*rec = buf;
		}
	}
}

void print_list(t_list *list)
{
	while (list)
	{
		printf("%d ", list->nbr);
		list = list->next;
	}
}

int check_emprty(t_list **list, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (list[i])
			return (0);
		i++;
	}
	return (1);
}

void init_boxs_list(t_list **arr, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		arr[i] = NULL;
		i++;
	}
}

void radix_sort(t_list **list)
{
	t_list *boxs[10];
	int i;
	int l;

	i = 0;
	l = 1;
	init_boxs_list(boxs, 10);
	while (!check_sort(*list, 1) && check_emprty(boxs, 10))
	{
		while (*list)
		{
			i = ((*list)->order / l) % 10;
			push(&boxs[i], list);
		}
		i = 9;
		while (i >= 0)
		{
			while (boxs[i])
				push(list, &boxs[i]);
			i--;
		}
		l *= 10;
	}
}

int main(void)
{
	t_list	*list;
	int		dist[10] = {64, 64, 63, 64, 0, 25, 13, 23, 1, -34};

	list = new_list(dist, 10);
	print_list(list);
	radix_sort(&list);
	printf("\n");
	print_list(list);
	return (0);
}