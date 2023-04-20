# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicrodri <vicrodri@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 12:59:48 by vicrodri          #+#    #+#              #
#    Updated: 2023/04/19 16:55:07 by vicrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
		ft_toupper.c ft_calloc.c ft_strdup.c \

OBJCS = $(FILES:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): 
	gcc $(FLAGS) -c $(FILES) -I ./
	ar rc $(NAME) $(OBJCS)

all: $(NAME)

clean:
	rm -f $(OBJCS)

fclean: clean
	rm -f $(NAME)

re: fclean all