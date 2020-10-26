#include <stdio.h>

void	expression_bitwise()
{
	int i = 0x3;
	int j = 0x1;

	printf("[ bitwise expression ]\n");
	printf("i = %02X, j = %02X\n", i, j);
	printf("i & j = %02X\n", i & j);
	printf("i | j = %02X\n", i | j);
	printf("i ^ j = %02X\n", i ^ j);
}

void	main(void)
{
	expression_bitwise();
}
