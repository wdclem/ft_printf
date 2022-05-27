# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 11:11:33 by ccariou           #+#    #+#              #
#    Updated: 2022/05/27 11:38:46 by ccariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = libft.h
FLAG =  -Werror -Wextra -Wall
OPTION = -c -I $(HEAD) 
SRC = \
	  \
	  \
	  \

OBJ = $(SRC:%.c=%.o)

$(NAME):
	@gcc $(FLAG) $(OPTION) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
