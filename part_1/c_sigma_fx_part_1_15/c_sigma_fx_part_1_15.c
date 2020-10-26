#include <stdio.h>

void	statement_for()
{
	int sum = 0;

	printf("[ statement for ]\n");
	printf("sum = %d\n", sum);

	for (int count = 1; count <= 10; count++)
	{
		sum += count;
	}

	printf("sum = %d\n", sum);
}

void	main(void)
{
	statement_for();
}
