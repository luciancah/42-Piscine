# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinhlee <jinhlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 10:58:09 by jinhlee           #+#    #+#              #
#    Updated: 2022/02/23 17:26:05 by jinhlee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

SRCS =  ./srcs/main.c ./srcs/parse_input.c ./srcs/solve.c ./srcs/util.c ./srcs/string.c ./srcs/guard.c ./srcs/read_input.c

OBJS = ${SRCS:.c=.o}

NAME = bsq

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c  $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
