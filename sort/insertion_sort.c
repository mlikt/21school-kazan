#include <stdio.h>

void	swap(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	check_sort(double *arr, int count)
{
	int	i;

	i = 0;
	while (i < (count - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	insertion_sort(double *s, int n)
{
	int	i;
	int	j;

	i = 1;
	while (i < n)
	{
		j = i;
		while ((j > 0) && (s[j] < s[j - 1]))
		{
			swap(&s[j], &s[j - 1]);
			j = j - i;
		}
		i++;
	}
	if (!check_sort(s, n))
		insertion_sort(s, n - 1);
}

void	print_arr(double *arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("%.1f ", arr[i]);
		i++;
	}	
	printf("\n");
}

int	main(void)
{
	double	c[7] = {3.1, 2, 1, 4, 5, 6, 0};

	print_arr(c, 7);
	insertion_sort(c, 7);
	insertion_sort(c, 7);
	print_arr(c, 7);
	return (0);
}