/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:01:30 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/29 16:56:16 by ccariou          ###   ########.fr       */
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

int	type_x(t_info *info)
{
	unsigned long long	i;
	int					len;
	char				*temp;

	i = 0;
	temp = NULL;
	i = change_size(info, i);
	if (!edge_case(info, i))
		convert(info, i, 16);
	len = info->precision - info->copylen;
	if (len > 0)
		info->mod = ft_strnew(len);
	else
	{
		info->mod = ft_strnew(2);
	}
	if (ft_strchr(info->flag, '#') && i != 0 && info->precision != 0)
	{
		temp = ft_strncpy(temp, info->mod, len);
		ft_strdel(&(info->mod));
		info->mod = ft_strjoin("0x", info->mod);
		info->mod = ft_strjoin(info->mod, temp);
		ft_strdel(&(temp));
	}
	return (0);
}
