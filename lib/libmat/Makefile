# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 11:54:25 by fkoehler          #+#    #+#              #
#    Updated: 2018/06/14 13:53:52 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FILES

NAME = libmat.a

SRC =	mat_copy.c \
		mat_mul.c \
		mat_rotate.c \
		new_mat.c \
		new_vec.c

OBJ = $(SRC:.c=.o)
O2 = $(addprefix $(OPATH), $(OBJ))

# DIRECTORIES

vpath %.c ./src
INC = ./include/
OPATH = ./obj/

# COMPILATION

CC = gcc
FLAGS = -Wall -Werror -Wextra

# PROCESS

all: $(NAME)

$(NAME): $(O2)
	@ar rc $(NAME) $(O2)
	@ranlib $(NAME)
	@echo "\033[0;33mLibmat compilation done !\033[0;m"

$(OPATH)%.o: %.c
	@$(CC) $(FLAGS) -I $(INC) -c $< -o $@

clean:
	@rm -f $(O2)
	@echo "\033[0;33mLibmat object files deleted !\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;33m$(NAME) deleted !\033[0;m"

re: fclean all

.PHONY: all clean fclean re