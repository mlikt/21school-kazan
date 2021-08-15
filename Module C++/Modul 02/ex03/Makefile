SRC = main.cpp Fixed.cpp Point.cpp
OBJ = ${SRC:.cpp=.o}
CFLAGCS = -Wall -Wextra -Werror -std='c++98'
CC = clang++
NAME = Fixed

%.o:		%.cpp
		$(CC) $(CFLAGCS) -c -o $@ $<

all: $(NAME)

${NAME}: ${OBJ}
	$(CC) $(CFLAGCS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

debug:
	$(CC) -g $(CFLAGCS) $(SRC) -o $(NAME)

re: fclean all

.PHONY : all clean fclean re
