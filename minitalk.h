/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:05:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/18 18:52:04 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_putstr(const char *str, int *len);
void	ft_putnbr_base(unsigned int nbr, char symbol, int *len);
void	ft_putnbr_uns(unsigned int nbr, int *len);
void	ft_print_adress(unsigned long long nbr, int *len);

#endif
