# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 10:09:37 by arthurasced       #+#    #+#              #
#    Updated: 2023/03/13 15:09:21 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long
OS = $(shell uname)

LIBFT = libft/libft.a
HEADER = so_long.h
SRCS = src/main.c src/parsing.c src/error.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -I./inc -Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -rf

%.o : %.c ./inc/$(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all :
	make $(NAME)

lib :
	make -C libft

mlx :
	if [ $(OS) = "Linux" ]; then\
		make -C mlx_linux;\
	else\
		make -C mlx_macos;\
	fi

$(NAME) : lib mlx $(OBJS)
	if [ $(OS) = "Linux" ]; then\
		$(CC) $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz $(LIBFT) -o $(NAME);\
	else\
		$(CC) $(CFLAGS) $(OBJS) -lmlx -Lmlx_macos -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME);\
	fi


clean : 
	$(RM) $(OBJS)
	make clean -C libft
	if [ $(OS) = "Linux" ]; then\
		make clean -C mlx_linux;\
	else\
		make clean -C mlx_macos;\
	fi

fclean :
	$(RM) $(NAME)
	make clean
	make fclean -C libft

re : fclean
	make all

norm :
	norminette ./src ./libft

.PHONY : all mlx lib clean fclean re norm