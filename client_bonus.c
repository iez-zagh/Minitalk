/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:06:09 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/22 18:27:32 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handling(int signal)
{
	if (signal == SIGUSR1)
	{
		printf("Message delivered to the server successfully");
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
	int	u;
	int	i;

	signal(SIGUSR1, signal_handling);
	if (ac == 3)
	{
		u = atoi(av[1]);
		if (u <= 0)
		{
			ft_printf("bad pid process!!\n");
			exit (EXIT_FAILURE);
		}
		i = 0;
		while (av[2][i])
		{
			send_signal(u, av[2][i]);
			i++;
		}
		send_signal(u, '\0');
	}
	while (1)
		pause();
	return (0);
}