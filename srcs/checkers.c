/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:42:00 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/29 14:57:26 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "ft_printf.h" // CHECK ME OUT

int	check_flag(const char **ptr, t_info *info)
{
	int	i;

	++*ptr;
	i = 0;
	while (**ptr && ft_strchr(" #0-+", **ptr))
	{
		info->flag[i] = **ptr;
		++*ptr;
		i++;
	}
	return (i);
}

int	check_width(const char **ptr, t_info *info)
{
	int	nb;

	while (ft_isspace(**ptr))
		ptr++;
	if (**ptr == '*')
	{
		nb = va_arg(info->list, int);
		if (nb < 0)
		{
			nb *= -1;
			ft_strcat(info->flag, "-");
		}
		info->width = nb;
		++*ptr;
	}
	if (**ptr >= '0' && **ptr <= '9')
	{
		info->width = ft_atoi(*ptr);
		if (info->width > 9)
			*ptr += 2;
		else
			++*ptr;
	}
	return (1);
}

int	check_precision(const char **ptr, t_info *info)
{
	if (**ptr != '.')
		return (0);
	++*ptr;
	info->precision = 0;
	if (ft_isdigit(**ptr))
	{
		info->precision = ft_atoi(*ptr);
		if (info->precision > 9)
			*ptr += 2;
		else
			++*ptr;
	}
	else if (**ptr == '*')
	{
		info->precision = va_arg(info->list, int);
		if (info->precision < 0)
			info->precision = -1;
		++*ptr;
		return (1);
	}
	else
		return (1);
	return (0);
}

int	check_size(const char **ptr, t_info *info)
{
	int	i;

	i = 0;
	while (**ptr && ft_strchr("Llh", **ptr))
	{
		info->size[i] = **ptr;
		++*ptr;
		i++;
	}
	return (i);
}

int	check_conv(const char **ptr, t_info *info)
{
	int	i;

	i = 0;
	if (**ptr && ft_strchr("cspdiouxXf%", *ptr[i]))
		info->type = *ptr[i];
	else
		return (0); // return error if no type precise ?
	return (1);
}
