#include <stdio.h>

void	expression_relational()
{
	int i = 1;
	int j = 2;

	printf("[ relational expression ]\n");
	printf("i = %d, j = %d\n", i, j);
	printf("i < j = %d\n", i < j);
	printf("i > j = %d\n", i > j);
	printf("i <= j = %d\n", i <= j);
	printf("i >= j = %d\n", i >= j);
	printf("i == j = %d\n", i == j);
	printf("i != j = %d\n", i != j);
}

void	main(void)
{
	expression_relational();
}
