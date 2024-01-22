/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:05:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/22 18:25:45 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

typedef struct parametrs
{
	int	char_index;
	int	array_index;
	int	nbit;
	int	client_pid;
	int	current_pid;

}  para;

void	ft_bzero(void *s);
int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_putstr(const char *str, int *len);
void	ft_putnbr_base(unsigned int nbr, char symbol, int *len);
void	ft_putnbr_uns(unsigned int nbr, int *len);
void	ft_print_adress(unsigned long long nbr, int *len);

#endif
