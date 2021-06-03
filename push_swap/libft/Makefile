CFILE = ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_memcpy.c\
		ft_strlcpy.c\
		ft_strlen.c

OFILE = ${CFILE:.c=.o}

CFLAGS = -Wall -Wextra -Werror 
CC = gcc
NAME = libft.a
all: ${NAME} 

${NAME}: ${OFILE} libft.h 
	ar rcs ${NAME} ${OFILE}

clean:
	rm -rf ${OFILE}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY : all bonus clean fclean re

