# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 20:36:25 by yolabi            #+#    #+#              #
#    Updated: 2017/11/28 15:04:32 by yolabi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	kift
OUT 		=	-o $(NAME)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRCDIR		=	srcs/
INCS		=	-I./includes/
LIBFT		=	includes/libs/libft.a
LIST		=	main play_music say set_timer send_email roll_dice coin_flip light_control joke search parse who_are_you where_are_you
SRCS		=	$(addsuffix .c,$(addprefix $(SRCDIR),$(LIST)))
OBJS		=	$(addsuffix .o,$(LIST))

.PHONY: all clean fclean re

all: $(NAME) $(NAME2)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(INCS) $(OUT)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f test

re: fclean all
