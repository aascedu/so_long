# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 10:09:37 by arthurasced       #+#    #+#              #
#    Updated: 2023/03/08 15:32:11 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long
OS = $(shell uname)

HEADER = so_long.h
SRCS = src/main.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -I./inc #-Wall -Werror -Wextra
RM = rm -rf

%.o : %.c ./inc/$(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all :
	make $(NAME)

mlx :
	if [ $(OS) = "Linux" ]; then\
		make -C mlx_linux;\
	else\
		make -C mlx_macos;\
	fi

$(NAME) : mlx $(OBJS)
	if [ $(OS) = "Linux" ]; then\
		$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME);\
	else\
		$(CC) $(CFLAGS) $(OBJS) -lmlx -Lmlx_macos -framework OpenGL -framework AppKit -o $(NAME);\
	fi


clean : 
	$(RM) $(OBJS)
	if [ $(OS) = "Linux" ]; then\
		make clean -C mlx_linux;\
	else\
		make clean -C mlx_macos;\
	fi

fclean :
	$(RM) $(NAME)
	make clean

re : fclean
	make all

.PHONY : all mlx clean fclean re