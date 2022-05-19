# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:16:39 by aaespino          #+#    #+#              #
#    Updated: 2022/05/19 18:53:04 by aaespino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
SERVER = server
CLIENT = client
LIBFT = ./libft/libft.a

INCLUDE = includes/minitalk.h

SRC = 	./src/ server.c \
		./src/ client.c \

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(LIBFT) $(CLIENT) $(SERVER) $(INCLUDE)

$(SERVER): src/server.c $(INCLUDE)
		$(CC) src/server.c -o $@
		@echo $@ ready
$(CLIENT): src/client.c $(INCLUDE)
		$(CC) $(CFLAGS) src/client.c -o $@ 
		@echo $@ ready
$(LIBFT):
		@make -C./libft
clean:
		@make clean -C ./libft

fclean: clean
		rm -rf $(SERVER) $(CLIENT)
		make fclean -C ./libft

re: fclean all
