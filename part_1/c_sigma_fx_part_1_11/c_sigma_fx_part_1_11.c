#include <stdio.h>

void	statement_if()
{
	int i = 1;
	int j = 2;
	int max;

	printf("[ statement if ]\n");
	printf("i = %d, j = %d\n", i, j);

	if (i > j)	max = i;
	else		max = j;

	if (0 == max)
	{
		i = 0;
		j = 0;
	}
	else if (1 == max)
	{
		i = 1;
		j = 1;
	}
	else
	{
		i = max;
		j = max;
	}

	printf("i = %d, j = %d, max = %d\n", i, j, max);
}

void	main(void)
{
	statement_if();
}
