# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:19:17 by bsaeed            #+#    #+#              #
#    Updated: 2022/08/01 10:52:18 by bsaeed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= children.c ft_split.c ft_strjoin.c ft_strlen.c ft_substr.c paths.c pipex.c utils.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

NAME	= pipex

$(NAME): $(OBJ) pipex.h
		 gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re:		fclean all

.PHONY:	all clean fclean re

