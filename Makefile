# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 16:21:25 by mregrag           #+#    #+#              #
#    Updated: 2024/12/24 17:07:43 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
# Project names
NAME        = cube

# Compiler and flags
CC          = cc
MLX	    = -lmlx42 -lglfw -lm
CFLAGS      = -Wall -Wextra -Werror -fsanitize=address -g2
RM          = rm -f

# Headers
CUBE_H     = $(shell find ./include -name '*.h')

# Source  Files
SRCS        = $(shell find ./src -name '*.c')

# Object Files
OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

.%.o: %.c $(CUBE_H)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


