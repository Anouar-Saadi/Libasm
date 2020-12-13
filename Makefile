# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asaadi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 12:44:58 by asaadi            #+#    #+#              #
#    Updated: 2020/12/13 12:54:00 by asaadi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

COMPIL = nasm -f macho64

LINKER = ld -macosx_version_min 10.7.0 -lSystem

AR = ar rc

RA = ranlib

SRCS = ft_strlen.s

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): 
	$(OBJ)
	$(AR) $(NAME) $(OBJS)
	$(RA) $(NAME)

%.o: %.c
	$(COMPIL) $<

clean:
	rm -rf $(OBJS)

fclean:
	rm - rf $(NAME)

re: fclean all
