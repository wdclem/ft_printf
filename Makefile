# **************************************************************************** # #                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 13:04:47 by ccariou           #+#    #+#              #
#    Updated: 2021/11/05 13:04:47 by ccariou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 
HEAD = ft_printf.h
# compile specs
FLAGS = -g -Werror -Wextra -Wall
CC = gcc
# Directories to hold .o, .h, .c
OBJ_DIR = ./objects/
SRC_DIR = ./srcs/
INC_DIR = ./includes/

SRCS = ft_printf.c\
	  checkers.c converter.c get_info.c\
	  type_c.c type_int.c type_o.c type_percent.c type_s.c type_u.c type_x.c type_xcap.c type_f.c type_p.c \
	  \

INC = -I ./includes -I ./libft/includes
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
LIB = ./libft/libft.a

all: $(NAME) 

$(NAME): $(OBJ)
	 make -s fclean -C ./libft && make -s -C ./libft
	 cp $(LIB) ./$(NAME)
	 ar rc $(NAME) $(OBJ)
	 ranlib $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	 mkdir -p $(OBJ_DIR)
	 $(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@ rm -rf $(OBJ)
	@ make -C ./libft clean

fclean: clean
	@ rm -f $(NAME)
	@ make  -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
