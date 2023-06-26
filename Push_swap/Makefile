# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 13:45:54 by vicrodri          #+#    #+#              #
#    Updated: 2023/06/06 16:17:22 by vicrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

INC			= libft/

LIBFT		= $(INC)libft.a

SOURCES	=		push_swap.c main.c sort.c stack.c init_values.c \
				move_cost.c cost.c moves.c moves2.c \
				

OBJECTS	=	$(SOURCES:.c=.o)

%.o: %.c
	@$(CC)$(FLAGS) -c $< -o $@

all: $(LIBFT)	$(NAME)

$(LIBFT):
	@make -C $(INC)

$(NAME)		: $(LIBFT) $(OBJECTS) 
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJECTS) -o $(NAME)
			@echo "$(GREEN)$(NAME) -> program created! $(DEFAULT)"

clean:
		rm -f $(OBJECTS)
		@make -C $(INC) clean
		@echo "$(YELLOW)$(NAME) -> Object files deleted. "

fclean:	clean
		rm -f $(NAME)
		@echo "$(RED)$(NAME) program -> Program and objects files deleted. "

re:	fclean all

.PHONY:	all clean fclean re 

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m