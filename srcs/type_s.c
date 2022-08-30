/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:00:24 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/30 13:02:44 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	more_edge(t_info *info, char *str)
{
	if (str)
	{
		info->copy = ft_strnew(info->copylen + 1);
		ft_strcpy(info->copy, str);
	}
	else
	{
		info->copy = ft_strnew(6);
		info->copylen = 6;
		ft_strcpy(info->copy, "(null)");
	}
	if (info->precision > 0 && info->precision < info->copylen)
	{
		info->copy[info->precision] = '\0';
		info->copylen = ft_strlen(info->copy);
	}
}

int	type_str(t_info *info)
{
	char	*str;

	if (info->precision == 0)
	{
		info->copy = ft_strnew(1);
		ft_strcpy(info->copy, "\0");
		return (1);
	}
	str = va_arg(info->list, char *);
	info->copylen = ft_strlen(str);
	more_edge(info, str);
	return (0);
}
