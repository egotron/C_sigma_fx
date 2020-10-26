#ifndef __C_SIGMA_FX_PART_1_20__
#define __C_SIGMA_FX_PART_1_20__

#include <stdio.h>

#define	LOOP_COUNT	10
#define	X10(x)		((x) * 10)

int	global_loop_count	= LOOP_COUNT;
int global_2x10 = X10(2);

#define	FOREVER		for(;;)
#define	MAX(a, b)	((a) > (b) ? (a) : (b))
#define	PRINT(expr)	printf(#expr " = %d\n", expr)

void	main(void)
{
	int	local_loop_count = X10(global_loop_count);
	int local_max = MAX(2, 5);

	PRINT(global_loop_count);
	PRINT(global_2x10);

	PRINT(local_loop_count);
	PRINT(local_max);
}

#endif // !__C_SIGMA_FX_PART_1_20__
