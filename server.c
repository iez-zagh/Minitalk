/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:06:19 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/26 06:02:53 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handling(int signal, siginfo_t *info_of_pro, void *just)
{
	static int	i = 0;
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
	if (signal == SIGUSR1)
		rec_char |= 1 << (7 - i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", rec_char);
		i = 0;
		rec_char = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	ft_printf("the PID: %d\n", pid);
	ft_printf("ready to get messages :)\n");
	act.sa_sigaction = signal_handling;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, 0) == -1
		|| sigaction(SIGUSR2, &act, 0) == -1)
	{
		ft_printf("oops, some thing went !!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
