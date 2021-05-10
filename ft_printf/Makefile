CFILE = ft_printf.c\
		read_flags.c\
		read_nbr.c\
		put_space_zero.c\
		behavior_dec.c\
		count_size_out.c\
		read_flags_subf.c\
		ft_uitoa.c\
		behavior_udec.c\
		behavior_hexl.c\
		ft_hexltoa.c\
		ft_hexuptoa.c\
		behavior_hexup.c\
		behavior_pointer.c\
		behavior_precent.c\
		behavior_char.c\
		behavior_string.c\
		out_list_func.c\
		out_list_func1.c\
		neg_points_and_zero.c

OFILE = ${CFILE:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libftprintf.a
HEADER = libftprintf.h ./libft/libft.h

%.o:		%.c ${HEADER}
		$(CC) $(CFLAGS) -c -o $@ $<

all: ${NAME}

${NAME}: ${OFILE}
	${MAKE} -C ./libft
	ar rcs ${NAME} ${OFILE} ./libft/*.o
clean:
	${MAKE} clean -C ./libft 
	rm -rf ${OFILE}

fclean: clean
	${MAKE} fclean -C ./libft
	rm -rf ${NAME}
re: fclean all

main: all
	gcc  -c main.c
	gcc  -o a.out ./libft/*.o *.o

.PHONY: all clean fclean re
