# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 09:06:15 by iez-zagh          #+#    #+#              #
#    Updated: 2024/01/18 18:50:23 by iez-zagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SOURCES1 = ft_putchar.c ft_putnbr.c ft_putstr.c ft_print_adress.c \
			ft_putnbr_uns.c ft_printf.c

SOURCES = server.c client.c

OBJS1 = ${SOURCES1:.c=.o}
OBJS = ${SOURCES:.c=.o}

all: server client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: server.o $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

client: client.o $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) $(OBJS1) server.o client.o

fclean: clean
	$(RM) server client

re: fclean all

.PHONY: clean fclean all
