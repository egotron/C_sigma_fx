///////////////////////////////////////////////////////////////////////////////
//
// main.c
//
// Created by Egotron, 2020.11.07
//
// Devtainment, All right reserved.
//
///////////////////////////////////////////////////////////////////////////////

#include "DrinksMachine.h"

void main(void)
{
	TYPE_DRINKSMACHINE DrinksMachine;

	if (DrinksMahcine_Open(&DrinksMachine))
	{
		DrinksMahcine_Run(&DrinksMachine);
		DrinksMahcine_Close(&DrinksMachine);
	}
}
