#include <stdio.h>

void	statement_switch()
{
	int i = 1;
	int j = 2;
	int max;

	printf("[ statement switch ]\n");
	printf("i = %d, j = %d\n", i, j);

	switch (i)
	{
	case 0: max = 0; break;
	case 1:
		max = 1;
		j = max;
		break;
	case 2:
		{
			max = 2;
			j = max;
		}
		break;
	default:
		max = -1;
		j = 0;
	}

	printf("i = %d, j = %d, max = %d\n", i, j, max);
}

void	main(void)
{
	statement_switch();
}
