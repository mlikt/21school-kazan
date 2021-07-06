CFILE = change_coord.c\
		create_bmp.c\
		draw_line_sp.c\
		draw_line.c\
		draw_sprite.c\
		draw_walls.c\
		draw_world.c\
		get_color.c\
		get_order_sprite.c\
		init_coord_and_session.c\
		init_image.c\
		main.c\
		output_file_bmp.c\
		this_is_rendering.c\
		where_to_go.c\
		sort_sprite.c\

OFILE = ${CFILE:.c=.o}

HEADER = ./header/cube.h
CFLAGS = -Wall -Wextra -Werror -I ${HEADER}
CC = gcc
NAME = cub3D

%.o:		%.c ${HEADER}
		$(CC) $(CFLAGS) -c -o $@ $<

all: ${NAME}

${NAME}: ${OFILE}
	${MAKE} -C ./valid_cube
	@ranlib ./valid_cube/libvalid.a ./valid_cube/libft/libft.a ./valid_cube/get_next_line/libgnl.a
	@gcc  ${OFILE} -L./valid_cube -lvalid  -L./valid_cube/libft -lft -L./valid_cube/get_next_line -lgnl -L. -lmlx -o ${NAME}
	@echo "cub3D compiled"
debug:
	gcc -g -c *.c
	gcc -g *.o  -L./valid_cube -lvalid  -L./valid_cube/libft -lft -L./valid_cube/get_next_line -lgnl -L. -lmlx ${FLAGS} -o cube
clean: 
	${MAKE} -C ./valid_cube clean;
	@rm -rf ${OFILE}
	@echo "Remove object file"

fclean:
	${MAKE} -C ./valid_cube fclean
	@rm -rf ${OFILE} ${NAME}
	@echo "Remove object file"
	@echo "Remove ${NAME} file"

re: fclean all
