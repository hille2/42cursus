#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int i;
	// int q;
	// int w;
	// int e;

	// q = ft_atoi(argv[1]);
	// w = ft_atoi(argv[2]);
	// e = ft_atoi(argv[3]);


	// i = ft_printf("%*.*i", q, w, e);
	// printf("\n%d\n", i);

	// i = printf("%*.*i", q, w, e);
	// printf("\n%d\n", i);


	i = ft_printf("%-8.0d", 0);
	printf("\n%d\n", i);
	i = printf("%-8.0d", 0);
	printf("\n%d\n", i);
}