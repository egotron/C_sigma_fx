#ifndef __SUM_H__
#define __SUM_H__

#include "Define.h"

///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////

typedef struct tagSum
{
	int nA;
	int nB;
	int nSum;
} TYPE_SUM, *TYPE_LPSUM;

///////////////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////////////

TYPE_LPSUM Sum_New();
void	Sum_Delete(TYPE_LPSUM pSum);
void	Sum_Init(TYPE_LPSUM pSum);
void	Sum_A_B(TYPE_LPSUM pSum, int nA, int nB);
void	Sum_A_to_B(TYPE_LPSUM pSum, int nA, int nB);
void	Sum_A_to_B_Fast(TYPE_LPSUM pSum, int nA, int nB);
int		Sum_GetResult(TYPE_LPSUM pSum);

#endif // !__SUM_H__
