# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melsahha <melsahha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 11:51:22 by melsahha          #+#    #+#              #
#    Updated: 2023/05/05 16:27:11 by melsahha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g

LINK = -L. -lpthread
INCL = -I.

OBJ_DIR = obj
SRC_DIR = src/
SRC = $(addprefix $(SRC_DIR), main.c utils.c utils2.c utils3.c philo.c init.c)
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

#######################################

$(NAME): $(OBJ) $(OBJ_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LINK) -o $(NAME)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $(INCL) $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
