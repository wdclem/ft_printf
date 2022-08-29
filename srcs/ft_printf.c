/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:21:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/29 16:44:47 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "../includes/ft_printf.h"

static void	initialize_type(conv **type)
{
/* cspdiouxXf% */
	type[0] = &type_c;
	type[1] = &type_str;
	type[2] = &type_p;
	type[3] = &type_int;
	type[4] = &type_int;
	type[5] = &type_o;
	type[6] = &type_unsigned;
	type[7] = &type_x;
	type[8] = &type_xcap;
	type[9] = &type_f;
	type[10] = &type_percent;
}

void	set_struc(t_info *info)
{
	info->copy = NULL;
	info->mod = NULL;
	info->minus_mod = NULL;
	info->isneg = 0;
	info->copylen = 0;
	info->modlen = 0;
	ft_memset (info->flag, 0, sizeof (info->flag));
	info->type = '0';
	info->width = 0;
	info->precision = -6;
	ft_memset (info->size, 0, sizeof (info->size));
	info->isneg = 0;
	info->cnull = 0;
	info->minuslen = 0;
}

void	size_mod(t_info *info)
{
	int		len;
	char	*temp;
	int		position;

	info->modlen = ft_strlen(info->mod);
	len = info->width - info->copylen;
	if (len <= info->modlen)
		return ;
	temp = ft_strnew(len);
	ft_memset(temp, ' ', len);
	if (ft_strchr(info->flag, '-'))
	{
		temp[len - info->modlen] = '\0';
		info->minus_mod = temp;
		return ;
	}
	if ((info->precision < 0 || !ft_strchr("diouxX", info->type))
		&& ft_strchr(info->flag, '0'))
			ft_memset(temp, '0', len);
	position = (len - info->modlen) * (temp[0] != '0');
	if (info->mod)
		ft_strncpy(&temp[position], info->mod, info->modlen);
	ft_strdel(&info->mod);
	info->mod = temp;
}

int	check_percentage(const char **ptr, t_info *info)
{
	conv	*type[11];
	int		select;

	select = 0;
	initialize_type(type);
	get_info(ptr, info);
	dispatch(info, type, select);
	size_mod(info);
	print(info);
	/*
	 * %[flags][width][.precision][size]type
	*/
	return (0);
}

void    clean_up(t_info *info)
{
	ft_strdel(&info->mod);
	ft_strdel(&info->copy);
	ft_strdel(&info->minus_mod);
}

int	ft_printf(const char *str, ...)
{
	t_info		info;
	int			charcount;

	va_start(info.list, str);
	set_struc(&info);
	charcount = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			check_percentage(&str, &info);
			charcount += (info.copylen + info.modlen + (ft_strlen(info.minus_mod)));
			clean_up(&info);
			set_struc(&info);
			str += 1;
		}
		else
		{
			write(1, str, 1);
			charcount += 1;
			str++;
		}
	}
	va_end(info.list);
	return (charcount);
}
