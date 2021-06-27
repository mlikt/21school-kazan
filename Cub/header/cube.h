#ifndef CUBE_H
# define		CUBE_H
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "valid_map.h"

void	init_win_size(t_win *win, int length, int width);
void	init_session(t_session *mlx, t_win *win, int fd);
void	init_coord_position(t_crd *coord, double posX, double posY);
void	init_coord_direction(t_crd *coord, double DirX, double DirY);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	line(t_img *img, int *coord, int color);
void	init_img(t_img *img, t_session *mlx);
void	get_rayDir_deltaDist(t_crd *coord, int x, t_dataRay *data, t_win *win);
void	get_sideDist(t_crd *coord, t_dataRay *data);
void	DDA_algorithm(t_dataRay *data, char **map);
void	get_perpWallDist(t_crd *coord, t_dataRay *data, double *buf, int x);
void	get_lineHeight(t_win *win, t_dataRay *data);
int		get_color_channel(t_img *img, int x, int y, int i);
int		get_color(t_img *img, int x, int y);
void	apply_pixel(t_img *img, int x, int y, int color);
void	get_texX(t_dataRay *data, t_win *win, t_img *img);
void	draw_line_tex(t_img *img, t_img *texture, int x, t_dataRay *data);
void	NO_and_SO(t_session *mlx, t_dataRay *data, int x, t_img *img);
void	WE_and_EA(t_session *mlx, t_dataRay *data, int x, t_img *img);
void	draw_walls(t_session *mlx, t_dataRay *data, int x, t_img *img);
void	this_is_rendering(t_session *mlx, t_dataRay *data, int x, double *buf);
void	draw_walls(t_session *mlx, t_dataRay *data, int x, t_img *img);
void	draw_roof_and_floor(t_dataRay *data, t_img *img, int x, t_session *mlx);
void	add_texture(t_session *mlx);
t_img	*init_texture(t_session *mlx, t_img *img, char *path);
void	draw_sprites(double *buf, t_session *mlx, t_img *img);
void	init_ord_dist(t_crd *crd, int *order, double *dis, t_sprite **sp);
void	sortSprites(int *order, double *dist, int amount);
void	*get_dynamic_array(unsigned int i, int amount);
int		**get_matrix(int h, int w);
void	free_matrix(int **l, int w);
void	draw_line_sp(t_img *img, t_data_sp *sp, t_win *win, int stripe);
void	go_forward_or_backward(int S, int W, char **map, t_crd *crd);
void	turn_right_or_left(int left, int right, t_crd *crd);
void	go_right_or_left(int A, int D, char **map, t_crd *crd);
int		button_press(int keycode, t_session *mlx);
int		button_unpress(int keycode, t_session *mlx);
void	change_coord(t_session *mlx);
int		exit_win(void);
int		get_size_img_bmp(int w, int h);
void	create_header_bmp(char *buf, int size, int w, int h);
char	*create_bmp(unsigned int w, unsigned int h);
void	draw_pix_bmp(int x, int y, t_bmp_file *img, unsigned int color);
void	init_bmp_file(t_bmp_file *file, int h, int w);
void	output_file_bmp(t_bmp_file *file);
void	printscreen(t_img *img);
#endif