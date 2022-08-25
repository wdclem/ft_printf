/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:13:53 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/24 11:43:28 by ccariou          ###   ########.fr       */
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

void	mod_init(t_info *info)
{
	int	len;

	len = info->precision - info->copylen + 1;
	if (len <= 0)
		len = 1;
	info->mod = ft_strnew(len);
	ft_memset(info->mod, '0', len);
	if (info->isneg == 1 && (ft_strchr("idf", info->type)))
		info->mod[0] = '-';
	else if (ft_strchr(info->flag, '+') && info->type != 'u')
		info->mod[0] = '+';
	else if (ft_strchr(info->flag, ' ') && info->type != 'u')
		info->mod[0] = ' ';
	else
		info->mod[len - 1] = '\0';
}

char	*convert(t_info *info, unsigned long long numb, int base)
{
	static char	*str;
	int			len;

	str = "0123456789abcdef";
	len = numb_len(numb, base);
	info->copylen = len;
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
	return (info->copy);
}

char	*signed_numb(t_info *info, long long numb, int base)
{
	static char	*str;
	int			len;

	str = "0123456789abcdef";
	len = numb_len(numb, base);
	info->copylen = len;
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
	return (info->copy);
}
