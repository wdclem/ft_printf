/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:03:17 by ccariou           #+#    #+#             */
/*   Updated: 2022/06/03 13:51:18 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(t_info *info)
{
	int	i;

	if(info->flag == '+')
		write(1, "+", 1);
	i = va_arg(info->list, int);
	if (i < 0)
	{
		i = -i;
		putchar('-');
	}
	ft_putstr(convert(i, 10));
	return(1);
}
