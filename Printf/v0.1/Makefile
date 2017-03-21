# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: susivagn <susivagn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/08 16:08:11 by susivagn          #+#    #+#              #
#    Updated: 2017/03/18 15:04:26 by susivagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = print

FLAGS = -Wall-Werror-Wextra

FILE = mainik.c \
	   ft_printf.c \
	   ft_parsing.c \
	   ft_start_processing.c

LIB = ../libft/libft.a

all: $(NAME)

$(NAME):
	gcc -w -o $(NAME) $(LIB) $(FILE)

clean:
	rm -f print

re: clean all
