CFILE = get_next_line_utils.c\
		get_next_line.c

OFILE = ${CFILE:.c=.o}

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=256
CC = @gcc
NAME = gnl.a
HEADER = get_next_line.h

%.o:		%.c ${HEADER}
		$(CC) $(CFLAGS) -c -o $@ $<

all: ${NAME} 

${NAME}: ${OFILE} 
	@ar rcs ${NAME} ${OFILE}
clean:
	@rm -rf ${OFILE}
	@echo "Remove object file"

fclean:
	@rm -rf ${NAME} ${OFILE}
	@echo "Remove gnl.a"

re: fclean all

.PHONY : all clean fclean re

