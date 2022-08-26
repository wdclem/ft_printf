/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:02:59 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/26 19:18:00 by ccariou          ###   ########.fr       */
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
	int					len;
	int					limit;

	i = 0;
	i = change_size(info, i); /*make it a if */
	if (!edge_case(info, i))
		convert(info, i, 8);
	//if (i == 0 && info->precision == 0 && ft_strchr(info->flag, '#'))
	//		info->mod = ft_strjoin("0", info->mod);
	//else if (info->precision == 0 && ft_strchr(info->flag, '#'))
	//	info->precision = info->copylen + 1;
	//if (i == 0 && info->precision == 0)
	//	info->mod = ft_strnew(1);
	len = info->precision - info->copylen;
	if (len > 0)
	{
		info->mod = ft_strnew(len);
		ft_memset(info->mod, '0', len);
	}
	else
	{
		info->mod = ft_strnew(1);
//		if (
//			ft_memset(info->mod, '0', 1);
	}
	limit = len + info->copylen;
	if (ft_strchr(info->flag, '#') && limit <= info->precision && info->copy[0] != '0')
	{
		limit = ft_strlen(info->mod) + info->copylen;
		if (limit <= info->precision)
			return (1);
		else
			info->mod = ft_strjoin("0", info->mod);
	}
	//if (ft_strchr(info->flag, '#') && (limit < info->precision || limit == -6))
	/*info->copylen = (ft_strlen(info->copy));
	info->modlen = (ft_strlen(info->mod));
	if (ft_strchr(info->flag, '#') && ((info->modlen + info->copylen < info->precision) || info->precision <= 0))
	{
		if (ft_strcmp(info->copy, "0") == 0)
			return (1);
		else
			info->mod = ft_strjoin("0", info->mod);
	}*/
	return (0);
}
