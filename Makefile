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

NAME = ft_printf.a
HEAD = ft_printf.h
# compile specs
FLAGS = -Werror -Wextra -Wall
CC = gcc
# Directories to hold .o, .h, .c
OBJ_DIR = ./object/
SRC_DIR = ./srcs/
INC_DIR = ./includes/

SRCS = ft_printf.c\
	  checkers.c\
	  ft_putdigit.c ft_puthexa.c ft_putoctal.c ft_putunsigned.c ft_putupperhexa.c \
	  print_char.c print_int.c print_octal.c print_percentage.c print_str.c print_unsigned.c print_x.c print_Xcapital.c\
	  \

INC = -I ./includes ./libft/includes 
SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
LIB = ./libft/libft.a

$(NAME): $(OBJS)
	 make -s fclean -C ./libft && make -s -C ./libft
	 cp $(LIB) ./$(NAME)
	 ar rc $(NAME) $(OBJ)
	 ranlib $(NAME)

$(OBJS_DIR)%.o:	$(SRC_DIR)%.c
	 mkdir -p $(OBJ_DIR)
	 $(CC) $(FLAGS) $(INCL) -o $@ -c $<

makelibft:

clean:
	@ rm -rf $(OBJ_DIR)
	@ make -s clean -C ./libft

fclean: clean
	@ rm -f $(NAME)
	@ make -s fclean -C ./libft

re: fclean all
.PHONY: all clean fclean re
	
	@echo "Lib created"
	@echo "Executable deleted"
	@echo "Objects deleted"
