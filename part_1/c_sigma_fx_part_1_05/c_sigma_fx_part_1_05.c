#include <stdio.h>

void	expression_bit_shift()
{
	int i = 2;

	printf("[ bit shift expression ]\n");
	printf("i << 1 = %d\n", i << 1);
	printf("i >> 1 = %d\n", i >> 1);
}

void	main(void)
{
	expression_bit_shift();
}
