# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/20 10:13:55 by jinhlee           #+#    #+#              #
#    Updated: 2022/02/20 13:20:28 by jinhlee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAG	= -Wall -Wextra -Werror
INCS	= includes
NAME	= libft.a

all : $(NAME)

.c.o:
	${CC} ${CFLAG} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

clean :
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all .c.o clean fclean re
