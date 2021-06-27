CFILE = get_next_line_utils.c\
		get_next_line.c

OFILE = ${CFILE:.c=.o}

HEADER = ../../header/get_next_line.h
CFLAGS = -Wall -Wextra -Werror -I ${HEADER}
CC = gcc
NAME = libgnl.a

%.o:		%.c ${HEADER}
		$(CC) $(CFLAGS) -c -o $@ $<

all: ${NAME} 

${NAME}: ${OFILE} ${HEADER}
	@ar rcs ${NAME} ${OFILE}
	@echo "Library gnl.a collected"
clean:
	@rm -rf ${OFILE}
	@echo "Remove object file"

fclean:
	@rm -rf ${NAME} ${OFILE}
	@echo "Remove gnl.a"

re: fclean all

.PHONY : all clean fclean re

