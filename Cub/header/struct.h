#ifndef STRUCT_H
# define		STRUCT_H
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
typedef struct s_bmp_file
{
	int		h;
	int		w;
	int		fd;
	int		size;
	int		line_length;
	char	*data;
}				t_bmp_file;

typedef struct s_kye
{
	int	W;
	int	S;
	int	A;
	int	D;
	int	left;
	int	rigth;
	int	esc;
	int	start;
}				t_key;

typedef struct s_img
{
	void	*img;
	int		bits;
	int		len;
	char	*addr;
	int		e;
	int		w;
	int		h;
}	t_img;

typedef struct s_sprite
{
	double	x;
	double	y;
	t_img	*img;
	int		amount;
}	t_sprite;

typedef struct s_check
{
	int	R;
	int	NO;
	int	SO;
	int	WE;
	int	EA;
	int	S;
	int	F;
	int	C;
}				t_check;

typedef struct s_info
{
	int			*R;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	int			F;
	int			C;
	char		**map;
	char		**map2;
	double		*cd;
	t_sprite	**sprite;
}				t_info;

typedef struct s_coordinate
{
	double	PosX;
	double	PosY;
	double	DirX;
	double	DirY;
	double	planeX;
	double	planeY;
}				t_crd;

typedef struct s_win
{
	int	width;
	int	height;
}				t_win;

typedef struct s_session
{
	void	*mlx;
	void	*win_ptr;
	t_key	key;
	t_img	NO;
	t_img	SO;
	t_img	WE;
	t_img	EA;
	t_img	S;
	t_img	img;
	t_win	*win;
	t_crd	coord;
	t_info	*info;
	int		screen;
}			t_session;

typedef struct s_dataRay
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	double	sideDistX;
	double	sideDistY;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	double	WallX;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
}			t_dataRay;

typedef struct s_for_sort
{
	int		order;
	double	dist;
}		t_for_sort;

typedef struct s_data_sp
{
	double	spX;
	double	spY;
	double	invDet;
	double	trX;
	double	trY;
	int		spriteScreenX;
	int		spriteHeight;
	int		spW;
	int		drawStartX;
	int		drawEndX;
	int		drawStartY;
	int		drawEndY;
	int		texX;
	int		texY;
	double	*buf;
	int		**l;
	t_img	*text;
}				t_data_sp;
#endif