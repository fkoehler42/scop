# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 11:54:25 by fkoehler          #+#    #+#              #
#    Updated: 2018/06/07 17:37:33 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#SRC =

.PHONY: all clean fclean re

FLAGS = -Wall -Werror -Wextra

# DIRECTORIES
INC = ./include/
OPATH = ./obj/
vpath %.c ./src

# FILES
NAME = libmat.a
OBJ = $(SRC:.c=.o)
O2 = $(addprefix $(OPATH), $(OBJ))

# PROCESS
all: $(NAME)

$(NAME): $(O2)
	@ar rc $(NAME) $(O2)
	@ranlib $(NAME)
	@echo "\033[0;33mLibmat compilation done !\033[0;m"

$(OPATH)%.o: %.c
	@gcc $(FLAGS) -I $(INC) -c $< -o $@

clean:
	@rm -f $(O2)
	@echo "\033[0;33mLibmat object files deleted !\033[0;m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;33m$(NAME) deleted !\033[0;m"

re: fclean all
