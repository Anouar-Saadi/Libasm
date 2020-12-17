# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaadi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 13:44:42 by asaadi            #+#    #+#              #
#    Updated: 2020/12/17 11:24:29 by asaadi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s	\
		ft_read.s	\
		#ft_strdup.s

OBJS = $(SRCS:.s=.o)


all: $(NAME)

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

%.o	: %.s
	nasm -f macho64 $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

main:
	gcc main.c $(NAME)

remove:
	rm a.out
