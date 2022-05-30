/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:13:53 by ccariou           #+#    #+#             */
/*   Updated: 2022/05/30 13:42:23 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(int num, int base)
{
	static char str[]="0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[50];
	ft_bzero(ptr, sizeof(buffer));

	while(num !=0)
	{
		*--ptr = str[num%base];
		num/= base;
	}
	return(ptr);
}
