#include <stdio.h>

void	swap(double *a, double *b)
{
	double	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	comb_sort(double *arr, int count)
{
	double	factor;
	int		step;
	int		i;

	factor = 1.2473309;
	step = count - 1;
	while (step >= 1)
	{
		i = 0;
		while ((i + step) < count)
		{
			if(arr[i] > arr[i + step])
				swap(&arr[i], &arr[i + step]);
			i++;
		}
		step /= factor;
	}
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
	int		i = 0;
	double	c[7] = {3.1, 2, 1, 4, 5, 6, 0};

	print_arr(c, 7);
	comb_sort(c, 7);
	print_arr(c, 7);
	return (0);
}