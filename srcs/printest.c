#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"

typedef	int	conv(va_list *list);
/*struct convert_interface{
	conv_char = &print_char;
	conv_string = &print_str;
	conv_digit = &print_digit;
	conv_integer = &print_int;
	conv_undecimal;
	conv_pointer;
	conv_hexa;
	conv_X;
	conv_percent;
}*/
/*
struct	flag_interface{
	zero = 0;
	space = 0;
	hash = 0;
	plus = 0;
	minus = 0;
}
*/
/*char	*convert(int num, int base)
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
*/
/*
int	check_input(char c)
{
	int	i;
	i = 0;
	while(FLAGS[i] !='\0')
	{
		if(c == FLAGS[i])
			return(1);
		i++;
	}
	return(0);
}
*/
static int	print_int(va_list *list)
{
	ft_putnbr(va_arg(*list, int));
	return (1);
}

static int	print_str(va_list *list)
{
	ft_putstr(va_arg(*list, char *));
	return (1);
}

static int	print_char(va_list *list)
{
	ft_putchar(va_arg(*list, char));
	return (1);
}

static int	print_percentage(va_list *list)
{
	(void)list;
	write(1, "%", 1);
	return (0);
}

int	check_percentage(char *ptr, va_list *list)
{
	char	*copy;
	conv	*array[11];
	int		select;
	int		ret;
	copy = ptr;

	array[0] = &print_int;
	array[1] = &print_str;
	array[2] = &print_char;
	array[3] = &print_percentage;

	if(*(ptr + 1) == 'd')
		select = 0;
	else if (*(ptr + 1) == 's')
		select = 1;
	else if(*(ptr + 1) == 'c')
		select = 2;
	else if (*(ptr + 1) == '%')
		select = 3;
	ret = (array[select])(list);
	return(ret);
	//check_flag;
	//check_width
	//if(**copy == '.')
	//check_preci
	//copy++;
	//convert using convert interface
	//if (copy == 's')
}


int	ft_printf(char *str, ...)
{
	int		i;
	int		ret;
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
				write(1, str, (ptr - str));
				//write(1, ptr + 1, 1);
				str = ptr + 1;
				ret = check_percentage(ptr, &list);
				/*s = va_arg(list, char*);
				ft_putstr(s);
				i += ft_strlen(s);
				*ptr++;
				*ptr++;*/
			}
			ptr++;
		}
			//write(1, str, ft_strlen(str));
			/*
			else
			{
				ft_putchar(*ptr);
				*ptr++;
				i++;
			}
			*/
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
	ft_printf("Hello %s\n", salut);
	ft_printf("Hello %d\n", 13);
	return (0);
}
