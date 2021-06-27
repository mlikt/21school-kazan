#include "./header/cube.h"

int	what_is_key_press(int keycode)
{
	if (keycode == 13 || keycode == 1 || keycode == 0
		|| keycode == 2 || keycode == 123 || keycode == 124
		|| keycode == 53 || keycode == 35)
		return (1);
	return (0);
}

int	button_press(int keycode, t_session *mlx)
{
	if (keycode == 13)
		mlx->key.W = 1;
	if (keycode == 1)
		mlx->key.S = 1;
	if (keycode == 0)
		mlx->key.A = 1;
	if (keycode == 2)
		mlx->key.D = 1;
	if (keycode == 123)
		mlx->key.left = 1;
	if (keycode == 124)
		mlx->key.rigth = 1;
	if (keycode == 53)
		mlx->key.esc = 1;
	mlx->key.start = what_is_key_press(keycode);
	return (0);
}

int	press_or_unpress(t_session *mlx)
{
	if (mlx->key.W || mlx->key.A || mlx->key.S
		|| mlx->key.D || mlx->key.left || mlx->key.rigth)
		return (1);
	return (0);
}

int	button_unpress(int keycode, t_session *mlx)
{
	if (keycode == 13)
		mlx->key.W = 0;
	if (keycode == 1)
		mlx->key.S = 0;
	if (keycode == 0)
		mlx->key.A = 0;
	if (keycode == 2)
		mlx->key.D = 0;
	if (keycode == 123)
		mlx->key.left = 0;
	if (keycode == 124)
		mlx->key.rigth = 0;
	if (keycode == 53)
		mlx->key.esc = 0;
	mlx->key.start = press_or_unpress(mlx);
	return (0);
}

void	change_coord(t_session *mlx)
{
	char	**map;
	t_crd	*crd;

	map = mlx->info->map2;
	crd = &mlx->coord;
	if (mlx->key.esc)
		exit (0);
	go_forward_or_backward(mlx->key.S, mlx->key.W, map, crd);
	turn_right_or_left(mlx->key.left, mlx->key.rigth, crd);
	go_right_or_left(mlx->key.A, mlx->key.D, map, crd);
}
