/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_truncate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:37:04 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/11 13:41:42 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_truncate(long double numb)
{
	long double x;

	x = 0;
	if(x >= 0.0)
		x = ft_floor(numb);
	else
		x = ft_ceil(numb);

	return (x);
}
