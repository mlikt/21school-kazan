DIRECTORY:= $(shell find ./*/* -type f -name Makefile | sed 's/\/Makefile//g')
CFILE = get_map.c\
		duplicate_map.c\
		filling_spaces.c\
		what_is_it.c\
		flood_fild.c\
		validaction_map.c\
		get_information_map.c\
		get_resolution.c\
		get_identifer.c\
		get_path_img.c\
		get_color_from_file.c\
		check_struct.c\
		valid_value.c\
		get_information_file.c
OFILE = ${CFILE:.c=.o}

HEADER = ../header/cube.h
CFLAGS = -Wall -Wextra -Werror -I ${HEADER}
CC = gcc
NAME = libvalid.a

%.o:		%.c ${HEADER}
		$(CC) $(CFLAGS) -c -o $@ $<

all: ${NAME}

${NAME}: ${OFILE} ${HEADER}
	@sh -c 'for directory in ${DIRECTORY}; do make -C $$directory; done'
	@ar rcs ${NAME} ${OFILE} ./libft/libft.a ./get_next_line/libgnl.a
	@echo "Library libvalid.a collected"
clean:
	@sh -c 'for directory in ${DIRECTORY}; do make -C $$directory clean; done'
	@rm -rf ${OFILE}
	@echo "Remove objectfile"
fclean:
	@sh -c 'for directory in ${DIRECTORY}; do make -C $$directory fclean; done'
	@rm -rf ${OFILE}
	@echo "Remove object file"
re: fclean all
.PHONY : all clean fclean re