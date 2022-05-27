/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:16:44 by ccariou           #+#    #+#             */
/*   Updated: 2022/05/13 14:50:09 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putoctal(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putoctal(nb / 8);
		ft_putoctal(nb % 8);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}
