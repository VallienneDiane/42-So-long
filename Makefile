# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 15:49:10 by dvallien          #+#    #+#              #
#    Updated: 2022/02/17 17:03:09 by dvallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

INCS = ./includes/so_long.h 		\

SRCS =		./srcs/main.c				\
			./srcs/ft_valid_map.c		\
			./srcs/ft_check_items.c		\
			./srcs/ft_parse_map.c		\
			./srcs/ft_print_map.c		\
			./srcs/ft_keycode.c			\
			./srcs/ft_mooves.c			\
			
SRCS_BONUS =	./srcs_bonus/main_bonus.c				\
				./srcs_bonus/ft_valid_map_bonus.c		\
				./srcs_bonus/ft_check_items_bonus.c		\
				./srcs_bonus/ft_parse_map_bonus.c		\
				./srcs_bonus/ft_print_map_bonus.c		\
				./srcs_bonus/ft_animation_bonus.c		\
				./srcs_bonus/ft_keycode_bonus.c			\
				./srcs_bonus/ft_mooves_bonus.c			\
				./srcs_bonus/ft_list_enemy_bonus.c		\

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I mlx

RM = rm -f

all : libft mlx ${NAME}

libft : 
		make -C ./libft
		
mlx : 
		make -C ./mlx

${NAME}: ${OBJS} ${LIBFT} ${MLX}
	${CC} ${OBJS} ${LIBFT} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

bonus : libft mlx ${OBJS_BONUS}
	${CC} ${OBJS_BONUS} ${LIBFT} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o: %.c ${INCS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_BONUS}
	make clean -C ./libft
	make clean -C ./mlx

fclean: clean
	${RM} ${LIBFT}
	${RM} ${MLX}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re mlx libft bonus