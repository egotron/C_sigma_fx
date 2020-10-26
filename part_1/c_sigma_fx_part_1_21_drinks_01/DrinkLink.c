#include <malloc.h>
#include <memory.h>
#include "DrinkLink.h"

TYPE_DRINKLINK* DrinkLink_New()
{
	TYPE_DRINKLINK* pTemp = (TYPE_DRINKLINK*)malloc(sizeof(TYPE_DRINKLINK));
	if (null == pTemp)	return null;

	memset(pTemp, 0, sizeof(*pTemp));

	return pTemp;
}

void			DrinkLink_Delete(TYPE_DRINKLINK* pDrinkLink)
{
	SAFE_FREE(pDrinkLink->pDrink);
	SAFE_FREE(pDrinkLink);
}

void			DrinkLink_AddDrink(TYPE_DRINKLINK* pDrinkLink, TYPE_DRINK* pDrink)
{
	pDrinkLink->pDrink = pDrink;
}

TYPE_DRINK* DrinkLink_GetDrink(TYPE_DRINKLINK* pDrinkLink)
{
	return pDrinkLink->pDrink;
}
