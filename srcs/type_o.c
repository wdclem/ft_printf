/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:02:59 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/30 13:03:02 by ccariou          ###   ########.fr       */
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

static void	more_edge(t_info *info, int len)
{
	if (len > 0 && info->precision != 0)
	{
		info->mod = ft_strnew(len);
		ft_memset(info->mod, '0', len);
	}
	else
	{
		info->mod = ft_strnew(1);
		if (len == 0 && info->precision != 0 && info->copy[0] != '0')
		{
			len = 1;
			ft_memset(info->mod, '0', len);
		}
	}
}

int	type_o(t_info *info)
{
	unsigned long long	i;
	int					len;
	int					limit;

	i = 0;
	i = change_size(info, i);
	if (!edge_case(info, i))
		convert(info, i, 8);
	len = info->precision - info->copylen;
	more_edge(info, len);
	limit = len + info->copylen;
	if (ft_strchr(info->flag, '#')
		&& limit <= info->precision && info->copy[0] != '0')
	{
		limit = ft_strlen(info->mod) + info->copylen;
		if (limit <= info->precision)
			return (1);
		else
			info->mod = ft_strjoin("0", info->mod);
	}
	return (0);
}
