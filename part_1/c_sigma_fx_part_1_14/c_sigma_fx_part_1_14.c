#include <stdio.h>

void	statement_do_while()
{
	int count = 0;
	int sum;

	sum = 0;

	printf("[ statement do while ]\n");
	printf("count = %d, sum = %d\n", count, sum);

	do {
		count++;
		sum += count;
	} while (count < 10);

	printf("count = %d, sum = %d\n", count, sum);
}

void	main(void)
{
	statement_do_while();
}
