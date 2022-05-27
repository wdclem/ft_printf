/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:42:00 by ccariou           #+#    #+#             */
/*   Updated: 2022/05/27 10:45:35 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "ft_printf.h" // CHECK ME OUT

int	check_flag(char **ptr, t_info *info)
{
	int	i;
	++*ptr;
	i = 0;
	while (**ptr && ft_strchr("#0-+", (*ptr)[i]))
			{
				info->flag[i] = *ptr[i];
				i++;
			}
	//printf("flag = %d\n", flag);
	return(i);
}

int	check_width(char **ptr, t_info *info, va_list *list)
{
	int	nb;

	while (ft_isspace(**ptr))
		ptr++;
	if (**ptr == '*')
	{
		nb = va_arg(*list, int);
		if (nb < 0)
		{
			nb *= -1;
			info->width = -1;
		}
		info->width = nb;
		ptr++;
	}
	if (**ptr >= '0' && **ptr <= '9')
	{
		nb = 0;
		while (**ptr >= '0' && **ptr <= '9')
		{
			nb = nb * 10 + (**ptr - '0');
			ptr++;
		}
		info->width = nb;
	}
	return(1);
}

int	check_precision(char **ptr, t_info *info, va_list *list)
{
	int	precision;
	int	no_precision;
	int	star;

	if (**ptr != '.')
		return(0);
	++*ptr;
	if(isdigit(**ptr))
		precision = ft_atoi(*ptr) ;
	printf("precision = %d\n",precision);
	return(0);
}

int	check_size(char **ptr, t_info *info, va_list *list)
{
	int	i;

	i = 0;
	while (**ptr && ft_strchr("Llh", *ptr[i]))
	{
		info->size = *ptr[i];
		i++;
	}
	return (i);
}

int    check_conv(char **ptr, t_info *info, va_list *list)
{
	int	i;

	i = 0;
	if(**ptr && ft_strchr("cspdiouxXf%", *ptr[i]))
		info->type = *ptr[i];
	else
		return(0); // return error if no type precise ?
	return(1);
}
