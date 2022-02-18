# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:30:19 by dvallien          #+#    #+#              #
#    Updated: 2022/02/04 15:11:41 by dvallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS= ft_isalnum.c		\
	  ft_isprint.c		\
	  ft_memmove.c		\
	  ft_strlcat.c		\
	  ft_strnstr.c		\
	  ft_atoi.c			\
	  ft_isalpha.c		\
	  ft_memchr.c		\
	  ft_memset.c		\
	  ft_strlcpy.c		\
	  ft_strrchr.c		\
	  ft_bzero.c		\
	  ft_isascii.c		\
	  ft_memcmp.c		\
	  ft_strchr.c		\
	  ft_strlen.c		\
	  ft_strlen2d.c		\
	  ft_tolower.c		\
	  ft_calloc.c		\
	  ft_isdigit.c		\
	  ft_memcpy.c		\
	  ft_strdup.c		\
	  ft_strncmp.c		\
	  ft_toupper.c		\
	  ft_strjoin.c		\
	  ft_strtrim.c		\
	  ft_split.c		\
	  ft_itoa.c			\
	  ft_strmapi.c		\
	  ft_striteri.c		\
	  ft_putchar_fd.c	\
	  ft_putstr_fd.c	\
	  ft_putendl_fd.c	\
	  ft_putnbr_fd.c	\
	  ft_substr.c		\
	  ft_lstnew.c		\
	  ft_lstadd_front.c	\
	  ft_lstsize.c		\
	  ft_lstlast.c		\
	  ft_lstadd_back.c	\
	  ft_lstdelone.c	\
	  ft_lstclear.c		\
	  ft_lstiter.c		\
	  ft_lstmap.c		\
	  get_next_line.c	\
	  get_next_line_utils.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCS = libft.h

OBJS = $(SRCS:.c=.o)

NAME = libft.a

all : $(NAME)

$(NAME)	: $(OBJS)
		ar rcs $@ $(OBJS)

%.o : %.c $(INCS)
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
