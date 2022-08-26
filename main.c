#include "includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("\n");
	ft_printf("%#.o", 42);
	printf("\n");
	printf("%#.o", 42);
	printf("\n");
	ft_printf("%#6o", 2500);
		//ft_printf("%9.2p", 1234);UNDEFINED BEHAVIOUR
//	printf("\n");
//			printf("%9.2p", 1234);
	printf("\n");
	/*	ft_printf("%");
	printf("\n");
			printf("%");
			*/
	printf("\n");
		ft_printf("%c", 0);
	printf("\n");
			printf("%c", 0);
	printf("\n");
		ft_printf("{%3c}", 0);
	printf("\n");
			printf("{%3c}", 0);
	printf("\n");
	/*	ft_printf("%#c", 0);
	printf("\n");
			printf("%#c", 0);
			*/
	printf("\n");
		ft_printf("%4.s", "42");
	printf("\n");
			printf("%4.s", "42");
	printf("\n");
		ft_printf("%.c", 0);
	printf("\n");
			printf("%.c", 0);
	printf("\n");
//		ft_printf("%.5p", 0);  UNDEFINED BEHAVIOUR
//	printf("\n");
//			printf("%.5p", 0);
	printf("\n");
		ft_printf("%#.3o", 1);
	printf("\n");
			printf("%#.3o", 1);
	printf("\n");
		ft_printf("{%*c}", 0, 0);
	printf("\n");
			printf("{%*c}", 0, 0);
	printf("\n");
	/*
	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	ft_printf("%4.15d\n", 42);
	printf("@: % 10.5d\n", 4242);
	printf("@: %.10d\n", -42);
	ft_printf("%#6o\n", 2500);
	printf("%#6o\n", 2500);
	ft_printf("@ft: %.o %.0o\n", 0, 0);
	printf("@print : %.o %.0o\n", 0, 0);
	ft_printf("@ft %#.x %#.0x\n", 0, 0);
	// UNDEFINED printf("%.2c\n", NULL);
	printf("@moulitest: %c\n", 0);
	ft_printf("ft@moulitest: %c\n", 0);
	printf("pr %2c\n", 0);
	ft_printf("ft %2c\n", 0);
	printf("null %c and text\n", 0);
	ft_printf("ft null %c and text\n", 0);
	// UNDEFINED printf("% c\n", 0);
	printf("@moulitest: %.d %.0d\n", 42, 43);
	ft_printf("ft@moulitest: %.d %.0d\n", 42, 43);
	*/
}

