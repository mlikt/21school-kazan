CFILE = init_rule.c\
		ft_atoi.c\
		philosophers_bonus.c\
		actions.c\
		time.c\
		ft_isdigit.c\
		valid.c

OFILE = ${CFILE:.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = philo_bonus
HEADER = philosophers_bonus.h


%.o:		%.c ${HEADER}
		@$(CC) $(CFLAGS) -c -o $@ $<

all: ${NAME} 

${NAME}: ${OFILE} 
	gcc  ${OFILE} -o ${NAME}
clean:
	rm -rf ${OFILE}
fclean:
	rm -rf ${NAME} ${OFILE}

re: fclean all

.PHONY : all clean fclean re