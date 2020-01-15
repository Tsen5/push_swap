# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swann <swann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 12:10:35 by swann             #+#    #+#              #
#    Updated: 2020/01/13 15:22:03 by swann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
FLAG		=	-Werror -Wall -Wextra #-g3 -fsanitize=address

PTH_LIBFT	=	libft/
LIBFT		=	$(PTH_LIBFT)libft.a
LNK_LIBFT	=	-L. $(LIBFT)

SRCS		=	srcs/push_swap.c \
				srcs/moves.c \
				srcs/swap.c \
				srcs/push.c \
				srcs/rotate.c \
				srcs/tools.c \

OBJ 		=	$(SRCS:.c=.o)

PTH_INCLDS	=	includes/
INCLDS		=	-I $(PTH_LIBFT) -I $(PTH_INCLDS)tools.h -I $(PTH_INCLDS)push_swap.h

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	gcc $(FLAG) -o $@ $^ $(LNK_LIBFT)

$(LIBFT):
	make -C $(PTH_LIBFT)

%.o: %.c
	gcc $(FLAG) $(INCLDS) -c -o $@ $<

clean:
	rm -rf $(OBJ)
	make -C $(PTH_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(PTH_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re