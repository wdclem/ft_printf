/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:03:17 by ccariou           #+#    #+#             */
/*   Updated: 2022/05/30 11:44:21 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(va_list *list)
{
	int	i;

	i = va_arg(*list, int);
	if (i < 0)
	{
		i = -i;
		putchar('-');
	}
	ft_putstr(convert(i, 10));
	return(1);
}
