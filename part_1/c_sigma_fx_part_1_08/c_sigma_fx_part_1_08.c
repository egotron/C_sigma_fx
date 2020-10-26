#include <stdio.h>

void	expression_logical()
{
	int i = 1;
	int j = 0;

	printf("[ logical expression ]\n");
	printf("i = %d, j = %d\n", i, j);
	printf("i && j = %d\n", i && j);
	printf("i || j = %d\n", i || j);
}

void	main(void)
{
	expression_logical();
}
