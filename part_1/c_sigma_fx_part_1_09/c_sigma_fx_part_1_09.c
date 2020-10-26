#include <stdio.h>

void	expression_conditional()
{
	int i = 1;
	int j = 2;

	printf("[ conditional expression ]\n");
	printf("i = %d, j = %d\n", i, j);
	printf("i < j ? %s\n", i < j ? "true" : "false");
	printf("(i > j) ? %s\n", (i > j) ? "true" : "false");
}

void	main(void)
{
	expression_conditional();
}
