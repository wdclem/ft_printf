#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

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


int	ft_printf(char *str, ...)
{
	int	i;
	int	ret;
	int	val;
	char	*ptr;
	va_list	list;

	va_start(list, str);
	val = 0;
	i = 0;
	ptr = strchr(str, (int) '%');

	while(str[i] != '\0')
	{
		if(str[i] != '%')
			putchar(str[i]);
		i++;
	}
	return (0);
}


	/*while(j < str)
	{
		val += va_arg(ap, int);
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
	ft_printf("On dit quoi ? %s\n", "salut");

	return (0);
}
