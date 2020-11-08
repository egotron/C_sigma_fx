#include <stdio.h>
#include "Sum.h"

void	main()
{
	TYPE_SUM Sum;
	TYPE_LPSUM pSum;
	
	Sum_Init(&Sum);
	Sum_A_B(&Sum, 2, 7);

	printf("%d + %d = %d\n", Sum.nA, Sum.nB, Sum.nSum);

	pSum = Sum_New();
	Sum_Init(pSum);
	Sum_A_to_B_Fast(pSum, 1, 7);

	printf("%d + ... + %d = %d\n", pSum->nA, pSum->nB, pSum->nSum);

	Sum_Delete(pSum);
}