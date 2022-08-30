/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:13:53 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/30 12:17:53 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numb_len(unsigned long long numb, int base)
{
	int	len;

	len = 1;
	while (numb / base != 0)
	{
		numb /= base;
		len++;
	}
	return (len);
}

int	edge_case(t_info *info, long long numb)
{
	if (numb == 0 && info->precision == 0)
	{
		if (ft_strchr("o", info->type) && ft_strchr(info->flag, '#'))
		{
			info->precision = 1;
			return (0);
		}
		else
		{
			info->copy = ft_strnew(1);
			info->copy[0] = '\0';
			return (1);
		}
	}
	else
		return (0);
}

char	*convert(t_info *info, unsigned long long numb, int base)
{
	static char	*str;
	int			len;

	str = "0123456789abcdef";
	len = numb_len(numb, base);
	info->copy = ft_strnew(len);
	ft_bzero(info->copy, len);
	if (numb == 0)
		info->copy[0] = '0';
	while (numb != 0)
	{
		len--;
		info->copy[len] = str[numb % base];
		numb /= base;
	}
	info->copylen = ft_strlen(info->copy);
	return (info->copy);
}

char	*signed_numb(t_info *info, long long numb, int base)
{
	static char	*str;
	int			len;

	str = "0123456789abcdef";
	len = numb_len(numb, base);
	info->copy = ft_strnew(len);
	ft_bzero(info->copy, len);
	if (numb == 0)
		info->copy[0] = '0';
	while (numb != 0)
	{
		len--;
		info->copy[len] = str[numb % base];
		numb /= base;
	}
	info->copylen = ft_strlen(info->copy);
	return (info->copy);
}
