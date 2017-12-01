# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 20:19:44 by enunes            #+#    #+#              #
#    Updated: 2017/11/27 21:28:12 by enunes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CL = client
NAME_SVR = server
CFLAGS = -Wall -Werror -Wextra -g
SPHX_FLAGS = $(shell pkg-config --cflags --libs pocketsphinx sphinxbase)

DIR_CL = ./client/
DIR_SVR = ./server/

SRC_CL = $(DIR_CL)client.c
SRC_SVR = $(DIR_SVR)server.c sphinx.c
SRC_TOOL = tools.c

OBJ_CL = $(SRC_CL:.c=.0)
