# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbodak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 15:48:37 by mbodak            #+#    #+#              #
#    Updated: 2016/12/26 15:39:05 by mbodak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRCS = main.c ft_validation.c ft_move_tetriminos.c ft_map.c ft_magic.c
LIB = libft/
OBJS = $(SRCS:.c=.o)
INCLUDES = -I $(LIB)
NAME = fillit
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIB)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) $(LIB)libft.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(MAKE) clean -C $(LIB)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIB)
	$(RM) $(NAME)

re: fclean all
