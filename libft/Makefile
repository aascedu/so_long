# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 15:12:19 by aascedu           #+#    #+#              #
#    Updated: 2023/03/13 13:47:37 by aascedu          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# EFFECTS
BOLD = $'\x1b[1m
END=$'\x1b[0m
GREEN=$'\x1b[32m

SRC_DIR = ./src/

SRCS =  ft_isalnum.c ft_isascii.c ft_isprint.c ft_memmove.c ft_strlen.c ft_bzero.c \
		ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_memset.c ft_strlcpy.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
		ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_strlcat.c ft_calloc.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_print_addr.c \
		ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_str.c \
		ft_print_unbr.c ft_printf.c ft_specifier.c get_next_line.c \
		get_next_line_utils.c get_next_line_bonus.c ft_strjoin_frees1.c \

SRCS_PREFIX = $(addprefix $(SRC_DIR), $(SRCS))

HEADER = ./include/libft.h


OBJS = $(SRCS:.c=.o)
OBJS_DIR = objects/

CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra -I./include/
AR = ar
ARFLAGS = rcs

NAME = libft.a

all: $(OBJS_DIR)
	make $(NAME)

$(OBJS_DIR) :
	mkdir $(OBJS_DIR)

$(OBJS_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(addprefix $(OBJS_DIR), $(OBJS))
	$(AR) $(ARFLAGS) $(NAME) $(addprefix $(OBJS_DIR), $(OBJS))

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean
	@make all

.PHONY: all clean fclean re
