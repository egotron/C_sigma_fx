///////////////////////////////////////////////////////////////////////////////
//
// DrinkSlot.h
//
// Created by Egotron, 2020.11.07
//
// Devtainment, All right reserved.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __DRINKSLOT_H__
#define	__DRINKSLOT_H__

#include "Drink.h"


///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////

#define	DRINKSLOT_DRINK_MAX		10

typedef struct tagDrinkLink*	TYPE_LPDRINKLINK;

typedef struct tagDrinkLink
{
	TYPE_LPDRINK		pDrink;
	TYPE_LPDRINKLINK	pNext;

} TYPE_DRINKLINK;

typedef struct tagDrinkSlot
{
	TYPE_LPDRINKLINK	pBottom;
	TYPE_LPDRINKLINK	pTop;

	int					nCount;

} TYPE_DRINKSLOT, *TYPE_LPDRINKSLOT;

///////////////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////////////

TYPE_LPDRINKSLOT	DrinkSlot_New();
void				DrinkSlot_Delete( TYPE_LPDRINKSLOT pDrinkSlot );

boolean	DrinkSlot_Open( TYPE_LPDRINKSLOT pDrinkSlot );
void	DrinkSlot_Close( TYPE_LPDRINKSLOT pDrinkSlot );

char*	DrinkSlot_GetDrinkName( TYPE_LPDRINKSLOT pDrinkSlot );
int		DrinkSlot_GetDrinkPrice( TYPE_LPDRINKSLOT pDrinkSlot );

boolean	DrinkSlot_IsEmpty( TYPE_LPDRINKSLOT pDrinkSlot );
boolean	DrinkSlot_IsFull( TYPE_LPDRINKSLOT pDrinkSlot );
int		DrinkSlot_GetCount( TYPE_LPDRINKSLOT pDrinkSlot );

void	DrinkSlot_AddDrink( TYPE_LPDRINKSLOT pDrinkSlot, TYPE_LPDRINK pDrink );
TYPE_LPDRINK	DrinkSlot_OutputDrink( TYPE_LPDRINKSLOT pDrinkSlot );

///////////////////////////////////////////////////////////////////////////////
#endif // !__DRINKSLOT_H__
