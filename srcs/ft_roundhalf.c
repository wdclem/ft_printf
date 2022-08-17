/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundhalf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:43:42 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/11 13:49:21 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_roundhalf(long double numb)
{
	long double x;

	x = 0;
	if(ft_abs(numb - ft_truncate(numb)) == 0.5)
	{
		if(!ft_divideby(ft_round(numb), 2.0))
			x = ft_round(numb) - 1.0;
		else
			x = ft_round(numb);
	else
		x = ft_round(numb);

	return r;
}
