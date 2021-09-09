SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
HEDEAR = 
CFLAGCS = -Wall -Wextra -Werror -std='c++98'
CC = clang++
NAME = ABC

%.o:		%.cpp
		$(CC) $(CFLAGCS) -c -o $@ $<

all: $(NAME)

${NAME}: ${OBJ} ${HEDEAR}
	$(CC) $(CFLAGCS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

debug:
	$(CC) -g $(CFLAGCS) $(SRC) -o $(NAME)

re: fclean all

.PHONY : all clean fclean re
