#include <stdio.h>

void	expression_arithmetic()
{
	int i = 1;
	int j = 2;

	printf("[ arithmetic expression ]\n");
	printf("i + j = %d\n", i + j);
	printf("i - j = %d\n", i - j);
	printf("i * j = %d\n", i * j);
	printf("i / j = %d\n", i / j);
	printf("i %% j = %d\n", i % j);
}

void	main(void)
{
	expression_arithmetic();
}
