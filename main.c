#include "includes/ft_printf.h"
#include <stdio.h>

int main()
{
	char test = 'c';
	char str[] = "verite";
	int num = 40000;
	float flo = 4.01;
	//char salut[] = "world";
	//ft_printf("Hello HEXA %X\n", 500);
	//ft_printf("Hello %-c\n", 'c');
	//printf("(pf)Hello %-c\n", 'c');
	printf("-------TEST D------\n\n");
	ft_printf("Hello %.1s\n", NULL);
	printf("Hello %.1s\n", NULL);
	printf("\n");
	printf("\n");
	ft_printf("Hello %x\n", num);
	printf("(pf)Hello %x\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %X\n", num);
	printf("(pf)Hello %X\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %15p\n", str);
	printf("(pf)Hello %15p\n", str);
	printf("\n");
	printf("\n");
	ft_printf("Hello %.3s\n", str);
	printf("(pf)Hello %.3s\n", str);
	printf("\n");
	printf("\n");
	ft_printf("Hello %c\n", test);
	printf("(pf)Hello %c\n", test);
	printf("\n");
	printf("\n");
	ft_printf("Hello %015c\n", test);
	printf("(pf)Hello %015c\n", test);
	printf("\n");
	printf("\n");
	ft_printf("Hello %4d\n", num);
	printf("(pf)Hello %4d\n", num);
	printf("\n");
	printf("\n");
	printf("\n");
	ft_printf("Hello %-d\n", num);
	printf("(pf)Hello %-d\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %d\n", num);
	printf("(pf)Hello %d\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %d\n", num);
	printf("(pf)Hello %d\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %d\n", num);
	printf("(pf)Hello %d\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %d\n", num);
	printf("(pf)Hello %d\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %d\n", num);
	printf("(pf)Hello %d\n", num);
	printf("\n");
	printf("\n");
	ft_printf( "|%-5d|%-5d|\n", 1, 2 );
	printf( "|%-5d|%-5d|\n", 1, 2 );
/*
	printf( "|%-5d|%-5d|\n", 1, 2 );
	printf("-------TEST "%F"------");
	printf("\n")
	printf("\n");
	ft_printf("Hello %-4d\n", num);
	printf("(pf)Hello %-4d\n", num);
	printf("\n");
	printf("\n");
	ft_printf("Hello %.14f\n", flo);
	printf("(pf)Hello %.14f\n", flo);
	printf("\n");
	printf("\n");
	ft_printf("Hello %f\n", flo);
	printf("(pf)Hello %f\n", flo);
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
	printf("\n");
	printf("\n");
	printf("-------TEST "%O"------");
	printf("\n");
	printf("\n");
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
	ft_printf("Hello %.14f\n", flo);
	printf("(pf)Hello %.14f\n", flo);
	printf("\n");
	printf("\n");
	ft_printf("Hello %f\n", flo);
	printf("(pf)Hello %f\n", flo);
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
	printf("-------TEST "%P"------");
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
	printf("(pf)Hello %d\n", 2147483647);
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
