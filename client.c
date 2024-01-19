/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:05:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/19 21:20:11 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handling(int signal)
{
	if (signal == SIGUSR1)
	{
		printf("Message delivered to the server successfully, lol\n");
		exit (0);
	}
}

void	send_signal(int pid, char char_)
{
	int	i;
	int	bit_to_send;

	i = 8;
	bit_to_send = char_;
	while (i > 0)
	{
		i--;
		bit_to_send = (char_ >> i) & 1;
		if (bit_to_send == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
	}
}

int	main(int ac, char **av)
{
	int	u;
	int	i;

	if (signal(SIGUSR1, signal_handling) == SIG_ERR
		|| signal(SIGUSR2, signal_handling) == SIG_ERR)
		exit (0);
	if (ac == 3)
	{
		u = atoi(av[1]);
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
