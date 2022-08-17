/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divideby.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccariou <ccariou@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:31:25 by ccariou           #+#    #+#             */
/*   Updated: 2022/08/11 14:23:12 by ccariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>

long double ft_fmod(long double a, long double b);


long double	ft_floor(long double numb)
{
	long double x;

 	numb = numb - ((int)numb % 1);
	return((float)numb);
}

long double ft_ceil(long double numb)
{
	int x;

	x = (int)numb;
	if (numb == (float)x || numb < 0)
	{
		return x;
	}
	else
		return (x + 1);
}

long double	ft_truncate(long double numb)
{
	long double x;

	x = 0;
	if(x >= 0.0)
		x = ft_floor(numb);
	else
		x = ft_ceil(numb);

	return (x);
}

long double	ft_fmod(long double a, long double b)
{
	return (a - ft_truncate(a / b) * b);
}

long double	ft_divideby(long double a, long double b)
{
	if(ft_fmod(a, b)== 0)
        return (1);
	else 
		return (0);
}

int main()
{
	int a = 4;
	int b = 7;
	int c = 2;

	if(ft_divideby(a, c))
		printf("oui\n");
	if(!ft_divideby(a, c))
		printf("!ouioui\n");
	if(ft_divideby(b, c))
		printf("non\n");
	return (0);
}
