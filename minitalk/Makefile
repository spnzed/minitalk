# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:16:39 by aaespino          #+#    #+#              #
#    Updated: 2022/11/09 13:42:03 by aaespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
LIBFT = ./libft/libft.a

INCLUDE = includes/minitalk.h

SRC_SERVER = 	server.c
SRC_CLIENT =	client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(LIBFT) $(CLIENT) $(SERVER) $(INCLUDE)

$(SERVER): $(OBJ_SERVER)
		$(CC) $(CFLAGS) $(LIBFT) server.o -o server
		@echo $@ ready
$(CLIENT): $(OBJ_CLIENT)
		$(CC) $(CFLAGS) $(LIBFT) client.o -o client
		@echo $@ ready
$(LIBFT):
		@make -C./libft
clean:
		@make clean -C ./libft
		@$(RM) $(OBJ_SERVER)
		@$(RM) $(OBJ_CLIENT)

fclean: clean
		$(RM) $(SERVER) 
		$(RM) $(CLIENT)
		make fclean -C ./libft

re: fclean all
