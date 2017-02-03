# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 15:53:43 by fdeclerc          #+#    #+#              #
#    Updated: 2017/02/03 10:37:01 by fdeclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_C = ./fractol.c \
		./pixel.c \
		./keyboard.c \
		./mouse.c \
		./julia.c \
		./mandelbrot.c \
		./burn.c

SRC_O = $(SRC_C:.c=.o)

SRC_H = fractol.h

SRC_A = libft/libft.a

FLAG = -Wall -Wextra -Werror

LIB = -L./libft -lft -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(SRC_O)
	make -C libft/
	gcc $(FLAG) -o $(NAME) $^ $(LIB)

%.o: %.c
	gcc $(FLAG) -I libft/includes/ -c $<

clean:
	make -C libft/ clean
	rm -f $(SRC_O)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
