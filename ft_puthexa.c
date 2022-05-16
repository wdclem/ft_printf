/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:23:39 by ccariou           #+#    #+#             */
/*   Updated: 2022/05/16 17:03:16 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_puthexa(nb / 16);
		ft_puthexa(nb % 16);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}
