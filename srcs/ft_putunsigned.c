/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 14:14:39 by ccariou           #+#    #+#             */
/*   Updated: 2022/05/13 14:49:27 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putunsigned(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_putunsigned(nb / 10);
		ft_putunsigned(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
