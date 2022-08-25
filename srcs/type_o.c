/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:02:59 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/25 11:20:57 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	change_size(t_info *info, unsigned long long i)
{
	if ((ft_strcmp(info->size, "ll")) == 0)
		return (i = va_arg(info->list, unsigned long long));
	else if ((ft_strcmp(info->size, "l")) == 0)
		return (i = va_arg(info->list, unsigned long));
	else if ((ft_strcmp(info->size, "h")) == 0)
		return (i = (unsigned short int)va_arg(info->list, unsigned int));
	else if ((ft_strcmp(info->size, "hh")) == 0)
		return (i = (unsigned char)va_arg(info->list, unsigned int));
	else
		return (va_arg(info->list, unsigned int));
}

int	type_o(t_info *info)
{
	unsigned long long	i;

	i = 0;
	i = change_size(info, i); /*make it a if */
	convert(info, i, 8);
	mod_init(info);
	info->copylen = (ft_strlen(info->copy));
	info->modlen = (ft_strlen(info->mod));
	if (ft_strchr(info->flag, '#') && ((info->modlen + info->copylen < info->precision) || info->precision <= 0))
	{
		if (ft_strcmp(info->copy, "0") == 0)
			return (1);
		else
			info->mod = ft_strjoin("0", info->mod);
	}
//	ft_putstr(convert(info,i, 10));
	return (0);
}
