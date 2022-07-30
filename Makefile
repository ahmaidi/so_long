# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmaidi <ahmaidi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 15:57:12 by ahmaidi           #+#    #+#              #
#    Updated: 2022/05/25 16:15:20 by ahmaidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS = so_long_bonus
CC = gcc 
SRCS = ./source/detecte_error.c ./source/filling_map.c ./source/ft_strcmp.c ./source/ft_strlen.c ./source/get_next_line.c ./source/free_it.c ./source/draw_map.c ./source/position_player.c ./source/get_next_line_utils.c \
./source/chack_components.c ./source/ft_split.c ./source/ft_calloc.c ./source/ft_bzero.c ./source/error.c ./source/key_hook.c ./source/count_it.c ./source/draw.c ./source/ft_itoa.c \
./source/draw_component.c ./source/init.c ./source/count_collect.c ./source/win.c ./source/ft_putchar_fd.c ./source/ft_putstr_fd.c\
./source/so_long.c
SRCS_B = ./source_bonus/detecte_error_bonus.c ./source_bonus/filling_map_bonus.c ./source_bonus/ft_strcmp_bonus.c ./source_bonus/ft_strlen_bonus.c ./source_bonus/get_next_line_bonus.c ./source_bonus/free_it_bonus.c ./source_bonus/draw_map_bonus.c ./source_bonus/position_player_bonus.c ./source_bonus/get_next_line_utils_bonus.c \
./source_bonus/chack_components_bonus.c ./source_bonus/ft_split_bonus.c ./source_bonus/ft_calloc_bonus.c ./source_bonus/ft_bzero_bonus.c ./source_bonus/error_bonus.c ./source_bonus/key_hook_bonus.c ./source_bonus/count_it_bonus.c ./source_bonus/draw_bonus.c ./source_bonus/ft_itoa_bonus.c ./source_bonus/lose_bonus.c \
./source_bonus/win_bonus.c ./source_bonus/draw_component_bonus.c ./source_bonus/rander_frame_bonus.c ./source_bonus/init_bonus.c ./source_bonus/render_it.c ./source_bonus/count_C_N_bonus.c ./source_bonus/position_enemy_bonus.c ./source_bonus/position_coll_bonus.c\
./source_bonus/animate_enemy_bonus.c ./source_bonus/so_long_bonus.c
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

bonus : $(SRCS_B)
	@echo '   __________                __                             '
	@echo '  /    _____/  _____        |  |      _____   _____    _____ '
	@echo '  \_____    \ /  _  \       |  |     /  _  \ /     \  /  ____\ '
	@echo '  /         (   <_>  )      |  |____(  <_>  )    |  \/  /_/   > '
	@echo ' /________  / \_____/_______|______/ \_____/|____|  /\___    / '
	@echo '          \/       /_______/                      \/ /______/ '
	
	@$(CC) $(CFLAGS)  -I $(IMLX) $(SRCS_B)  -lmlx -framework OpenGL -framework AppKit -o so_long_bonus
	@echo "\033[92mExecution file Created\033[0m"
fclean:
	@$(RM) $(NAME) $(BONUS)
	@echo "\033[91mExecution file deleted\033[0m"
re: fclean all

.PHONY: all fclean re