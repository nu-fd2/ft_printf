# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 02:37:11 by oel-mado          #+#    #+#              #
#    Updated: 2024/11/24 04:43:49 by oel-mado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putadr.c ft_putchar.c\
	ft_puthex.c ft_putnbr.c ft_putstr.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

main: re ${NAME}
	${CC} ${CFLAGS} main.c ${NAME} -o out

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
