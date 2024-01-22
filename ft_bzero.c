/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:24:24 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/22 18:25:26 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bzero(void *s)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		*((unsigned char *)(s + i)) = 0;
		i++;
	}
}
