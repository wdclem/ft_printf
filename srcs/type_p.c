/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:24:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/28 15:31:54 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	make_adress(t_info *info)
{
	int	size;

	//info->copylen = ft_strlen((const char *)info->list + 2);
	size = info->precision - info->copylen;
	if (size > 2)
	{
		size += 1;
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
	if (!edge_case(info, i))
		convert(info, i, 16);
	make_adress(info);
	return (0);
}
