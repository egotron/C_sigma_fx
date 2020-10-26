#include <malloc.h>
#include <memory.h>
#include <string.h>
#include "Drink.h"

TYPE_DRINK* Drink_New()
{
	TYPE_DRINK* pTemp = (TYPE_DRINK*)malloc(sizeof(TYPE_DRINK));
	if (null == pTemp)	return null;

	memset(pTemp, 0, sizeof(*pTemp));

	return pTemp;
}

void	Drink_Delete(TYPE_DRINK* pDrink)
{
	SAFE_FREE(pDrink);
}

void	Drink_Init(TYPE_DRINK* pDrink)
{
	if (null == pDrink)	return;

	memset(pDrink->szName, 0, sizeof(pDrink->szName));
	pDrink->nPrice = 0;
	pDrink->nProfit = 0;
}

void	Drink_Set(TYPE_DRINK* pDrink, char* pszName, int nPrice, int nProfit)
{
	if (null == pDrink)	return;

	strcpy_s(pDrink->szName, sizeof(pDrink->szName), pszName);
	pDrink->nPrice = nPrice;
	pDrink->nProfit = nProfit;
}
