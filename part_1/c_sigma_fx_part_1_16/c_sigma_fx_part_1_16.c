#include <stdio.h>

int		function_sum(int from, int to)
{
	int sum = 0;

	printf("[ function sum ]\n");
	printf("from = %d, to = %d\n", from, to);

	for (int count = from; ; )
	{
		sum += count;
		if (count++ < to)	continue;

		goto exit;
	}
	
exit:
	printf("sum = %d\n", sum);
	
	return sum;
}

void	main(void)
{
	function_sum(1, 10);
}
