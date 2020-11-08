///////////////////////////////////////////////////////////////////////////////
//
// DrinksMachine.h
//
// Created by Egotron, 2020.11.07
//
// Devtainment, All right reserved.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __DRINKSMACHINE_H__
#define	__DRINKSMACHINE_H__

#include "DrinkSlot.h"

///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////

#define	DRINKSLOT_MAX	4

typedef struct tagDrinksMachine
{
	boolean	bOpened;

	boolean	bRun;

	int		nMoney;

	TYPE_DRINKSLOT	DrinkSlot[ DRINKSLOT_MAX ];
	int		nSelecctDrinkSlot;

	boolean	bSelectDrink;
	boolean bSelectManager;

	int		nSales;
	int		nProfit;

} TYPE_DRINKSMACHINE, *TYPE_LPDRINKSMACHINE;

///////////////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////////////

TYPE_LPDRINKSMACHINE	DrinksMachine_New();
void					DrinksMachine_Delete( TYPE_LPDRINKSMACHINE pDrinksMachine );

boolean	DrinksMahcine_Open( TYPE_LPDRINKSMACHINE pDrinksMachine );
void	DrinksMahcine_Close( TYPE_LPDRINKSMACHINE pDrinksMachine );

void	DrinksMahcine_Run( TYPE_LPDRINKSMACHINE pDrinksMachine );

///////////////////////////////////////////////////////////////////////////////
#endif // !__DRINKSMACHINE_H__
