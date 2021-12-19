# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 13:05:41 by pskytta           #+#    #+#              #
#    Updated: 2021/12/19 14:02:04 by pskytta          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
	ft_atoi.o \
	ft_bzero.c \
	ft_bzero.o \
	ft_isalnum.c \
	ft_isalnum.o \
	ft_isalpha.c \
	ft_isalpha.o \
	ft_isascii.c \
	ft_isascii.o \
	ft_isdigit.c \
	ft_isdigit.o \
	ft_isprint.c \
	ft_isprint.o \
	ft_itoa.c \
	ft_itoa.o \
	ft_memalloc.c \
	ft_memalloc.o \
	ft_memccpy.c \
	ft_memccpy.o \
	ft_memchr.c \
	ft_memchr.o \
	ft_memcmp.c \
	ft_memcmp.o \
	ft_memcpy.c \
	ft_memcpy.o \
	ft_memdel.c \
	ft_memdel.o \
	ft_memmove.c \
	ft_memmove.o \
	ft_memset.c \
	ft_memset.o \
	ft_putchar.c \
	ft_putchar.o \
	ft_putchar_fd.c \
	ft_putchar_fd.o \
	ft_putendl.c \
	ft_putendl.o \
	ft_putendl_fd.c \
	ft_putendl_fd.o \
	ft_putnbr.c \
	ft_putnbr.o \
	ft_putnbr_fd.c \
	ft_putnbr_fd.o \
	ft_putstr.c \
	ft_putstr.o \
	ft_putstr_fd.c \
	ft_putstr_fd.o \
	ft_strcat.c \
	ft_strcat.o \
	ft_strchr.c \
	ft_strchr.o \
	ft_strclr.c \
	ft_strclr.o \
	ft_strcmp.c \
	ft_strcmp.o \
	ft_strcpy.c \
	ft_strcpy.o \
	ft_strdel.c \
	ft_strdel.o \
	ft_strdup.c \
	ft_strdup.o \
	ft_strequ.c \
	ft_strequ.o \
	ft_striter.c \
	ft_striter.o \
	ft_striteri.c \
	ft_striteri.o \
	ft_strjoin.c \
	ft_strjoin.o \
	ft_strlcat.c \
	ft_strlcat.o \
	ft_strlen.c \
	ft_strlen.o \
	ft_strmap.c \
	ft_strmap.o \
	ft_strmapi.c \
	ft_strmapi.o \
	ft_strncat.c \
	ft_strncat.o \
	ft_strncmp.c \
	ft_strncmp.o \
	ft_strncpy.c \
	ft_strncpy.o \
	ft_strnequ.c \
	ft_strnequ.o \
	ft_strnew.c \
	ft_strnew.o \
	ft_strnstr.c \
	ft_strnstr.o \
	ft_strrchr.c \
	ft_strrchr.o \
	ft_strrev.c \
	ft_strrev.o \
	ft_strsplit.c \
	ft_strsplit.o \
	ft_strstr.c \
	ft_strstr.o \
	ft_strsub.c \
	ft_strsub.o \
	ft_strtrim.c \
	ft_strtrim.o \
	ft_swap.c \
	ft_swap.o \
	ft_tolower.c \
	ft_tolower.o \
	ft_toupper.c \
	ft_toupper.o \
	ft_word_count.c \
	ft_word_count.o \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
