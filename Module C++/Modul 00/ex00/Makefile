SRC = megaphone.cpp
OBJ = ${SRC:.cpp=.o}
CFLAGCS = -Wall -Wextra -Werror
CC = clang++
NAME = megaphone

%.o:		%.cpp
		$(CC) $(CFLAGCS) -c -o $@ $<

all: $(NAME)

${NAME}: ${OBJ}
	$(CC) $(CFLAGCS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
