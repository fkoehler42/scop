# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 14:13:45 by fkoehler          #+#    #+#              #
#    Updated: 2018/06/15 19:53:29 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## FILES

NAME = scop

SRC =	error.c \
		gl_objs.c \
		init.c \
		main.c \
		matrix.c \
		parse.c \
		shader.c \
		store.c \
		utils.c \
		window_events.c

vpath %.c ./src

OBJ = $(SRC:.c=.o)
O2 = $(addprefix $(OPATH), $(OBJ))

LIBFT = $(LIBFT_PATH)libft.a
LIBMAT = $(LIBMAT_PATH)libmat.a

## DIRECTORIES

OPATH = ./obj/
INC = ./include/

LIBFT_PATH = ./lib/libft/
LIBFT_INC = $(LIBFT_PATH)includes/

LIBMAT_PATH = ./lib/libmat/
LIBMAT_INC = $(LIBMAT_PATH)include/

## COMPILATION

CC = gcc
FLAGS = -Wall -Wextra -Werror
GLFW_LIB = `pkg-config --static --libs glfw3` -framework OpenGL
GLFW_INC = `pkg-config --cflags-only-I glfw3`

## PROCESS

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMAT) $(O2)
	@$(CC) $(FLAGS) $(O2) -I $(LIBFT_INC) -I $(LIBMAT_INC) -I $(INC) $(GLFW_INC) \
	-L $(LIBFT_PATH) -L $(LIBMAT_PATH) -lft -lmat $(GLFW_LIB) -o $@
	@echo "\033[0;34m$(NAME) compilation done !\033[0;m"

$(LIBFT):
	@echo "\033[0;32mPlease wait while libft is compiled...\033[0;m"
	@make -C $(LIBFT_PATH)

$(LIBMAT):
	@echo "\033[0;32mPlease wait while libmat is compiled...\033[0;m"
	@make -C $(LIBMAT_PATH)

$(OPATH)%.o: %.c
	@gcc $(FLAGS) -I $(INC) -I $(LIBFT_INC) -I $(LIBMAT_INC) $(GLFW_INC) -o $@ -c $<

clean:
	@rm -f $(O2)
	@echo "\033[0;32mObject files deleted !\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32m$(NAME) executable deleted !\033[0;m"
	-@make fclean -C $(LIBFT_PATH)
	-@make fclean -C $(LIBMAT_PATH)

re : fclean all