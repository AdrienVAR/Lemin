CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = -I ./libft.h
NAME = libft.a
OBJECTS = $(SOURCES:.c=.o)
SOURCES =	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c	\
			ft_strnew.c	\
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar.c \
			ft_itoa.c \
			ft_putstr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c	\
			ft_sqrt.c \
			ft_pgcd.c \
			ft_iterative_power.c \
			ft_strtoupper.c \
			ft_strtolower.c \
			ft_swap.c \
			ft_print_words_table.c \
			ft_nb_digit.c \
			get_next_line.c

.PHONY: all clean fclean re

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -c $(SOURCES) $(HEADER)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

