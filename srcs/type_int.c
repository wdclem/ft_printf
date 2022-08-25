/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:03:17 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/24 10:54:30 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	change_size(t_info *info, long long i)
{
	if ((ft_strcmp(info->size, "ll")) == 0)
		return (i = va_arg(info->list, long long));
	else if ((ft_strcmp(info->size, "l")) == 0)
		return (i = va_arg(info->list, long));
	else if ((ft_strcmp(info->size, "h")) == 0)
		return (i = (signed short int)va_arg(info->list, int));
	else if ((ft_strcmp(info->size, "hh")) == 0)
		return (i = (signed char)va_arg(info->list, int));
	else
		return (va_arg(info->list, int));
}

int	type_int(t_info *info)
{
	long long	i;

	i = 0;
	i = change_size(info, i);
	if (i < -9223372036854775807 || i > 9223372036854775807)
	{
		if (i < 0)
		{
			info->isneg = 1;
			convert(info, i, 10);
		}
	}
	else if (i < 0)
	{
		i *= -1;
		info->isneg = 1;
		signed_numb(info, i, 10);
	}
	else
		signed_numb(info, i, 10);
	mod_init(info);
	return (0);
}
