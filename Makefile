# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 18:55:16 by kbethel           #+#    #+#              #
#    Updated: 2020/08/05 17:16:30 by kbethel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

LIB = -I libft/ -L./libft -lft

SRC =	src/ft_check.c \
		src/ft_helpers.c \
		src/ft_messages.c \
		src/ft_sort_p.c \
		src/ft_sort_r.c \
		src/ft_sort_rr.c \
		src/ft_sort_s.c \
		src/ft_sort.c \
		src/intstack.c \
		src/massort.c \
		src/noobsort.c \
		src/prosort_pbpa.c \
		src/prosort.c \

OBJ = $(SRC:.c=.o)

HEADER = -I ./header

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP):  $(OBJ)
	make -C libft/
	gcc -Wall -Wextra -Werror $(OBJ) main/push_swap.c -o $(PUSH_SWAP) $(LIB) $(HEADER)

$(CHECKER):  $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) main/checker.c -o $(CHECKER) $(LIB) $(HEADER)

clean:
	rm -rf libft/*.o
	rm -rf src/*.o

fclean: clean
	rm -rf $(PUSH_SWAP) $(CHECKER)
	rm -rf libft/libft.a

re: fclean all