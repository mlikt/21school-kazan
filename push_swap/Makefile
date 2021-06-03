CFILE = movement.c\
		print_rule_list_one.c\
		print_rule_list_two.c\
		push_swap.c\
		list_one.c\
		list_two.c\
		get_list_from_argv.c\
		validation.c\
		sort_small_list.c\
		sort.c

OFILE = ${CFILE:.c=.o}

CFLAGS = -Wall -Wextra -Werror -I libft.h
CC = gcc
NAME = push_swap
HEADER = push_swap.h

%.o:		%.c ${HEADER}
		$(CC) $(CFLAGS) -c -o $@ $<

all: ${NAME} 

${NAME}: ${OFILE} 
	${MAKE} -C ./libft
	gcc  ${OFILE} ./libft/libft.a -o ${NAME}

clean:
	${MAKE} clean -C ./libft
	rm -rf ${OFILE}

fclean:
	${MAKE} fclean -C ./libft
	rm -rf ${NAME} ${OFILE}

re: fclean all

.PHONY : all clean fclean re

