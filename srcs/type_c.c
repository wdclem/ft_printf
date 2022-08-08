/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:04:38 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/08 10:41:40 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(t_info *info)
{
	info->copy = ft_strnew(1);
	*info->copy = (char)va_arg(info->list, int);
	info->copylen = 1;
//	ft_putchar(va_arg(info->list, int));
	return(0);
}
