# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 14:13:45 by fkoehler          #+#    #+#              #
#    Updated: 2018/06/04 17:16:40 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## FILES

NAME = scop

SRC =	error.c \
		init.c \
		main.c \
		parsing.c \
		store.c \
		window_events.c

vpath %.c ./src

OBJ = $(SRC:.c=.o)
O2 = $(addprefix $(OPATH), $(OBJ))

LIBFT = $(LIBFT_PATH)libft.a
GLFW = $(GLFW_PATH)src/libglfw3.a

## DIRECTORIES

OPATH = ./obj/
INC = ./include/

LIBFT_PATH = ./lib/libft/
LIBFT_INC = $(LIBFT_PATH)includes/

GLFW_PATH = ./lib/glfw/
GLFW_INC = $(GLFW_PATH)$(INC)

## COMPILATION

CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS_OPENGL = -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

## PROCESS

all: $(NAME)

$(NAME): $(LIBFT) $(GLFW) $(O2)
	@$(CC) $(FLAGS) $(FLAGS_OPENGL) $(O2) -L $(LIBFT_PATH) -L $(GLFW_PATH)src -lft -lglfw3 \
	-I $(LIBFT_INC) -I $(GLFW_INC) -I $(INC) -o $@
	@echo "\033[0;34m$(NAME) compilation done !\033[0;m"

$(LIBFT):
	@echo "\033[0;32mPlease wait while libft is compiled...\033[0;m"
	@make -C $(LIBFT_PATH)

$(GLFW):
	@echo "\033[0;32mPlease wait while glfw is compiled...\033[0;m"
	@make -C $(GLFW_PATH)

$(OPATH)%.o: %.c
	@gcc $(FLAGS) -I $(INC) -I $(LIBFT_INC) -I $(GLFW_INC) -o $@ -c $<

clean:
	@rm -f $(O2)
	@echo "\033[0;32mObject files deleted !\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;32mExecutable deleted !\033[0;m"
	-@make fclean -C $(LIBFT_PATH)
	@echo "\033[0;32mLibft cleaned.\033[0;m"
	-@make clean -C $(GLFW_PATH)
	@echo "\033[0;32mglfw.a deleted.\033[0;m"

re : fclean all