# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 09:06:15 by iez-zagh          #+#    #+#              #
#    Updated: 2024/01/22 18:26:06 by iez-zagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SOURCES1 = ft_putchar.c ft_putnbr.c ft_putstr.c ft_print_adress.c \
			ft_putnbr_uns.c ft_printf.c ft_bzero.c

SOURCES = server.c client.c
SOURCES2 = server_bonus.c client_bonus.c

OBJS1 = ${SOURCES1:.c=.o}
OBJS = ${SOURCES:.c=.o}
OBJS2 = ${SOURCES2:_bonus.c=_bonus.o}

all: server client

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: server.o $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

client: client.o $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

#bonus

bonus: server_bonus client_bonus

%_bonus.o: %_bonus.c
	$(CC) $(CFLAGS) -c $< -o $@

server_bonus: server_bonus.o $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

client_bonus: client_bonus.o $(OBJS1)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS) $(OBJS1) $(OBJS2) server.o client.o server_bonus.o client_bonus.o

fclean: clean
	$(RM) server client server_bonus client_bonus

re: fclean all

.PHONY: clean fclean all
