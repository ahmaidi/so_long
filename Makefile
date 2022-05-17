# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 15:57:12 by ahmaidi           #+#    #+#              #
#    Updated: 2022/05/17 16:34:07 by ahmaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc 
SRCS = ./source/detecte_error.c ./source/filling_map.c ./source/ft_strcmp.c ./source/ft_strlen.c ./source/get_next_line.c ./source/free_it.c ./source/draw_map.c ./source/position_player.c ./source/get_next_line_utils.c \
./source/chack_components.c ./source/ft_split.c ./source/ft_calloc.c ./source/ft_bzero.c ./source/error.c ./source/key_hook.c ./source/count_it.c ./source/draw.c ./source/ft_itoa.c ./source/lose.c \
./source/win.c ./source/draw_component.c ./source/rander_frame.c ./source/init.c ./source/count_collect.c\
./source/so_long.c
SRCS_B = so_long.c
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
IMLX =  user/local/include
RM = rm -f

all : $(NAME)

$(NAME): $(SRCS)
	@echo '   __________                __                             '
	@echo '  /    _____/  _____        |  |      _____   _____    _____ '
	@echo '  \_____    \ /  _  \       |  |     /  _  \ /     \  /  ____\ '
	@echo '  /         (   <_>  )      |  |____(  <_>  )    |  \/  /_/   > '
	@echo ' /________  / \_____/_______|______/ \_____/|____|  /\___    / '
	@echo '          \/       /_______/                      \/ /______/ '
	
	@$(CC) $(CFLAGS)  -I $(IMLX) $(SRCS)  -lmlx -framework OpenGL -framework AppKit -o so_long
	@echo "\033[92mExecution file Created\033[0m"

bonus : $(NAME)
fclean:
	@$(RM) $(NAME) $(BONUS)
	@echo "\033[91mExecution file deleted\033[0m"
re: fclean all

.PHONY: all fclean re