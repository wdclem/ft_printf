/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:03:17 by ccariou           #+#    #+#             */
/*   Updated: 2022/07/05 10:58:52 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	change_size(t_info *info, long long i)
{
	if ((ft_strcmp(info->size, "ll")) == 0)
		return(i = va_arg(info->list, long long));
	else if ((ft_strcmp(info->size, "l")) == 0)
		return(i = va_arg(info->list, long));
	else if ((ft_strcmp(info->size, "h")) == 0)
		return(i = (short)va_arg(info->list, int));
	else if ((ft_strcmp(info->size, "hh")) == 0)
		return(i = (char)va_arg(info->list, int));
	else
		return (va_arg(info->list, int));
}

/*void	print_flag(t_info *info)
{
		if (ft_strchr(info->flag, '+'))
			info->mod[0]
			write(1, "+", 1);
		if(ft_strchr(info->flag, ' '))
			write(1, " ", 1);
		if(info->width)
		{
			while(info->width >= 0)
			{
				write(1, "$", 1);
				info->width--;
			}
		}
	//if ((ft_strcmp(info->flag, "+")) == 0)
	//	write(1, "+", 1);
	//if ((ft_strcmp(info->flag, " ")) == 0)
	//	write(1, " ", 1);
}

void	print_precision(t_info *info)
{
	if(info->precision)
	{                 
		while(info->precision > 1)
		{             
			write(1, "0", 1);
			info->precision--;
		}             
	}
}   

void	minus_flag(t_info *info, long long i)
{
	if (ft_strchr(info->flag, '+'))
 		write(1, "+", 1);
 	if(ft_strchr(info->flag, ' '))
 		write(1, " ", 1);
	 ft_putstr(convert(info, i, 10));
 }
*/
int	print(t_info *info)
{
	int	print_char;

	print_char = 0;
	print_char = info->modlen + info->copylen;
	ft_putstr(info->mod);
	ft_strdel(&info->mod);
	ft_putstr(info->copy);
	ft_strdel(&info->copy);
	ft_putstr(info->minus_mod);
	ft_strdel(&info->minus_mod);
	return (print_char);
}
static void	min_width(t_info *info)
{
	int		len;
	char	*temp;
	int		prefix_len;
	int		copy_position;

	prefix_len = ft_strlen(info->mod);
	len = info->width - info->copylenft_strlen(info->copy);
	if (len <= prefix_len)
		return ;
	temp = ft_strnew(len);
	ft_memset(temp, ' ', len);
	if (ft_strchr(info->flag, '-'))
	{
		temp[len - prefix_len] = '\0';
		info->minus_mod = temp;
		return ;
	}
	if ((info->precision == -1 || !ft_strchr("diouxX", info->type))
		&& ft_strchr(info->flag, '0'))
		ft_memset(temp, '0', len);
	copy_position = (len - prefix_len) * (temp[0] != '0');
	if (info->mod)
		ft_strncpy(temp + copy_position, info->mod, prefix_len);
	ft_strdel(&info->mod);
	info->mod = temp;
}

int	print_int(t_info *info)
{
	long long	i;

	i = 0;
	//if(info->flag == '#')
	//if(info->flag == '0')
	//if(info->flag == '-')
	//if ((ft_strcmp(info->flag, "+")) == 0)
	//	write(1, "+", 1);
	//if ((ft_strcmp(info->flag, " ")) == 0)
	//	write(1, " ", 1);
	i = change_size(info, i); /*make it a if */
	convert(info, i, 10);
	mod_init(info);
	min_width(info);
	print(info);
	/*if (ft_strchr(info->flag, '-'))
		minus_flag(info, i);
	else
	{
		print_flag(info);
		print_precision(info);
	}
	*/
//	i = va_arg(info->list, int);
/*	if (i < 0)
	{
		i = -i;
		putchar('-');
	}
	*/
//	ft_putstr(convert(info,i, 10));
	return(1);
}
