/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:06:19 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/20 01:25:12 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handling(int signal, siginfo_t *info_of_pro, void *just)
{
	static int	i;
	static int	client_pid = 0;
	static int	pid;
	static char	rec_char;

	just = NULL;
	if (!client_pid)
		client_pid = info_of_pro->si_pid;
	pid = info_of_pro->si_pid;
	if (client_pid != pid)
	{
		client_pid = pid;
		i = 0;
		rec_char = 0;
	}
	rec_char |= (signal == SIGUSR1) << (7 - i);
	i++;
	if (i == 8)
	{
		if (rec_char == '\0')
			kill(client_pid, SIGUSR1);
		else
		{
			ft_printf("%c", rec_char);
			i = 0;
			rec_char = 0;
		}
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("the PID: %d\n", pid);
	act.sa_sigaction = signal_handling;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, 0) == -1
		|| sigaction(SIGUSR2, &act, 0) == -1)
	{
		perror("oops, some thing went !!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
