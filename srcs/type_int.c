/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:03:17 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/04 12:19:22 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	change_size(t_info *info, long long i)
{
	if ((ft_strcmp(info->size, "ll")) == 0)
		return(i = va_arg(info->list, long long));
	else if ((ft_strcmp(info->size, "l")) == 0)
		return(i = va_arg(info->list, long));
	else if ((ft_strcmp(info->size, "h")) == 0)
		return(i = (short)va_arg(info->list, int));
	else if ((ft_strcmp(info->size, "hh")) == 0)
		return(i = (char)va_arg(info->list, int));
	else
		return (va_arg(info->list, int));
}

int	type_int(t_info *info)
{
	long long	i;

	i = 0;
	i = change_size(info, i); /*make it a if */
	signed_numb(info, i, 10);
	mod_init(info);
//	ft_putstr(convert(info,i, 10));
	return(0);
}
