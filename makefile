# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 16:23:30 by trlevequ          #+#    #+#              #
#    Updated: 2018/12/13 15:59:34 by trlevequ         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	libftprintf.a
CPPFLAGS	=	-Iincludes
INC_PATH	=	includes/
LIB			=	

SRC_PATH	=	srcs/


SRC_NAME	=	ft_printf.c		\
				ft_putchar.c	\
				ft_putnchar.c	\
				ft_putstr.c		\
				ft_putnstr.c	\
				ft_strlen.c		\
				ft_itoa.c		\
				ft_char_itoa.c	\
				ft_short_itoa.c	\
				ft_float.c		\
				ft_float1.c		\
				ft_float2.c		\
				ft_atoi.c		\
				ft_char_to_str.c\
				ft_fill_data1.c	\
				ft_fill_data2.c	\
				ft_param_size.c	\
				ft_print_param.c\
				ft_check_flag.c	\
				ft_parser.c		\
				ft_get_size.c	\
				ft_usage.c		\
				ft_convert_base.c

OBJ_PATH	=	objs/

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY:	all, clean, fclean, re, norme
