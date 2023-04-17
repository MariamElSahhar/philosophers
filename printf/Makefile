# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 16:28:04 by melsahha          #+#    #+#              #
#    Updated: 2023/04/13 17:34:33 by melsahha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBFT_DIR = ../libft/
SRC = ft_printf.c ft_putuint.c ft_putnbr.c ft_putchar.c ft_puthex.c ft_putpoint.c
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = gcc
INCL = ../include/


$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) -I$(INCL) $< -o $@

clean:
	rm -f $(OBJS) $(LIBFT)
	make -sC $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean re fclean all
