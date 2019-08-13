# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acostaz <acostaz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 16:17:52 by acostaz           #+#    #+#              #
#    Updated: 2019/07/19 11:07:44 by acostaz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -MMD

NAME = libftprintf.a

SRC_NAME = ft_atoi.c \
		   ft_bzero.c \
		   ft_isdigit.c \
		   ft_putchar.c \
		   ft_putchar_fd.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putnbr_fd.c \
		   ft_putnbrendl.c \
		   ft_putstr.c \
		   ft_putstr_fd.c \
		   ft_strcmp.c \
		   ft_strlen.c \
		   type_d.c				\
		   type_u.c				\
		   type_o.c				\
		   type_x.c				\
		   type_c.c				\
		   type_s.c				\
		   type_p.c				\
		   type_pct.c			\
		   type_f.c				\
		   utils.c				\
		   buff.c				\
		   id_utils.c			\
		   get_format.c			\
		   float_exponents.c	\
		   float_utils.c		\
		   ft_printf.c			\

SRC_DIR = src
BUILD_DIR = obj
INC_DIR = inc

OBJ = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.o))
DPD = $(addprefix $(BUILD_DIR)/,$(SRC_NAME:.c=.d))

opti:
	@$(MAKE) -j all

debug:
	@$(MAKE) opti DEBUG=yes

all: $(NAME)

$(NAME): $(OBJ) $(INC_DIR)/libft.h $(INC_DIR)/ft_printf.h
	@echo "\033[2K \033[A"
	@ar rc $(NAME) $(OBJ)
	@echo "\033[32m[$(NAME)]: compiled\033[0m"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@echo "\033[2K [$(NAME)]: Compilation of $< \033[A"
	@gcc $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)
	@echo "\033[33m[$(NAME)]: OBJ deleted\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m[$(NAME)]: deleted\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re

-include $(DPD)
