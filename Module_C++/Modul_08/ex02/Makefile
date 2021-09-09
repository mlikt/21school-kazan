SRC = main.cpp mutantstack.cpp
HEADER = mutantstack.hpp
OBJ = ${SRC:.cpp=.o}
# CFLAGCS = -Wall -Wextra -Werror -std='c++98'
CC = clang++
NAME = mutantstack

%.o:		%.cpp
		$(CC) $(CFLAGCS) -c -o $@ $<

all: $(NAME)

${NAME}: ${OBJ} ${HEADER}
	$(CC) $(CFLAGCS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

debug:
	$(CC) -g $(CFLAGCS) $(SRC) -o $(NAME)

re: fclean all

.PHONY : all clean fclean re