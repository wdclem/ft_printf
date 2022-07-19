/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:06:11 by ccariou           #+#    #+#             */
/*   Updated: 2022/07/04 12:06:32 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	type_c(t_info *info)
{
	info->copy = ft_strnew(1);
	ft_bzero(info->copy, 1);
	info->copy[0] = (char)va_arg(info->list, int);
	return(0);
}

