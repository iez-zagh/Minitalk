/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:05:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/01/29 11:20:33 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

# define RED_TEXT "\033[1;31m"
# define GREEN_TEXT "\033[1;32m"
# define YELLOW_TEXT "\033[1;33m"
# define RESET_TEXT "\033[0m"

typedef struct t_variables
{
	int				char_index;
	int				array_index;
	int				client_pid;
	unsigned char	rec_char;
	unsigned char	res[4];
}	t_var;

#endif
