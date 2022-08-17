/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:09:02 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/11 12:10:10 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double ft_ceil(long double numb)
{
	int x;

	x = (int)numb;
	if (numb == (float)x || numb < 0)
	{
		return x;
	}
	else
		return (x + 1);
}
