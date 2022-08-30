/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:13:44 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/30 12:55:46 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(t_info *info)
{
	int	i;

	i = 0;
	if (info->type != 'c')
		info->copylen = ft_strlen(info->copy);
	info->modlen = ft_strlen(info->mod);
	ft_putstr(info->mod);
	if (info->cnull == 1)
		write(1, "\0", 1);
	else
		ft_putstr(info->copy);
	ft_putstr(info->minus_mod);
}

void	clean_up(t_info *info)
{
	ft_strdel(&info->mod);
	ft_strdel(&info->copy);
	ft_strdel(&info->minus_mod);
}

void	get_info(const char **ptr, t_info *info)
{
	check_flag(ptr, info);
	check_width(ptr, info);
	check_precision(ptr, info);
	check_size(ptr, info);
	check_conv(ptr, info);
}

void	dispatch(t_info *info, conv **type, int select)
{
	if (info->type == 'c')
		select = 0;
	else if (info->type == 's')
		select = 1;
	else if (info->type == 'p')
		select = 2;
	else if (info->type == 'd' || info->type == 'i')
		select = 4;
	else if (info->type == 'o')
		select = 5;
	else if (info->type == 'u')
		select = 6;
	else if (info->type == 'x')
		select = 7;
	else if (info->type == 'X')
		select = 8;
	else if (info->type == 'f')
		select = 9;
	else if (info->type == '%')
		select = 10;
	else
		return ;
	type[select](info);
}
