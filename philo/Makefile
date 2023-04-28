# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 11:51:22 by melsahha          #+#    #+#              #
#    Updated: 2023/04/28 13:16:07 by melsahha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT = libftprintf.a
LIBFT_DIR = ../printf/

LINK = -L. -lftprintf -lpthread
INCL = -I../include/ -I.

SRC = main.c utils.c philo.c init.c
OBJ = $(SRC:.c=.o)

#######################################

$(NAME): $(OBJ)
	make -sC $(LIBFT_DIR)
	mv  $(LIBFT_DIR)$(LIBFT) .
	$(CC) $(CFLAGS) $(OBJ) $(LINK) -o $(NAME)

all: $(NAME)

$(OBJ): %.o: %.c
	$(CC) -c $(CFLAGS) $(INCL) $< -o $@

clean:
	make -sC $(LIBFT_DIR) clean
	rm -f $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
