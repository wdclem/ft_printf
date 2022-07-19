#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
	int num = 40000;
	float flo = 4.01;
	//char salut[] = "world";
	//ft_printf("Hello HEXA %X\n", 500);
	//ft_printf("Hello %-c\n", 'c');
	//printf("(pf)Hello %-c\n", 'c');
	ft_printf("Hello %d\n", num);
	printf("(pf)Hello %d\n", num);
	printf("\n");
	printf("\n");
	ft_printf( "|%-5d|%-5d|\n", 1, 2 );
	printf( "|%-5d|%-5d|\n", 1, 2 );
	printf("\n");
	printf("\n");
	ft_printf("Hello %-4d\n", num);
	printf("(pf)Hello %-4d\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %f\n", flo);
	printf("(pf)Hello %4f\n", flo);
	printf("\n");
	printf("\n");
	ft_printf("Hello %.4d\n", num);
	printf("(pf)Hello %-.4d\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello % ld\n", 10000);
	printf("(pf)Hello % ld\n", 10000);
	printf("\n");
	printf("\n");
	ft_printf("Hello % +ld\n", 10000);
	printf("(pf)Hello % +ld\n", 10000);
	printf("\n");
	printf("\n");
	ft_printf("Hello %hhd\n", 10001);
	printf("(pf)Hello %hhd\n", 10001);
	printf("\n");
	printf("\n");
	ft_printf("Hello %0d\n", 10000);
	printf("(pf)Hello %0d\n", 10000);
	/*printf("(pf)Hello %d\n", 2147483647);
	printf("(pf)Hello %d.0\n", 2147483647);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
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
	*/
	return (0);
}
