/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:56:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2023/11/29 09:24:04 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_adress(unsigned long long nbr, int *len)
{
	char				*base;
	unsigned long long	b_len;

	b_len = 16;
	base = "0123456789abcdef";
	if (nbr < b_len)
		ft_putchar(base[nbr], len);
	else
	{
		ft_print_adress(nbr / b_len, len);
		ft_print_adress(nbr % b_len, len);
	}
}
