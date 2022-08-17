/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:07:08 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/11 11:10:20 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* return absolute value of a number */

long double	ft_abs(long double numb)
{
	if (numb < 0)
		return(numb *= -1);
	else
		return(numb);
}
