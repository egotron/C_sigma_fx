#include <stdio.h>
#include "DrinksMachine.h"
#include "DrinkSlot.h"

///////////////////////////////////////////////////////////////////////////////

boolean	g_bRun;

int		g_nMoney;

TYPE_DRINKSLOT	g_DrinkSlot[DRINKSLOT_MAX];
int				g_nSelecctDrinkSlot;

boolean	g_bSelectDrink;
boolean g_bSelectManager;

int		g_nSales;
int		g_nProfit;

int g_nMenu_Main;

void	main(void)
{
	for (int i = 0; i < DRINKSLOT_MAX; i++)
	{
		DrinkSlot_Init(&g_DrinkSlot[i]);
	}

	printf("음료 자동판매기를 시작합니다.\n");

	g_nMoney = 0;
	g_nSales = 0;
	g_nProfit = 0;

	g_bRun = true;
	do {

		DrinksMachine_SelectDrink();

		if (g_bSelectDrink)
		{
			DrinksMachine_CheckMoney();
			DrinksMachine_DispenseDrink();
		}
		else if (g_bSelectManager)
		{
			DrinksMachine_Management();
		}

	} while (g_bRun);


	printf("음료 자동판매기를 중지합니다.\n");
}
