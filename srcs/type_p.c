/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:24:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/02 17:21:06 by ccariou          ###   ########.fr       */
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
	//if(info->flag == '#')
	//if(info->flag == '0')
	//if(info->flag == '-')
	//if ((ft_strcmp(info->flag, "+")) == 0)
	//	write(1, "+", 1);
	//if ((ft_strcmp(info->flag, " ")) == 0)
	//	write(1, " ", 1);
	i = va_arg(info->list, unsigned long);
	make_adress(info);
	convert(info, i, 16);
//	mod_init(info);
	return(0);
}
