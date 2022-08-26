/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:53:11 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/26 17:20:11 by ccariou          ###   ########.fr       */
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

static void	fractional_part(t_info *info, long double after_dot)
{
	char			*str;
	unsigned int	i;

	if (info->precision == 0 && ft_strstr(info->flag, "#"))
	{
		info->copy = ft_strjoin(info->copy, ".");
		return ;
	}
	else if (!info->precision)
		return ;
//	if (info->precision ==  -6)
//		info->precision = 6;
	i = info->precision;
	str = ft_strnew(i + 1);
	str[0] = '.';
//	after_dot = round(after_dot, info->precision);
	while (i > 0)
	{
		after_dot *= 10.0;
		str[info->precision + 1 - i] = ((int)after_dot % 10) + '0';
		i--;
		after_dot -= (int)(after_dot);
	}
	info->copy = ft_strjoin(info->copy, str);
	ft_strdel(&str);
}

void	build_float(t_info *info, long double numb)
{
	long		before_dot;
	long double	after_dot;

	if (info->precision < 0)
		info->precision = 6;
	numb = round(numb, info->precision);
	before_dot = (long)numb;
	after_dot = numb - (long double)before_dot;
	signed_numb(info, before_dot, 10);
	fractional_part(info, after_dot);
}

static long double	change_size(t_info *info, long double i)
{
	if ((ft_strcmp(info->size, "L")) == 0)
		return (i = va_arg(info->list, long double));
	else
		return (va_arg(info->list, double));
}

int	type_f(t_info *info)
{
	long double	i;

	i = 0;
	i = change_size(info, i);
	if (i < 0)
	{
		info->isneg = 1;
		i *= -1;
	}
	build_float(info, i);
	info->copylen = ft_strlen(info->copy);
	if (info->isneg == 1)
		info->mod[0] = '-';
	else if (ft_strchr(info->flag, '+'))
		info->mod[0] = '+';
	else if (ft_strchr(info->flag, ' '))
		info->mod[0] = ' ';
	return (0);
}
