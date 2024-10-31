# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 23:21:14 by javjimen          #+#    #+#              #
#    Updated: 2024/10/29 17:05:05 by javjimen         ###   ########.fr        #
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
UTILS_DIR	= utils/
CLIENT_SRC	= $(addprefix $(SRC_DIR), $(addprefix $(CLIENT_DIR), client.c))
SERVER_SRC	= $(addprefix $(SRC_DIR), $(addprefix $(SERVER_DIR), server.c))
UTILS_SRC	= $(addprefix $(SRC_DIR), $(addprefix $(UTILS_DIR), error_handler.c))
SRC			= $(CLIENT_SRC) $(SERVER_SRC) $(UTILS_SRC)
CL_BON_SRC	= $(addprefix $(SRC_DIR), $(addprefix $(CLIENT_DIR), client_bonus.c))
SR_BON_SRC	= $(addprefix $(SRC_DIR), $(addprefix $(SERVER_DIR), server_bonus.c))
UT_BON_SRC	= $(addprefix $(SRC_DIR), $(addprefix $(UTILS_DIR), error_handler_bonus.c))
BONUS_SRC	= $(CL_BON_SRC) $(SR_BON_SRC) $(UT_BON_SRC)

# List of object files
OBJ_DIR		= obj/
CLIENT_OBJ	= $(CLIENT_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
SERVER_OBJ	= $(SERVER_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
UTILS_OBJ	= $(UTILS_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
CL_BON_OBJ	= $(CL_BON_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
SR_BON_OBJ	= $(SR_BON_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
UT_BON_OBJ	= $(UT_BON_SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# List of header files
INC_DIR		= includes/
INLCUDES	= $(addprefix includes/, minitalk.h)
BONUS_INC	= $(addprefix includes/, minitalk_bonus.h)

# Compilation flags
CC			= cc
RM			= rm -rf
AR			= ar
DIR_DUP		= mkdir -p $(@D)

CFLAGS 		+= -Wall -Wextra -Werror -I includes -I libft/includes
ARFLAGS		= -r -c -s

SANITIZE	= $(CFLAGS) -fsanitize=address

# Rule name protection
.PHONY:		all libft clean fclean re sanitize bonus bonus_sanitize

all: 		$(NAME)

# Make rules
$(NAME):	$(LIBFT) $(CLIENT_OBJ) $(SERVER_OBJ) $(UTILS_OBJ) $(INLCUDES)
			$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT) $(LIBFT)
			$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER) $(LIBFT)

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

sanitize:	$(LIBFT) $(CLIENT_OBJ) $(SERVER_OBJ) $(UTILS_OBJ) $(INLCUDES)
			$(CC) $(SANITIZE) $(CLIENT_OBJ) $(UTILS_OBJ) -o $(CLIENT) $(LIBFT)
			$(CC) $(SANITIZE) $(SERVER_OBJ) $(UTILS_OBJ) -o $(SERVER) $(LIBFT)

bonus:		$(LIBFT) $(CL_BON_OBJ) $(SR_BON_OBJ) $(UT_BON_OBJ) $(BONUS_INC)
			$(CC) $(CFLAGS) $(CL_BON_OBJ) $(UT_BON_OBJ) -o $(CLIENT) $(LIBFT)
			$(CC) $(CFLAGS) $(SR_BON_OBJ) $(UT_BON_OBJ) -o $(SERVER) $(LIBFT)

bonus_sanitize:	$(LIBFT) $(CL_BON_OBJ) $(SR_BON_OBJ) $(UT_BON_OBJ) $(INLCUDES)
			$(CC) $(SANITIZE) $(CL_BON_OBJ) $(UT_BON_OBJ) -o $(CLIENT) $(LIBFT)
			$(CC) $(SANITIZE) $(SR_BON_OBJ) $(UT_BON_OBJ) -o $(SERVER) $(LIBFT)
