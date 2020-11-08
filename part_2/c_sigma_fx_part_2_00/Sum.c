#include <malloc.h>
#include <memory.h>
#include <string.h>
#include "Sum.h"

///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Methods - declaration
///////////////////////////////////////////////////////////////////////////////

void	Sum_Two(TYPE_LPSUM pSum);
void	Sum_Set_A_B_Ordering(TYPE_LPSUM pSum, int nA, int nB);
void	Sum_Range(TYPE_LPSUM pSum);
void	Sum_Range_Fast(TYPE_LPSUM pSum);

///////////////////////////////////////////////////////////////////////////////
// Methods - public
///////////////////////////////////////////////////////////////////////////////

TYPE_LPSUM Sum_New()
{
	TYPE_LPSUM pTemp = (TYPE_LPSUM)malloc(sizeof(TYPE_SUM));
	if (null == pTemp)	return null;

	memset(pTemp, 0, sizeof(*pTemp));

	return pTemp;
}

void	Sum_Delete(TYPE_LPSUM pSum)
{
	SAFE_FREE(pSum);
}

void	Sum_Init(TYPE_LPSUM pSum)
{
	if (null == pSum)	return;

	memset(pSum, 0, sizeof(*pSum));
}

void	Sum_A_B(TYPE_LPSUM pSum, int nA, int nB)
{
	if (null == pSum)	return;

	pSum->nA = nA;
	pSum->nB = nB;

	Sum_Two(pSum);
}

void	Sum_A_to_B(TYPE_LPSUM pSum, int nA, int nB)
{
	if (null == pSum)	return;

	Sum_Set_A_B_Ordering(pSum, nA, nB);

	Sum_Range(pSum);
}

void	Sum_A_to_B_Fast(TYPE_LPSUM pSum, int nA, int nB)
{
	if (null == pSum)	return;

	Sum_Set_A_B_Ordering(pSum, nA, nB);

	Sum_Range_Fast(pSum);
}

int		Sum_GetResult(TYPE_LPSUM pSum)
{
	return pSum->nSum;
}

///////////////////////////////////////////////////////////////////////////////
// Methods - private
///////////////////////////////////////////////////////////////////////////////

void	Sum_Two(TYPE_LPSUM pSum)
{
	pSum->nSum = pSum->nA + pSum->nB;
}

void	Sum_Set_A_B_Ordering(TYPE_LPSUM pSum, int nA, int nB)
{
	if (nA < nB)
	{
		pSum->nA = nA;
		pSum->nB = nB;
	}
	else
	{
		pSum->nA = nB;
		pSum->nB = nA;
	}
}

void	Sum_Range(TYPE_LPSUM pSum)
{
	pSum->nSum = 0;

	for (int i = pSum->nA; i <= pSum->nB; i++)
	{
		pSum->nSum += i;
	}
}

void	Sum_Range_Fast(TYPE_LPSUM pSum)
{
	int nAdd = pSum->nA + pSum->nB;
	int nRange = (pSum->nB - pSum->nA + 1) / 2;

	pSum->nSum = nAdd * nRange;

	if ((pSum->nB - pSum->nA) != (nRange * 2))	return;

	pSum->nSum += (nAdd / 2);
}
