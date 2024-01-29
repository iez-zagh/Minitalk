/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:06:09 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/26 06:53:18 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

long	ft_atoi(char *str)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	while ((str[i]) >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res < 0)
			return (-1);
		i++;
	}
	return (res);
}

void	signal_handling(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf(GREEN_TEXT
			"Message delivered to the server successfully\n"RESET_TEXT);
		exit (0);
	}
}

void	send_signal(int pid, char char_)
{
	int	i;
	int	bit_to_send;

	i = 8;
	while (i > 0)
	{
		i--;
		bit_to_send = (char_ >> i) & 1;
		if (bit_to_send == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		usleep(400);
	}
}

int	main(int ac, char **av)
{
	long	u;
	int		i;

	signal(SIGUSR1, signal_handling);
	if (ac == 3)
	{
		u = ft_atoi(av[1]);
		if (u <= 0 || kill(u, 0) == -1)
		{
			ft_printf(RED_TEXT"bad pid process!!\n"RESET_TEXT);
			exit (EXIT_FAILURE);
		}
		ft_printf(RED_TEXT"Message is currently being sending\n"RESET_TEXT);
		i = 0;
		while (av[2][i])
			send_signal(u, av[2][i++]);
		send_signal(u, '\0');
	}
	else
		ft_printf(RED_TEXT"invalid number of arguments\n"RESET_TEXT);
	while (1)
		pause();
	return (0);
}
