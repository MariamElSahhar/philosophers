# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 11:51:22 by melsahha          #+#    #+#              #
#    Updated: 2023/05/03 21:10:52 by melsahha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

LINK = -L. -lpthread
INCL = -I.

SRC = main.c utils.c utils2.c utils3.c philo.c init.c
OBJ = $(SRC:.c=.o)

#######################################

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINK) -o $(NAME)

all: $(NAME)

$(OBJ): %.o: %.c
	$(CC) -c $(CFLAGS) $(INCL) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
