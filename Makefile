# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etavera- <etavera-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 08:24:14 by etavera-          #+#    #+#              #
#    Updated: 2023/02/13 08:27:36 by etavera-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
LIBFT_DIR		=	libft
LIBFT			=	$(LIBFT_DIR)/libft.a
CC				= 	cc
CFLAGS			= 	-Wall -Wextra -Werror

SRC			=	libftprintf.c

OBJS			=	$(SRCS:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(LIBFT) $(OBJS)
					cp $(LIBFT) $(NAME)
					ar -rcs $(NAME) $(OBJS)

$(LIBFT)		:
					make -C $(LIBFT_DIR) all

$(OBJ)			:	$(SRC)

clean			:
					$(RM) $(OBJS)

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean $(NAME)

.PHONY			:	all clean fclean re bonus

