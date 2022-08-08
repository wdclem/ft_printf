/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:01:07 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/04 12:21:03 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	change_size(t_info *info,unsigned long long i)
{
	if ((ft_strcmp(info->size, "ll")) == 0)
		return(i = va_arg(info->list, unsigned long long));
	else if ((ft_strcmp(info->size, "l")) == 0)
		return(i = va_arg(info->list, unsigned long));
	else if ((ft_strcmp(info->size, "h")) == 0)
		return(i = (unsigned short)va_arg(info->list, unsigned int));
	else if ((ft_strcmp(info->size, "hh")) == 0)
		return(i = (unsigned char)va_arg(info->list, unsigned int));
	else
		return (va_arg(info->list, int));
}

int	type_unsigned(t_info *info)
{
	unsigned long long	i;

	i = 0;
	i = change_size(info, i); /*make it a if */
	convert(info, i, 10);
	mod_init(info);
//	ft_putstr(convert(info,i, 10));
	return(0);
}
