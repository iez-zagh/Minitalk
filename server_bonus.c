/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:05:54 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/29 11:20:36 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bzero(unsigned char *s)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		s[i] = 0;
		i++;
	}
}

void	checker2(t_var *my_para, siginfo_t *info_of_pro)
{
	if (!my_para->client_pid)
		my_para->client_pid = info_of_pro->si_pid;
	if (info_of_pro->si_pid != my_para->client_pid)
	{
		my_para->client_pid = info_of_pro->si_pid;
		my_para->char_index = 0;
		my_para->array_index = 0;
		my_para->rec_char = 0;
		ft_bzero(my_para->res);
	}
}

void	print_unicode(t_var *my_para, siginfo_t *info_of_pro)
{
	static int	j = 0;
	int			i;

	checker2(my_para, info_of_pro);
	i = 0;
	my_para->res[my_para->array_index++] = my_para->rec_char;
	if (my_para->rec_char >= 192 && my_para->rec_char < 224)
		j = 2;
	else if (my_para->rec_char >= 224 && my_para->rec_char < 240)
		j = 3;
	else if (my_para->rec_char >= 240)
		j = 4;
	if (my_para->array_index == j)
	{
		ft_printf("%s", my_para->res);
		ft_bzero(my_para->res);
		my_para->array_index = 0;
	}
}

void	signal_handling(int signal, siginfo_t *info_of_pro, void *just)
{
	static t_var	my_para = {0, 0, 0, 0, "0000"};
	static int		u = 0;

	u++;
	just = NULL;
	checker2(&my_para, info_of_pro);
	if (signal == SIGUSR1)
		my_para.rec_char |= 1 << (7 - my_para.char_index);
	my_para.char_index++;
	if (my_para.char_index == 8)
	{
		if (my_para.rec_char == '\0')
		{
			ft_printf(YELLOW_TEXT "\n%d signal are recived\n" RESET_TEXT, u);
			u = 0;
			kill(my_para.client_pid, SIGUSR1);
		}
		else if (my_para.rec_char <= 127)
			ft_printf("%c", my_para.rec_char);
		else
			print_unicode(&my_para, info_of_pro);
		my_para.rec_char = 0;
		my_para.char_index = 0;
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
	if (sigaction(SIGUSR1, &act, 0) == -1 || sigaction(SIGUSR2, &act, 0) == -1)
	{
		ft_printf("oops, some thing went !!\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}
