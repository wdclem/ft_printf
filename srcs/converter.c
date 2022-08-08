/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:13:53 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/04 13:08:52 by ccariou          ###   ########.fr       */
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
	ft_bzero(info->mod, len);
	if (info->isneg == 1 && (info->type == 'd' || info->type == 'i'))
		info->mod[0] = '-';
	else if (ft_strchr(info->flag, '+'))
		info->mod[0] = '+';
	else if (ft_strchr(info->flag, ' '))
		info->mod[0] = ' ';
	else
		info->mod[0] = '\0';
}

char	*convert(t_info *info, unsigned long long numb, int base)
{
	static char str[]="0123456789abcdef";
	//unsigned long long	num;
	int			len;
//	static char buffer[50];

	//ptr = &buffer[50];
	//ft_bzero(ptr, sizeof(buffer));
	//if (numb < 0)
	//	info->isneg = 1;
//	if (info->isneg && (info->type == 'd' || info->type == 'i'))
//		numb = (-1 * (numb + 1)) + 1;
//	else
//		num = (unsigned long long)numb;
	len = numb_len(numb, base);
	info->copylen = len;
	info->copy = ft_strnew(len);
	ft_bzero(info->copy, len);
	while(numb !=0)
	{
		len--;
		info->copy[len] = str[numb % base];
		numb /= base;
	}
	return(info->copy);
}

char	*signed_numb(t_info *info, long long numb, int base)
{
	static char str[]="0123456789abcdef";
	int         len;

	if (numb < 0)
	{
		info->isneg = 1;
		numb *= -1;
	}
	len = numb_len(numb, base);
	info->copylen = len;
	info->copy = ft_strnew(len);
	ft_bzero(info->copy, len);
	while(numb !=0)
	{
		len--;
		info->copy[len] = str[numb % base];
		numb /= base;
	}
	return(info->copy);
}                                       
