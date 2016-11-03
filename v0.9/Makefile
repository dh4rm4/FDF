#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboddez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/09 12:57:20 by kboddez           #+#    #+#              #
#    Updated: 2016/10/28 09:48:15 by kboddez          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

LIB = libfdf.a

MAIN = main.c

SRC_NAME = ft_start.c ft_graph.c ft_map.c ft_trace.c ft_check_space.c \
	ft_height.c ft_llen.c ft_do.c ft_next_height.c ft_start_coord.c \
	ft_exit.c ft_check.c $(MAIN)

GREEN = \033[33;32m
YELLOW = \033[33;33m
RED = \033[33;31m
WHITE = \033[33;37m

SRC_PATH = ./src/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

CFLAGS_MLX = -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Compilation libft\t:\t"
	@make -C ./libft re
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Compilation fdf\t:\t"
	@gcc $(CFLAGS_MLX) $(CFLAGS) $(SRC) -L ./libft -lft -o $(NAME)
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

clean:
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)Clean\t\t:\t"
	@make -C ./libft clean
	@/bin/rm -f $(OBJ)
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

fclean: clean
	@printf "$(GREEN)=$(YELLOW)=$(RED)= $(WHITE)FClean\t\t:\t"
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -f ./src/./*~
	@/bin/rm -f *~
	@/bin/rm -f ./*~
	@/bin/rm -f *#
	@echo "$(GREEN)DONE =$(YELLOW)=$(RED)="

re: fclean all
