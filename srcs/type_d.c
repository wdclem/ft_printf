/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:24:31 by ccariou           #+#    #+#             */
/*   Updated: 2022/06/02 11:40:59 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	use_size(t_info *info)
{
	if(info->flag == "l")
		modify_type(info, va_arg(info->info, long), 10);
}

void	use_flag(t_info *info)
{
	if(info->flag == '-')
		write

int	type_d(t_info *info)
{
	use_size(info);
	use_flag(info);
	return(0);
}
