VAR:= $(shell find ./*/* -type f -name Makefile | sed 's/\/Makefile//g')

all:
	@sh -c 'for w in ${VAR}; do make -C $$w; done'
	@echo "Я запустил все найденные Makefile"
clean:
	@sh -c 'for w in ${VAR}; do make -C $$w clean; done'
fclean:
	@sh -c 'for w in ${VAR}; do make -C $$w fclean; done'
re:
	@sh -c 'for w in ${VAR}; do make -C $$w re; done'
