#include <malloc.h>
#include <memory.h>
#include <string.h>
#include "DrinkSlot.h"

boolean			DrinkSlot_Init(TYPE_DRINKSLOT* pDrinkSlot)
{
	if (null == pDrinkSlot)	return false;

	pDrinkSlot->pTop = null;
	pDrinkSlot->pBottom = null;

	pDrinkSlot->nCount = 0;

	return true;
}

char* DrinkSlot_GetDrinkName(TYPE_DRINKSLOT* pDrinkSlot)
{
	TYPE_DRINK* pDrink;

	if (null == pDrinkSlot)	return null;

	pDrink = DrinkLink_GetDrink(pDrinkSlot->pBottom);
	if (null == pDrink)	return null;

	return pDrink->szName;
}

int		DrinkSlot_GetDrinkPrice(TYPE_DRINKSLOT* pDrinkSlot)
{
	TYPE_DRINK* pDrink;

	if (null == pDrinkSlot)	return 0;

	pDrink = DrinkLink_GetDrink(pDrinkSlot->pBottom);
	if (null == pDrink)	return 0;

	return pDrink->nPrice;
}

boolean	DrinkSlot_IsEmpty(TYPE_DRINKSLOT* pDrinkSlot)
{
	if (null == pDrinkSlot)	return true;

	return pDrinkSlot->nCount <= 0;
}

boolean	DrinkSlot_IsFull(TYPE_DRINKSLOT* pDrinkSlot)
{
	if (null == pDrinkSlot)	return true;

	return pDrinkSlot->nCount >= DRINKSLOT_DRINK_MAX;
}

int		DrinkSlot_GetCount(TYPE_DRINKSLOT* pDrinkSlot)
{
	if (null == pDrinkSlot)	return 0;

	return pDrinkSlot->nCount;
}

void	DrinkSlot_AddDrink(TYPE_DRINKSLOT* pDrinkSlot, TYPE_DRINK* pDrink)
{
	TYPE_DRINKLINK* pDrinkLink = DrinkLink_New();
	DrinkLink_AddDrink(pDrinkLink, pDrink);

	if (null == pDrinkSlot->pTop)
	{
		pDrinkSlot->pTop = pDrinkLink;
		pDrinkSlot->pBottom = pDrinkLink;
	}
	else
	{
		pDrinkSlot->pTop->pNext = pDrinkLink;
		pDrinkSlot->pTop = pDrinkLink;
	}

	pDrinkSlot->nCount++;
}

TYPE_DRINK* DrinkSlot_OutputDrink(TYPE_DRINKSLOT* pDrinkSlot)
{
	TYPE_DRINKLINK* pDrinkLink = pDrinkSlot->pBottom;
	TYPE_DRINK* pDrink = pDrinkLink->pDrink;

	if (null == pDrinkLink)	return null;

	pDrinkSlot->pBottom = pDrinkLink->pNext;

	pDrinkLink->pDrink = null;
	DrinkLink_Delete(pDrinkLink);

	pDrinkSlot->nCount--;

	return pDrink;
}
