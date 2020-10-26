#ifndef __DRINKSLOT_H__
#define __DRINKSLOT_H__

#include "DrinkLink.h"

#define	DRINKSLOT_DRINK_MAX		10

typedef struct tagDrinkSlot
{
	TYPE_DRINKLINK* pBottom;
	TYPE_DRINKLINK* pTop;

	int					nCount;

} TYPE_DRINKSLOT;

boolean			DrinkSlot_Init(TYPE_DRINKSLOT* pDrinkSlot);
char* DrinkSlot_GetDrinkName(TYPE_DRINKSLOT* pDrinkSlot);
int		DrinkSlot_GetDrinkPrice(TYPE_DRINKSLOT* pDrinkSlot);
boolean	DrinkSlot_IsEmpty(TYPE_DRINKSLOT* pDrinkSlot);
boolean	DrinkSlot_IsFull(TYPE_DRINKSLOT* pDrinkSlot);
int		DrinkSlot_GetCount(TYPE_DRINKSLOT* pDrinkSlot);
void	DrinkSlot_AddDrink(TYPE_DRINKSLOT* pDrinkSlot, TYPE_DRINK* pDrink);
TYPE_DRINK* DrinkSlot_OutputDrink(TYPE_DRINKSLOT* pDrinkSlot);

#endif // !__DRINKSLOT_H__
