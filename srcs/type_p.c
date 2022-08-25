/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:24:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/25 11:22:05 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	make_adress(t_info *info)
{
	int	size;

	info->copylen = ft_strlen(info->list + 2);
	size = info->precision - info->copylen;
	if (size > 2)
	{
		info->mod = ft_strnew(size);
		ft_memset(info->mod, '0', size);
	}
	else
		info->mod = ft_strnew(2);
	ft_strncpy(info->mod, "0x", 2);
}

int	type_p(t_info *info)
{
	long long	i;

	i = 0;
	i = va_arg(info->list, unsigned long);
	make_adress(info);
	convert(info, i, 16);
	return (0);
}
