NAME = lem-in
CC = gcc
FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
SRC_DIR = src/
LIB_DIR = includes/libft/

SRC_FILES = main.c \
			print_utils.c \
			bfs_utils.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C includes/libft/
	$(CC) $(FLAGS) -Lincludes/libft -lft -o $@ $^

%.o: %.c
	$(CC) $(FLAGS) -I includes/libft -o $@ -c $<

clean:
	make -C includes/libft clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C includes/libft fclean
	/bin/rm -f $(NAME)

re: fclean all
