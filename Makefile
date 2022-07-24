# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsaeed <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/24 18:19:17 by bsaeed            #+#    #+#              #
#    Updated: 2022/07/24 18:29:41 by bsaeed           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= $(wildcard *.c)

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

NAME	= pipex

$(NAME): $(OBJ)
		 gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re:		fclean all

.PHONY:	all clean fclean re
