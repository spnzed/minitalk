# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaespino <aaespino@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:16:39 by aaespino          #+#    #+#              #
#    Updated: 2022/05/11 17:23:00 by aaespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = server.c client.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: server client

server: server.o
		$(CC) -o $@ $<
client: client.o
		$(CC) -o $@ $<
clean:
		rm -f %(OBJ)
fclean: clean
		rm -f server client
re: fclean all
