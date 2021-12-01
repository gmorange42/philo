# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 13:38:06 by gmorange          #+#    #+#              #
#    Updated: 2021/11/29 13:01:36 by gmorange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=clang
CFLAGS=-Wall -Werror -Wextra -pthread
SRCS=./srcs/main.c \
	 ./srcs/utils.c \
	 ./srcs/init.c \
	 ./srcs/time.c \
	 ./srcs/actions.c \
	 ./srcs/death.c \
	 ./srcs/destroy.c


OBJS=$(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re bonus
