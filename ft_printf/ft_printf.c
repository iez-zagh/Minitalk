/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:37:54 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/29 11:19:58 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char c, va_list ags1, int *len, int *k)
{
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ags1, int), len);
	else if (c == 'c')
		ft_putchar(va_arg(ags1, int), len);
	else if (c == 's')
		ft_putstr(va_arg(ags1, char *), len);
	else if (c == '%')
		ft_putchar(c, len);
	else if (c == 'x' || c == 'X')
		ft_putnbr_base(va_arg(ags1, unsigned int), c, len);
	else if (c == 'p')
	{
		ft_putstr("0x", len);
		ft_print_adress(va_arg(ags1, unsigned long long), len);
	}
	else if (c == 'u')
		ft_putnbr_uns(va_arg(ags1, unsigned int), len);
	else
		(*k)--;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ags;
	int		len;

	i = 0;
	len = 0;
	va_start(ags, str);
	if (write(1, NULL, 0) < 0)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print(str[++i], ags, &len, &i);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end (ags);
	return (len);
}
