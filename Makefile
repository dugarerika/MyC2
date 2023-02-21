# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 08:24:14 by etavera-          #+#    #+#              #
#    Updated: 2023/02/21 11:40:16 by etavera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a
CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror

SRC				=	ft_printf.c \

OBJS			=	$(SRCS:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(OBJS)
					cp $(LIBFT) $(NAME)
					ar -rcs $(LIBFT) $(NAME) $(OBJS)

$(LIBFT)		:
					make -C $(LIBFT_DIR) all

$(OBJ)			:	$(SRC)
					$(CC) $(CFLAGS) -c $(SRC)

clean			:
					make clean -C ./libft
					rm -f $(OBJ)

fclean			:	clean
					make fclean -C ./libft
					rm -f $(NAME)

re				:	fclean all

norm			:
					norminette $(SRC)

.PHONY			:	all clean fclean re

