/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:21:35 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/04 16:22:49 by ccariou          ###   ########.fr       */
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
	type[8] = &type_Xcap;
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
	info->precision = 0;
	ft_memset (info->size, 0, sizeof (info->size));
}

void	size_mod(t_info *info)
{
	int		len;
	char	*temp;
	int		prefix_len;
	int		copy_position;

	prefix_len = ft_strlen(info->mod);
	len = info->width - info->copylen;
	if (len <= prefix_len)
		return ;
	temp = ft_strnew(len);
	ft_memset(temp, ' ', len);
	if (ft_strchr(info->flag, '-'))
	{
		temp[len - prefix_len] = '\0';
		info->minus_mod = temp;
		return ;
	}
	if ((info->precision == 0 || !ft_strchr("diouxX", info->type))
		&& ft_strchr(info->flag, '0'))
		ft_memset(temp, '0', len);
	copy_position = (len - prefix_len) * (temp[0] != '0');
	if (info->mod)
		ft_strncpy(temp + copy_position, info->mod, prefix_len);
	ft_strdel(&info->mod);
	info->mod = temp;
}

int	check_percentage(char **ptr, t_info *info)
{
	conv	*type[11];
	int		select;

	select = 0;
	set_struc(info);
	initialize_type(type);
	get_info(ptr, info);
	dispatch(info, type, select);
	size_mod(info);
	print(info);
	/*%[flags][width][.precision][size]type
	*/
	return (0);
}

int	ft_printf(char *str, ...)
{
	char	*ptr;
	t_info	info;

	/*Initialize printf listuments */
	va_start(info.list, str);
	ptr = str;
	set_struc(&info);
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			check_percentage(&ptr, &info);
			ptr += 1;
		}
		else
		{
			write(1, ptr, 1);
			ptr++;
		}
	}
	va_end(info.list);
	return (0);
}
