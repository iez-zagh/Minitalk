/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:05:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/26 06:52:53 by iez-zagh         ###   ########.fr       */
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
		usleep(400);
	}
}

int	main(int ac, char **av)
{
	long	u;
	int		i;

	if (ac == 3)
	{
		u = ft_atoi(av[1]);
		if (u <= 0 || kill(u, 0) == -1)
		{
			ft_printf(RED_TEXT"bad process id ):\n"RESET_TEXT);
			return (1);
		}
		ft_printf(YELLOW_TEXT
			"Message is currently sending, please be patient ;)\n"RESET_TEXT);
		i = 0;
		while (av[2][i])
			send_signal(u, av[2][i++]);
	}
	else
	{
		ft_printf(RED_TEXT"invalid number of arguments\n"RESET_TEXT);
		exit (1);
	}
	ft_printf(GREEN_TEXT"DONE\n"RESET_TEXT);
	return (0);
}
