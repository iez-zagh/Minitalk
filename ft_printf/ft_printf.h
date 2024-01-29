/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:38:00 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/26 06:38:01 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int nbr, int *len);
void	ft_putstr(const char *str, int *len);
void	ft_putnbr_base(unsigned int nbr, char symbol, int *len);
void	ft_putnbr_uns(unsigned int nbr, int *len);
void	ft_print_adress(unsigned long long nbr, int *len);

#endif
