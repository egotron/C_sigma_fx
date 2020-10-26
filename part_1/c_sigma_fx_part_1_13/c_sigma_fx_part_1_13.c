#include <stdio.h>

void	statement_while()
{
	int count = 0;
	int sum;

	sum = 0;

	printf("[ statement while ]\n");
	printf("count = %d, sum = %d\n", count, sum);

	while (count < 10)
	{
		count++;
		sum += count;
	}

	printf("count = %d, sum = %d\n", count, sum);
}

void	main(void)
{
	statement_while();
}
