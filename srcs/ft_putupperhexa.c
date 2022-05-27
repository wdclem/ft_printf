/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupperhexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:28:26 by ccariou           #+#    #+#             */
/*   Updated: 2022/05/16 16:50:37 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putupperhexa(unsigned int nb)
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
