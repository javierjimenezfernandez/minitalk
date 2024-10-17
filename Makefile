# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 23:21:14 by javjimen          #+#    #+#              #
#    Updated: 2024/10/17 14:11:23 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME		= minitalk

# File names
CLIENT		= client
SERVER		= server

# Dependancies
LIBFT_PATH	= ./libft
LIBFT		= $(LIBFT_PATH)/libft.a

# List of source files
SRC_DIR		= src/
CLIENT_DIR	= client/
SERVER_DIR	= server/
CLIENT_SRC	= $(addprefix $(SRC_DIR), $(addprefix $(CLIENT_DIR), client.c))
SERVER_SRC	= $(addprefix $(SRC_DIR), $(addprefix $(SERVER_DIR), server.c))
SRC			= $(CLIENT_SRC) $(SERVER_SRC)

# List of object files
OBJ_DIR		= obj/
CLIENT_OBJ	= $(CLIENT_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
SERVER_OBJ	= $(SERVER_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# List of header files
INC_DIR		= includes/
INLCUDES	= $(addprefix includes/, minitalk.h)

# Compilation flags
CC			= cc
RM			= rm -rf
AR			= ar
DIR_DUP		= mkdir -p $(@D)

CFLAGS 		+= -Wall -Wextra -Werror -I includes -I libft/includes
ARFLAGS		= -r -c -s

SANITIZE	= $(CFLAGS) -fsanitize=address

# Rule name protection
.PHONY:		all libft clean fclean re bonus sanitize bonus_sanitize

all: 		$(NAME)

# Make rules
$(NAME):	$(LIBFT) $(CLIENT_OBJ) $(SERVER_OBJ) $(INLCUDES)
			$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT) $(LIBFT)
			$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER) $(LIBFT)

$(LIBFT):
			make -C $(LIBFT_PATH) all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			make -C $(LIBFT_PATH) clean
			$(RM) $(OBJ_DIR)

fclean:		clean
			make -C $(LIBFT_PATH) fclean
			$(RM) $(CLIENT)
			$(RM) $(SERVER)

re:			fclean all

sanitize:	$(LIBFT) $(CLIENT_OBJ) $(SERVER_OBJ) $(INLCUDES)
			$(CC) $(SANITIZE) $(CLIENT_OBJ) -o $(CLIENT) $(LIBFT)
			$(CC) $(SANITIZE) $(SERVER_OBJ) -o $(SERVER) $(LIBFT)
