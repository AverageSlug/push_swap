# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/16 15:49:10 by marvin            #+#    #+#              #
#    Updated: 2021/03/16 15:49:10 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS_NAME	=	push_swap.c \
				ps_alt_sort.c \
				operations/p.c \
				operations/r.c \
				operations/rr.c \
				operations/s.c \
				utils/ps_utils.c \
				utils/utils.c

INC_NAME	= 	push_swap.h struct.h

SRCS		=	$(addprefix srcs/, $(SRCS_NAME))

INC			=	$(addprefix includes/, $(INC_NAME))

OBJS		= 	$(SRCS:.c=.o)

all :		$(NAME)

$(NAME) : $(OBJS) $(INC)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
			rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re:			fclean all
