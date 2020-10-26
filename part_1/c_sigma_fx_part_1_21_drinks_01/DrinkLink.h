#ifndef __DRINKLINK_H__
#define __DRINKLINK_H__

#include "Drink.h"

typedef struct tagDrinkLink
{
	TYPE_DRINK* pDrink;
	struct tagDrinkLink* pNext;

} TYPE_DRINKLINK;

TYPE_DRINKLINK* DrinkLink_New();
void			DrinkLink_Delete(TYPE_DRINKLINK* pDrinkLink);
void			DrinkLink_AddDrink(TYPE_DRINKLINK* pDrinkLink, TYPE_DRINK* pDrink);
TYPE_DRINK* DrinkLink_GetDrink(TYPE_DRINKLINK* pDrinkLink);

#endif // !__DRINKLINK_H__
