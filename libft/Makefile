# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 23:33:59 by javjimen          #+#    #+#              #
#    Updated: 2024/02/22 12:44:21 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the library
NAME		= libft.a

# Library components directories
LIBFT_DIR	= libft/
PRINTF_DIR	= ft_printf/

# List of source files
SRC_DIR		= src/

LIBFT_SRC	= $(addprefix $(LIBFT_DIR), ft_isalpha.c \
										ft_isdigit.c \
										ft_isalnum.c \
										ft_isascii.c \
										ft_isprint.c \
										ft_strlen.c \
										ft_memset.c \
										ft_bzero.c \
										ft_memcpy.c \
										ft_memmove.c \
										ft_strlcpy.c \
										ft_strlcat.c \
										ft_toupper.c \
										ft_tolower.c \
										ft_strchr.c \
										ft_strrchr.c \
										ft_strncmp.c \
										ft_memchr.c \
										ft_memcmp.c \
										ft_strnstr.c \
										ft_atoi.c \
										ft_calloc.c \
										ft_strdup.c \
										ft_substr.c \
										ft_strjoin.c \
										ft_strtrim.c \
										ft_split.c \
										ft_itoa.c \
										ft_strmapi.c \
										ft_striteri.c \
										ft_putchar_fd.c \
										ft_putstr_fd.c \
										ft_putendl_fd.c \
										ft_putnbr_fd.c \
										ft_lstnew_bonus.c \
										ft_lstadd_front_bonus.c \
										ft_lstsize_bonus.c \
										ft_lstlast_bonus.c \
										ft_lstadd_back_bonus.c \
										ft_lstdelone_bonus.c \
										ft_lstclear_bonus.c \
										ft_lstiter_bonus.c \
										ft_lstmap_bonus.c)

PRINTF_SRC	= $(addprefix $(PRINTF_DIR), ft_printf.c \
										ft_printf_utils.c \
										ft_printf_char.c \
										ft_printf_string.c \
										ft_printf_pointer.c \
										ft_printf_int.c \
										ft_printf_uint.c \
										ft_printf_hexa.c \
										ft_printf_percent.c)

SRC			= $(addprefix $(SRC_DIR), $(LIBFT_SRC) \
									  $(PRINTF_SRC))

# List of object files
OBJ_DIR		= obj/

OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# List of header files
INC_DIR		= includes/

INCLUDES	= $(addprefix $(INC_DIR), libft.h \
									  ft_printf.h)

# Compilation flags
CC			= cc
RM			= rm -rf
AR			= ar
DIR_DUP		= mkdir -p $(@D)

CFLAGS 		+= -Wall -Wextra -Werror -I includes
ARFLAGS		= -r -c -s

# Rule name protection
.PHONY:		all clean fclean re

# Make rules
all:		$(NAME)

$(NAME):	$(OBJ) $(INCLUDES)
			$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
