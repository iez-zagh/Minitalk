/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.>c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.>42.>fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 00:05:54 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/22 16:48:00 by iez-zagh         ###   ########.>fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int checker(unsigned char rec_char)
{
	if (rec_char >= 240)
		return (4);
	else if (rec_char >= 224)
		return (3);
	else if (rec_char >= 192)
		return (2);
	return (-1);
}

static unsigned char res[4];

void checker2(int *j, unsigned char rec_char, int *i, int *u)
{
	static int i1 = 0;

	// ft_printf("[[%c]]\n", rec_char);
	// if (rec_char == ' ')
	// 	ft_printf(" ");
	if (j > 0)
	{
		res[i1] = rec_char;
		i1++;
		*i = 0;
	}
	if (*j == 1)
	{
		res[i1] = '\0';
		ft_printf("%s", res);
		res[0] = '\0';
		i1 = 0;
		*i = 0;
		*j = 0;
		*u = 0;
	}
}

void check_for_char(para *my_para, unsigned char rec_char)
{
	static int	j = 0;
	static int	u = 0;


	if (u == 0)
		j = checker(rec_char);
	// ft_printf ("[[%d]]\n", j);
	if (rec_char == '\0')
		kill(my_para->client_pid, SIGUSR1);
	if (rec_char < 127 && res[0] == '\0')
	{
		ft_printf("%c", rec_char);
		my_para->array_index = 0;
	}
	if (j >= 0)
	{
		checker2(&j, rec_char, &my_para->array_index, &u);
		j--;
	}
}

void	signal_handling(int signal, siginfo_t *info_of_pro, void *just)
{
	static unsigned char rec_char;
	static para my_para = {0, 0, 0, 0, 0};

	just = NULL;
	if (!my_para.client_pid)
		my_para.client_pid = info_of_pro->si_pid;
	my_para.current_pid = info_of_pro->si_pid;
	if (my_para.current_pid != my_para.client_pid)
	{
		my_para.client_pid = my_para.current_pid;
		my_para.char_index = 0;
		ft_bzero(res);
		rec_char = 0;
		my_para.array_index = 0;
	}
	rec_char |= (signal == SIGUSR1) << (7 - my_para.char_index);
	my_para.char_index++;
	if (my_para.char_index == 8)
	{
		check_for_char(&my_para, rec_char);
		my_para.char_index = 0;
		rec_char = 0;
	}
}

int main(void)
{
	int pid;
	struct sigaction act;

	pid = getpid();
	ft_printf("the PID: %d\n", pid);
	act.sa_sigaction = signal_handling;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, 0) == -1 || sigaction(SIGUSR2, &act, 0) == -1)
	{
		perror("oops, some thing went !!");
		return (1);
	}
	while (1)
		pause();
	return (0);
}