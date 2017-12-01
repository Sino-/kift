# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yolabi <yolabi@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 20:36:25 by yolabi            #+#    #+#              #
#    Updated: 2017/11/23 20:40:27 by yolabi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	kift
S_BASE 		=	sphinxbase-5prealpha
S_POCKET	=	pocketsphinx-5prealpha
S_TRAIN		=	sphinxtrain-5prealpha
OUT 		=	-o $(NAME)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRCDIR		=	srcs/
INCS		=	-I./includes/
LIST		=	
SRCS		=	$(addsuffix .c,$(addprefix $(SRCDIR),$(LIST)))
OBJS		=	$(addsuffix .o,$(LIST))

.PHONY: all clean fclean re

all: $(NAME) $(NAME2)

$(NAME): 
	@echo "Setting up Sphinx Base..."				 	&&	sleep 1.5
	@(	cd $(S_BASE)													&&\
		chmod +x autogen.sh 	&&	./autogen.sh						&&\
		chmod +x configure		&&	./configure 						&&\
		make 					&&	make install							)
	@echo "Setting environmental variables..."			&&	sleep 1
	@(	export LD_LIBRARY_PATH=/usr/local/lib							&&\
		export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig						)
	@echo "Setting up Pocket Sphinx..."					&&	sleep 1.5
	@(	cd $(S_POCKET)													&&\
		chmod +x configure		&&	./configure							&&\
		make					&&	make install							)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f test

re: fclean all
