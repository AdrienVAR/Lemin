NAME = lem-in
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
SRC_DIR = src/
LIB_DIR = includes/libft/

SRC_FILES = main.c			\
			print_utils.c	\
			lem_in.c		\
			parsing_utils.c \
			room.c			\
			edge.c			\
			anthill.c		\
			graph.c			\
			algo.c			\
			algo_utils.c	\
			queue.c			\
			ant.c			\
			bfs.c			\
			print.c			\
			garbage_collector.c	

INC_FILES = $(shell find includes -regex ".\{1,200\}\.h" | xargs) \
			$(shell find includes/libft -regex ".\{1,200\}\.h" | xargs)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C includes/libft/
	$(CC) $(FLAGS) -Lincludes/libft -lft -o $@ $^
	make -C checker/

%.o: %.c $(INC_FILES)
	$(CC) $(FLAGS) -I includes/libft -o $@ -c $<

clean:
	make -C includes/libft clean
	make -C checker/ clean
	rm -f $(OBJ)

fclean: clean
	make -C includes/libft fclean
	make -C checker/ fclean
	rm -f $(NAME)

re: fclean all
