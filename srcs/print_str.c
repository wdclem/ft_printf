/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:00:24 by ccariou           #+#    #+#             */
/*   Updated: 2022/07/04 10:39:17 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(t_info *info)
{
//	char *	copy;
	
/*	if(info->precision ==0) 
		info->to_print[0] = '/0';
	else
	{
		copy = va_arg(info->list, char *);
		info->to_print = ft_strdup(copy);
	}
	*/
	ft_putstr(va_arg(info->list, char *));
	return(0);
}
