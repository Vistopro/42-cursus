# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 13:55:21 by vicrodri          #+#    #+#              #
#    Updated: 2023/07/26 11:25:33 by vicrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

NAME_BONUS	= so_long_bonus

LIBFT_D		= libft/
INC_LIBFT	= -I$(LIBFT_D)
LIBFT		= $(LIBFT_D)libft.a

MLX_DIR		= MLX42/
INC_MLX		= -I$(MLX_DIR)include/MLX42 -Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"
MLX_LIB		= $(MLX_DIR)libmlx42.a -ldl -lglfw -pthread -lm
LIBMLX		= libmlx42.a

INC			= -Iinclude $(INC_LIBFT) $(INC_MLX)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRC     	= $(wildcard src/*.c)		

SRC_BONUS	= $(wildcard src_bonus/*.c)

OBJ_SRC		= $(SRC:.c=.o)

OBJ_BONUS	= $(SRC_BONUS:.c=.o)

%.o: %.c
	@$(CC)$(FLAGS) -c $< -o $@


all:	$(LIBFT) $(LIBMLX) $(NAME)

$(NAME)		: $(OBJ_SRC)
	@$(CC) $(CFLAGS) $(INC) $(MLX_LIB) $(LIBFT) $(OBJ_SRC) -o $(NAME)
	@echo "$(GREEN)$(NAME) -> program created! $(DEFAULT) "

$(LIBMLX):
	@make -C $(MLX_DIR)
	

$(LIBFT):
	@make -C $(LIBFT_D)
	@echo "$(GREEN)$(LIBMLX) -> created! $(DEFAULT) "

bonus		:  $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INC) $(MLX_LIB) $(LIBFT) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) -> program created! $(DEFAULT) "

clean		:
	@rm -f $(OBJ_SRC)
	@rm -f $(OBJ_BONUS)
	@make -C $(LIBFT_D) clean --silent
	@make -C $(MLX_DIR) clean --silent
	@echo "$(YELLOW)$(NAME) -> Object files deleted. "

fclean		: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make -C $(LIBFT_D) fclean --silent
	@make -C $(MLX_DIR) fclean --silent
	@echo "$(RED)$(NAME) program -> Program and objects files deleted. "

re			: fclean all

.PHONY		:
	all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m