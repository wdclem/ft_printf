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

NAME = libft.a
HEAD = libft.h
# compile specs
FLAGS = -Werror -Wextra -Wall
CC = gcc
# Directories to hold .o, .h, .c
OBJ_DIR = ./object/
SRC_DIR = ./srcs/
INC_DIR = ./includes/
SRCS = ft_putchar.c ft_putchar_fd.c ft_putstr_fd.c ft_putstr.c ft_strlen.c \
	  ft_putnbr_fd.c ft_putnbr.c ft_putendl_fd.c ft_putendl.c \
	  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_tolower.c ft_toupper.c \
	  ft_atoi.c \
	  ft_isspace.c \
	  ft_memset.c ft_bzero.c \
	  ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strdup.c \
	  ft_strcat.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strlen.c \
	  ft_strnstr.c ft_strstr.c ft_strlcat.c \
	  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
	  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strsplit.c \
	  ft_strtrim.c ft_itoa.c \
	  ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstnew.c ft_lstmap.c\
	  ft_freearray.c ft_maketab.c ft_makearray.c \

OBJ = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "Lib created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INC_DIR) -o $@ -c $^

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Objects deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable deleted"

re: fclean all

.PHONY: all clean fclean re
