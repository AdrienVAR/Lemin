NAME = checker
CC = gcc
FLAGS = -g -Wall -Wextra -Werror
LIB_DIR = ../includes/libft/


SRC_FILES = checker.c \
			checker_utils.c \
			parser.c \
			read_output.c \
			gc_utils.c


INC_FILES = $(shell find ../includes -regex ".\{1,200\}\.h" | xargs)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(SRC_FILES:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -L ../includes/libft -lft -o $@ $^

%.o: %.c $(INC_FILES)
	$(CC) $(FLAGS) -I ../includes/libft -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
