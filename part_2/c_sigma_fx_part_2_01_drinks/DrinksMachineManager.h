///////////////////////////////////////////////////////////////////////////////
//
// DrinksMachineManager.h
//
// Created by Egotron, 2020.11.07
//
// Devtainment, All right reserved.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __DRINKSMACHINEMANAGER_H__
#define	__DRINKSMACHINEMANAGER_H__

#include "DrinksMachine.h"

///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////

typedef struct tagDrinksMachineManager
{
	boolean	bOpened;

	int nMenu_Main;

} TYPE_DRINKSMACHINEMANAGER, *TYPE_LPDRINKSMACHINEMANAGER;

///////////////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////////////

TYPE_LPDRINKSMACHINEMANAGER	DrinksMachineManager_New();
void						DrinksMachineManager_Delete( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager );

boolean	DrinksMachineManager_Open( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager );
void	DrinksMachineManager_Run( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager, TYPE_LPDRINKSMACHINE pDrinksMachine );
void	DrinksMachineManager_Close( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager );

///////////////////////////////////////////////////////////////////////////////
#endif // !__DRINK_H__
