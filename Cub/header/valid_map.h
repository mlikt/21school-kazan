#ifndef VALID_MAP_H
# define VALID_MAP_H
# include "struct.h"
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
int			*get_resolution(t_check *check, char **str, void *mlx);
void		print_map(char **map);
int			size_arr(char **arr);
void		copy_pointers(char **dest, char **src);
char		**add_new_line_map(int i, char **tmp, char **map, char *buf);
char		**get_map(int fd);
char		**duplicate_map(char **map);
int			find_max_lenght(char **map);
char		*filling_str_space(char *s, int size);
void		filling_map_space(char **map);
char		this_NSWE(char c);
int			this_wall_empty_sprite(char c);
int			this_replace(char c);
void		print_massege_error(int nbr_error);
int			valid_simbol_map(char **map);
double		*valid_direction_get_coord(char **map);
void		find_sprite_outfeild(char **map);
void		valid_map(char **map);
void		flood_fild(char **map, int *wh, int x, int y);
void		free_arr(char **arr_c);
double		*find_coord_and_directon(char **map);
int			count_sprite(t_sprite **sprite);
t_sprite	**get_sprite_coord(char **map, int count);
void		print_massege_error_id(int nbr_error, char *str);
int			recognize_id(char *id);
char		**get_identifer_and_data(char *line);
char		*get_path_img(t_check *check, char **str);
int			check_id(int i, t_check *check);
int			check_color(char *str);
void		confirm_check(t_check *check, int i);
int			get_color_from_file(t_check *check, char **str);
void		get_information_map(t_info *info, t_sprite ***sprite);
void		init_checker(t_check *check);
void		valid_value(char **str);
t_info		*get_information_file(int fd, void *mlx);
#endif