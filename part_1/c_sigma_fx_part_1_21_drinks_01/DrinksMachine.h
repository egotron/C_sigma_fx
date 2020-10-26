#ifndef __DRINKSMACHINE_H__
#define __DRINKSMACHINE_H__

#include "Define.h"

#define	DRINKSLOT_MAX	4

void	DrinksMachine_DrinkSlot_Print(boolean bManagement);

void	DrinksMachine_SelectDrink();
void	DrinksMachine_CheckMoney();
void	DrinksMachine_DispenseDrink();

void	DrinksMachine_Management();

#endif // !__DRINKSMACHINEMANAGER_H__
