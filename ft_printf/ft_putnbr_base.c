/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:38:14 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/29 11:20:08 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(unsigned int nbr, char symbol, int *len)
{
	char			*base;
	unsigned int	b_len;

	b_len = 16;
	base = "0123456789ABCDEF";
	if (symbol == 'x')
		base = "0123456789abcdef";
	if (nbr < b_len)
		ft_putchar(base[nbr], len);
	else
	{
		ft_putnbr_base(nbr / b_len, symbol, len);
		ft_putnbr_base(nbr % b_len, symbol, len);
	}
}
