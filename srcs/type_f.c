/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:53:11 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/12 14:13:34 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	round(long double num, int precision)
{
	long double	extra;

	extra = 0.5;
	if (precision <= 0)
		return (num);
	while (precision--)
		extra /= 10;
	return (num + extra);
}

static void	build_fractional_part(t_info *info, long double after_dot)
{
	char			*str;
	char			*temp;
	unsigned int	i;

	if (info->precision ==  -6)
		info->precision = 6;
	if (!info->precision)
		return ;
	i = info->precision + 1;
	str = ft_strnew(info->precision + 1);
	str[0] = '.';
	after_dot = round(after_dot, info->precision);
	while (--i > 0)
	{
		after_dot *= 10.0;
		str[info->precision + 1 - i] = (int)(after_dot) + '0';
		after_dot -= (int)(after_dot);
	}
	temp = info->copy;
	info->copy = ft_strjoin(info->copy, str);
	ft_strdel(&temp);
	ft_strdel(&str);
}

void	build_float(t_info *info, long double numb)
{
	long		before_dot;
	long double	after_dot;

	before_dot = (long)numb;
	after_dot = numb - (long double)before_dot;
	if (after_dot < 0)
		after_dot *= -1;
	convert(info, before_dot, 10);
	build_fractional_part(info, after_dot);
}

static long double change_size(t_info *info, long double i)
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
		return (va_arg(info->list, double));
}

int	type_f(t_info *info)
{
	long double i;

	i = 0;
	i = change_size(info, i); /*make it a if */
	build_float(info, i);
	info->copylen = ft_strlen(info->copy);
	mod_init(info);
//	ft_putstr(convert(info,i, 10));
	return(0);
}
