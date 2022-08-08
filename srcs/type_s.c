/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:00:24 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/04 16:56:11 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_str(t_info *info)
{
	char	*str;

	str = va_arg(info->list, char *);
	info->copylen = ft_strlen(str);
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
		info->copy[info->precision] = '\0';
	return(0);
}
