# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 20:36:25 by yolabi            #+#    #+#              #
#    Updated: 2017/11/30 18:34:24 by enunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	kift
SVRNAME		=	server
OUT 		=	-o $(NAME)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRCDIR		=	srcs/
SVRDIR		=	svrsrcs/
INCS		=	-I./includes/
LIBFT		=	includes/libs/libft.a
LIST		=	client tools log_history play_music mood say set_timer send_email roll_dice coin_flip light_control joke search parse who_are_you where_are_you command_error goodbye watch_netflix check_news
SVRLIST		=	server sphinx tools
SRCS		=	$(addsuffix .c,$(addprefix $(SRCDIR),$(LIST)))
OBJS		=	$(addsuffix .o,$(LIST))
SVRSRCS		=	$(addsuffix .c,$(addprefix $(SVRDIR),$(SVRLIST)))
SVROBJS		=	$(addsuffix .o,$(SVRLIST))
PSFLAGS		=	`pkg-config --cflags --libs pocketsphinx sphinxbase`

all: $(NAME) $(SVRNAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(INCS) $(OUT) $(PSFLAGS)

$(SVRNAME):
	mkdir -p server/
	$(CC) $(CFLAGS) $(SVRSRCS) $(LIBFT) $(INCS) -o server/server $(PSFLAGS)
	cp -r $(SVRDIR)FINAL $(SVRDIR)en-us server/

clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f $(SVROBJS)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(SERVER)
	/bin/rm -rf server
	/bin/rm -f test

re: fclean all

.PHONY: all clean fclean re
