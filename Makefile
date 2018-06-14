#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallois <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/13 21:48:44 by avallois          #+#    #+#              #
#    Updated: 2018/06/14 13:26:55 by adhondt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -Iinclude

NAME = lem_in

SRC_PATH = ./src
LIB_PATH = ./lib
INC_PATH = ./inc
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	 main.c \

LIB_NAME = 	ft_putchar.c ft_putstr.c ft_chardup.c ft_strdup.c \
			ft_itoa.c ft_atoi.c ft_itoa_base.c ft_memalloc.c ft_memalloc_c.c \
			ft_putnbr.c ft_strcmp.c ft_strcpy.c ft_strjoin.c ft_strjoin_f.c \
			ft_strlen.c ft_strstr.c pos_in_str.c ft_memset.c  ft_strcat.c \

INC_NAME = lem_in.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@$(CC) $(FLAGS) $(OBJ) $(OBJLIB) -o $(NAME)
	@echo "\033[1;34mpush_swap\t\033[1;33mCreation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH) $(OBJLIB)
	@echo "\033[1;34mboth\t\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;34mboth\t\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all
