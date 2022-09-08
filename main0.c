#include "includes/ft_printf.h"
#include <stdio.h>

int	main()
{
	int ft;
	int pf;

	ft_printf("%3d\n", 5);
	ft_printf("%-d\n", 5);
	printf("%.f\n", 3.500000);
	ft_printf("%.f\n", 3.500000);
	printf("\n");
	printf("%.f\n", 2.500000);
	ft_printf("%.f\n", 2.500000);
	printf("%");
	printf("\n");
	printf("test%#.hho %#.0hho", 0, 0);
	printf("\n");
	ft_printf("ftest%#.hho %#.0hho", 0, 0);
	printf("\n");
	printf("Test #8.2o: %#8.2o", 42);
	printf("\n");
	ft_printf("Test #8.2o: %#8.2o", 42);
	printf("\n");
	printf("test: % d\n", -42);
	printf("\n");
	ft_printf("test: % d\n", -42);
	printf("\n");
	printf("test: % st\n", "test");
	printf("\n");
	ft_printf("test: % st\n", "test");
	printf("\n");
	printf("Test %.f\n", 1.5);
	printf("\n");
	ft_printf("Test %.f\n", 1.5);
	printf("\n");
	printf("\n");
	printf("Test %%#-1.0x: {%#-1.0x}", 0);
	printf("\n");
	ft_printf("Test %%#-1.0u: {%#-1.0u}", 0);
	printf("\n");
	pf = printf("Test *c zero {%*c}", 0, 0);
	printf("\n");
	ft = ft_printf("Test *c zero {%*c}", 0, 0);
	printf("\n");
	printf("ft = %d, pf = %d", ft, pf);
	printf("\n");
	printf("%2.9p", 1234567);
	printf("\n");
	ft_printf("%2.9p", 1234567);
	printf("\n");
	//undefined behaviour
	printf("%.5p", 0);
	printf("\n");
	ft_printf("%.5p", 0);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Test 5p: {%5p}", 0);
	printf("\n");
	ft_printf("{%5p}", 0);
	printf("\n");
	printf("%#8.2x", 42);
	printf("\n");
	//double check the following
	ft_printf("%#8.2x", 42);
	printf("\n");
	printf("\n");
	printf("Test -15p: {%-15p}", 0);
	printf("\n");
	ft_printf("Test -15p: {%-15p}", 0);
	printf("\n");
	printf("\n");
	printf("\n");
	pf = printf("pfmin{%*c}", -15, 0);
	printf("\n");
	ft = ft_printf("ftmin{%*c}", -15, 0);
	printf("ft = %d, pf = %d", ft, pf);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	pf = printf("{%*c}", 0, 0);
	printf("\n");
	ft = ft_printf("{%*c}", 0, 0);
	printf("\n");
	printf("ft = %d, pf = %d", ft, pf);
	printf("\n");
	printf("%4.s", "42");
	printf("\n");
	ft_printf("%4.s", "42");
	printf("\n");
	pf = printf("pm{%3c}", 0);
	printf("\n");
	ft = ft_printf("fm{%3c}", 0);
	printf("\n");
	printf("ft = %d, pf = %d", ft, pf);
	printf("\n");
/*	printf("%9.2p", 1234);
	printf("\n");
	ft_printf("%9.2p", 1234);
	UNDEFINIED */
	printf("\n");
	pf = printf("{%*c}", 0, 0);
	printf("\n");
	ft = ft_printf("{%*c}", 0, 0);
	printf("\n");
	printf("ft = %d, pf = %d", ft, pf);
	printf("\n");
	printf("%");
	printf("\n");
	ft_printf("%");
	printf("\n");
	printf("\n");
	/*printf("%.s", "Hello");
	printf("\n");
	ft_printf("%.s", "Hello");
	printf("\n");
	ft_printf("Test %010d\n", -0.0);
	printf("Test %010d\n", -0.0);
	ft_printf("Test positive %010f\n", 0.0);
	ft_printf("Test %010f\n", -0.0);
	printf("Test %010f\n", -0.0);
	ft_printf("ft : %f\n", -42.42);
	printf("ft : %f\n", -42.42);
	ft_printf("%#.o", 42);
	printf("\n");
	printf("%#.o", 42);
	printf("\n");
	ft_printf("%#6o", 2500);
		//ft_printf("%9.2p", 1234);UNDEFINED BEHAVIOUR
//	printf("\n");
//			printf("%9.2p", 1234);
	printf("\n");
		ft_printf("%");
	printf("\n");
			printf("%");
	printf("\n");
		ft_printf("%c", 0);
	printf("\n");
			printf("%c", 0);
	printf("\n");
		ft_printf("{%3c}", 0);
	printf("\n");
			printf("{%3c}", 0);
	printf("\n");
		ft_printf("%#c", 0);
	printf("\n");
			printf("%#c", 0);
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
	printf("\n");*/
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
