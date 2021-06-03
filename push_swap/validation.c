#include "push_swap.h"

int	is_valid_simbol(int c)
{
	if ((c >= '0' && c <= '9') || c == ' ' || c == '-' || c == '+')
		return (1);
	return (0);
}

int	check_str(char *str)
{
	int	i;
	int	tumb;

	i = 0;
	tumb = 0;
	if (str[i] == 0)
		return (0);
	while (str[i] != 0)
	{
		if (str[i] == '+' || str[i] == '-')
			tumb++;
		else
			tumb = 0;
		if (!is_valid_simbol(str[i]) || tumb == 2)
			return (0);
		i++;
	}
	return (1);
}

int	validation_argv(int argc, char **argv)
{
	int	i;
	int	out;

	i = 1;
	out = 0;
	while (i < argc)
	{
		out = check_str(argv[i]);
		if (!out)
			return (0);
		i++;
	}
	return (out);
}

int	validation_list(t_list *checker)
{
	t_list	*tmp;

	tmp = checker;
	while (checker)
	{
		tmp = tmp->next;
		if (tmp)
		{
			if (checker->nbr == tmp->nbr)
				return (0);
		}
		else
		{
			checker = checker->next;
			if (checker)
				tmp = checker;
		}
	}
	return (1);
}
