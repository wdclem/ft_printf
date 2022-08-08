/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_Xcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:06:07 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/08 12:30:21 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	capital(char *str)
{
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
}

int	type_Xcap(t_info *info)
{
	type_x(info);
	printf("ERROR TRACK copy = %s\n", info->copy);
	capital(info->copy);
	printf("ERROR TRACK after capitalize copy = %s\n", info->copy);
/*	while(*info->copy != '\0')
	{
		*info->copy = ft_toupper(*info->copy);
		info->copy++;
	}
	*/
	return(0);
}
