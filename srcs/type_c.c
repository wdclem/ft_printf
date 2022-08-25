/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:04:38 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/24 10:51:06 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(t_info *info)
{
	info->copy = ft_strnew(1);
	*info->copy = (char)va_arg(info->list, int);
	info->copylen = 1;
	return (0);
}
