CFILE = main.c\
		get_path.c\
		find_path.c\
		valid_argv.c\
		error_arg.c\
		init_list_cmds.c

OFILE = ${CFILE:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = pipex
HEADER = pipex.h
LIB_DR = ./libft
LIB = ./libft/libft.a

%.o:		%.c ${HEADER}
		@$(CC) $(CFLAGS) -c -o $@ $<

all: ${NAME} 

${NAME}: ${OFILE} 
	${MAKE} -C ${LIB_DR}
	gcc  ${OFILE} -o ${NAME} ${LIB}
clean:
	${MAKE} clean -C ${LIB_DR}
	rm -rf ${OFILE}
fclean:
	${MAKE} fclean -C ${LIB_DR}
	rm -rf ${NAME} ${OFILE}

re: fclean all

.PHONY : all clean fclean re