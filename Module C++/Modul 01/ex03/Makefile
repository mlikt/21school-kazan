SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = ${SRC:.cpp=.o}
CFLAGCS = -Wall -Wextra -Werror -std=c++98
CC = clang++
NAME = Violence

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
	clang++ -g $(SRC) -o $(NAME)
dclean:
	rm -rf $(NAME).dSYM
re: fclean all

.PHONY : all clean fclean re
