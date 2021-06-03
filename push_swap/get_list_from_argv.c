#include "push_swap.h"

int	get_size_split(char **arr_c)
{
	int	i;

	i = 0;
	while (arr_c[i])
		i++;
	return (i);
}

int	*get_arr(char **arr_c)
{
	int	amount;
	int	i;
	int	*arr;

	amount = get_size_split(arr_c);
	arr = (int *)ft_calloc(amount, sizeof(int));
	i = 0;
	while (i < amount)
	{
		arr[i] = ft_atoi(arr_c[i]);
		i++;
	}
	return (arr);
}

int	*get_arr_argv(char **argv, int argc)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)ft_calloc(argc, sizeof(int));
	while (i < argc - 1)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arr);
}

void	free_split(char **arr_c)
{
	int	amount;
	int	i;

	amount = get_size_split(arr_c);
	i = 0;
	while (i < amount)
	{
		free(arr_c[i]);
		i++;
	}
	free(arr_c);
}

t_list	*get_list_from_argv(char *argv)
{
	char		**arr_c;
	int			*arr;
	int			amount;
	t_list		*list;

	list = NULL;
	arr_c = ft_split(argv, ' ');
	arr = get_arr(arr_c);
	amount = get_size_split(arr_c);
	list = new_list(arr, amount);
	free_split(arr_c);
	free(arr);
	return (list);
}
