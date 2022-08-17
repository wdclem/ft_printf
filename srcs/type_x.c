/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:01:30 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/12 12:17:58 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	change_size(t_info *info, long long i)
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
		return (va_arg(info->list, unsigned int));
}

int	type_x(t_info *info)
{
	long long	i;

	i = 0;
	i = change_size(info, i); /*make it a if */
	convert(info, i, 16);
	mod_init(info);
//	printf("ERROR TRACK copy = %s\n", info->copy);
//	printf("ERROR TRACK mod = %s\n", info->mod);
	if (ft_strchr(info->flag, '#') && i != 0)
		info->mod = ft_strjoin("0x",info->mod);
	return(0);
}
