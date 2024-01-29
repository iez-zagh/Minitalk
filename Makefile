# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 09:06:15 by iez-zagh          #+#    #+#              #
#    Updated: 2024/01/29 11:20:29 by iez-zagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

PRINTF_PATH  = ./ft_printf
PRINTF_NAME  = ftprintf

# mandatory variables

SERVER_SOURCES = server.c
CLIENT_SOURCES = client.c

NAME = server
CLIENT_NAME = client

# bonus variables

SERVER_SOURCES_B = server_bonus.c
CLIENT_SOURCES_B = client_bonus.c

SERVER_NAME_B = server_bonus
CLIENT_NAME_B = client_bonus


SERVER_OBJS = ${SERVER_SOURCES:.c=.o}
CLIENT_OBJS = ${CLIENT_SOURCES:.c=.o}

SERVER_OBJS_B = ${SERVER_SOURCES_B:.c=.o}
CLIENT_OBJS_B = ${CLIENT_SOURCES_B:.c=.o}


all: printf $(NAME) $(CLIENT_NAME)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SERVER_OBJS)
	@$(CC) -L$(PRINTF_PATH) -lftprintf $(SERVER_OBJS) -o $(NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	@$(CC) -L$(PRINTF_PATH) -lftprintf $(CLIENT_OBJS) -o $(CLIENT_NAME)

printf: minitalk.h
		@make -C $(PRINTF_PATH)

#bonus part

bonus: printf $(SERVER_NAME_B) $(CLIENT_NAME_B)

$(SERVER_NAME_B): $(SERVER_OBJS_B)
	@$(CC) -L$(PRINTF_PATH) -l$(PRINTF_NAME) $(SERVER_OBJS_B) -o $(SERVER_NAME_B)

$(CLIENT_NAME_B): $(CLIENT_OBJS_B)
	@$(CC) -L$(PRINTF_PATH) -l$(PRINTF_NAME) $(CLIENT_OBJS_B) -o $(CLIENT_NAME_B)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_B) $(CLIENT_OBJS_B)
	@make clean -C $(PRINTF_PATH)

fclean: clean
	$(RM) $(CLIENT_NAME) $(NAME) $(CLIENT_NAME_B) $(SERVER_NAME_B)
	@make fclean -C $(PRINTF_PATH)

re: fclean all

.PHONY: clean printf
