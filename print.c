#include <stdarg.h>
#include <string.h>
#include "ft_printf.h"

//typedef	int	*(*conv)();
typedef	int	conv(va_list *list);
//typedef	int	conv(va_list *list);

static int	print_unsigned(va_list *list)
{
	ft_putunsigned(va_arg(*list, unsigned int));
	return(1);
}

static int	print_x(va_list *list)
{
	ft_puthexa(va_arg(*list, int));
	return(1);
}

static int	print_X(va_list *list)
{
	ft_putupperhexa(va_arg(*list, unsigned int));
	return(1);
}

static int	print_octal(va_list *list)
{
	ft_putoctal(va_arg(*list, unsigned int));
	return(1);
}
static int	print_int(va_list *list)
{
	ft_putnbr(va_arg(*list, int));
	return(1);
}

static int	print_str(va_list *list)
{
	ft_putstr(va_arg(*list, char *));
	return (1);
}

static int	print_char(va_list *list)
{
	ft_putchar(va_arg(*list, int));
	return (1);
}

static int	print_percentage(va_list *list)
{
	write(1, "%", 1);
	return (0);
}

static void		initialize_flags(conv **flags)
{
	flags[0] = &print_str;
	flags[1] = NULL;
	flags[2] = NULL;
	flags[3] = NULL;
	flags[4] = NULL;
}

static void	initialize_size (conv **size)
{
	size[0] = &print_str;
	size[1] = NULL;
	size[2] = NULL;
	size[3] = NULL;
	size[4] = NULL;
}


static void		initialize_type(conv **type)
{
	/* cspdiouxXf% */
	type[0] = &print_char;
	type[1] = &print_str;
//	type[2] = &print_pointer;
	type[3] = &print_int;
	type[4] = &print_int;
	type[5] = &print_octal;
	type[6] = &print_unsigned;
	type[7] = &print_x;
	type[8] = &print_X;
//	type[9] = &print_float;
	type[10] = &print_percentage;
}
void	change_size(va_list *list)
{
	if(*(ptr + 1) == 'l' || *(ptr + 1) == 'L')
		va
	if(*(ptr + 1) == 'll')
	if(*(ptr + 1) == 'h' || *(ptr + 1) == 'hh')

int	check_percentage(char *ptr, va_list *list)
{
	char	*copy;
	conv	*type[11];
	int		select;
	int		ret;
	copy = ptr;
	conv	*flags[5];
	char	type; //to hold the conv type
	//%[flags][width][.precision][size]type

	initialize_flags(flags);
	initialize_type(type);
	initialize_size(size);

	if(*ptr && ft_strchr("cspdiouxXf%", *str)
			type == *(ptr + 1);
	
	if(*(ptr + 1) == 'l' || *(ptr + 1) == 'll' || *(ptr + 1) == 'h' || *(ptr + 1) == 'hh'
			|| *(ptr + 1) == 'L'
	if(*(ptr + 1) == 'c')
		select = 0;
	else if (*(ptr + 1) == 's')
		select = 1;
	else if(*(ptr + 1) == 'd' || *(ptr + 1) == 'i')
		select = 4;
	else if(*(ptr + 1) == 'o')
		select = 5;
	else if(*(ptr + 1) == 'u')
		select = 6;
	else if(*(ptr + 1) == 'x')
		select = 7;
	else if(*(ptr + 1) == 'X')
		select = 8;
	else if (*(ptr + 1) == '%')
		select = 10;
	ret = (type[select])(list);
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
				//write(1, str, (ptr - str));
				//write(1, ptr + 1, 1);
				str = ptr + 1;
				ret = check_percentage(ptr, &list);
				/*s = va_arg(list, char*);
				ft_putstr(s);
				i += ft_strlen(s);
				*/
				ptr+= 2;
			}
			else
			{
				write(1, ptr, 1);
				ptr++;
			}
		}
	//write(1, str + 1, 1);
	va_end(list);
	return(i);
}

int main()
{
	char salut[] = "world";
	//ft_printf("Hello HEXA %X\n", 500);
	ft_printf("Hello string %s\n", salut);
	printf("(pf)Hello %s\n", salut);
	ft_printf("Hello digit %d\n", 2147483647);
	printf("(pf)Hello %d\n", 2147483647);
	ft_printf("Hello hexa %x\n", 99);
	printf("(pf)Hello %x\n", 99);
	ft_printf("Hello HEXA %X\n", 99);
	printf("(pf)Hello %X\n", 99);
	ft_printf("Hello octal %o\n", -500);
	printf("(pf)Hello %o\n", -500);
	ft_printf("Hello int %i\n", 2147483647);
	printf("(pf)Hello %i\n", 2147483647);
	ft_printf("Hello percent %%\n", 10);
	printf("(pf)Hello %%\n", 10);
	ft_printf("hello unsigned %u\n", -1);
	printf("(pf)hello %u\n", -1);
;	return (0);
}
