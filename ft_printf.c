#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"

/*struct flag_interface{
	flag_char;
	flag_string;
	flag_digit;
	flag_integer;
	flag_undecimal;
	flag_pointer;
	flag_hexa;
	flag_X;
	flag_percent;
}*/
char	*convert(int num, int base)
{
	static char str[]="0123456789ABCDEF";
	static char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';

	while(num !=0)
	{
		*--ptr = str[num%base];
		num/= base;
	}
	return(ptr);
}

int	ft_printf(char *str, ...)
{
	int		i;
	size_t	charnumb;
	char	*ptr;
	char	*s;

	/*Initialize printf listuments */
	va_list	list;
	va_start(list, str);
	i = 0;
	ptr = str;

		while(*ptr != '\0')
		{
			if(*ptr == '%')
			{
				i += check_format(&str, &ptr, &list);
				/*s = va_arg(list, char*);
				ft_putstr(s);
				i += ft_strlen(s);
				*ptr++;
				*ptr++;
			}
			else
			{
				ft_putchar(*ptr);
				*ptr++;
				i++;
			}*/
			/*while(*ptr != '%' && *ptr != '\0')
			{
				putchar(*ptr);
				ptr++;
			}
			ptr++;*/
		//Module 2: Fetching and executing listuments
/*	switch (*ptr)
	{
		case 'c': i = va_arg(list, int); //Fetch char argument
		{
			ft_putchar(i);
			break;
		}
		case 'd': i = va_arg(list, int); //Fetch Decimal/Integer argument
		if (i < 0)
		{
			i = -i;
			putchar('-');
		}
		ft_putstr(convert(i, 10));
		break;

		case 'o': i = va_arg(list, int); //Fetch Octal representation
			ft_putstr(convert(i, 8));
		break;

		case 's': s = va_arg(list, char*); //Fetch string
			ft_putstr(s);
			charnumb = ft_strlen(s);
			ft_putnbr(charnumb);
		break;

		case 'x': i = va_arg(list, int); //Fetch Hexadecimal representation
			puts(convert(i, 16));
		break;
	}*/
	}

//Module 3: Closing listument list to necessary clean-up
// Module 3.1: Output the generated string.
	va_end(list);
	return(i);
}


	/*while(j < str)
	{
		val += va_list(ap, int);
		j++;
	}
	va_end(ap);
	return (ap);

	while(str && str[i])
	{
		if(str[i] == %)
		{
			i++;
			putchar(str[i]
		}
		if (str[i] == s)*/



int main()
{
	char salut[] = "world";
	printf("%d", ft_printf("Hello %s\n", salut));
	return (0);
}
