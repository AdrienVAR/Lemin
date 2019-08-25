NAME = checker
CC = gcc
FLAGS = -g -fsanitize=address -Wall -Wextra -Werror
SRC_DIR = ./
LIB_DIR = ../includes/libft/


SRC_FILES = checker.c \
			checker_utils.c \
			read_output.c


INC_FILES = $(shell find ../includes -regex ".\{1,200\}\.h" | xargs) \
			$(shell find ../includes/libft -regex ".\{1,200\}\.h" | xargs)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(addprefix $(SRC_DIR), $(SRC_FILES:.c=.o))

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../includes/libft/
	$(CC) $(FLAGS) -L ../includes/libft -lft -o $@ $^

%.o: %.c $(INC_FILES)
	$(CC) $(FLAGS) -I ../includes/libft -o $@ -c $<


clean:
	make -C ../includes/libft clean
	rm -f $(OBJ)

fclean: clean
	make -C ../includes/libft fclean
	rm -f $(NAME)

re: fclean all
