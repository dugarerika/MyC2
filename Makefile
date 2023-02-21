# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 08:24:14 by etavera-          #+#    #+#              #
#    Updated: 2023/02/21 12:11:41 by etavera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	printf.a
LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a
CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror

SRC				=	ft_printf.c\

OBJS			=	$(SRCS:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
					ar rcs $(NAME) $(OBJS)
					$(LIBFT) $(OBJS)
					cp $(LIBFT) $(NAME) $(OBJS)
					ar rcs $(LIBFT) $(NAME) $(OBJS)

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

