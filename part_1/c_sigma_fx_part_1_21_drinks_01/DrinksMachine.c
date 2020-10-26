#include <conio.h>
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drink.h"
#include "DrinkSlot.h"
#include "DrinksMachineManager.h"
#include "DrinksMachine.h"

extern boolean	g_bRun;

extern int		g_nMoney;

extern TYPE_DRINKSLOT	g_DrinkSlot[DRINKSLOT_MAX];
extern int				g_nSelecctDrinkSlot;

extern boolean	g_bSelectDrink;
extern boolean g_bSelectManager;

extern int		g_nSales;
extern int		g_nProfit;

extern int g_nMenu_Main;

void	DrinksMachine_SelectDrink()
{
	boolean bSelected;

	do {
		int nCh;
		int nSelectDrinkSlot;

		printf("======== 음료를 선택하세요 ========\n");

		DrinksMachine_DrinkSlot_Print(true);

		bSelected = false;
		g_bSelectDrink = false;
		g_bSelectManager = false;

		nCh = _getch();

		if ('0' == nCh)
		{
			bSelected = true;
			g_bSelectManager = true;
		}
		else
		{
			nSelectDrinkSlot = nCh - '1';

			if (0 <= nSelectDrinkSlot && nSelectDrinkSlot < DRINKSLOT_MAX)
			{
				if (false == DrinkSlot_IsEmpty(&g_DrinkSlot[nSelectDrinkSlot]))
				{
					g_bSelectDrink = true;
					g_nSelecctDrinkSlot = nSelectDrinkSlot;

					bSelected = true;
				}
			}
		}

	} while (false == bSelected);
}

void	DrinksMachine_DrinkSlot_Print(boolean bManagement)
{
	int i;

	if (bManagement)	printf("[ 관리자 ] ");

	for (i = 0; i < DRINKSLOT_MAX; i++)
	{
		TYPE_DRINKSLOT* pDrinkSlot = &g_DrinkSlot[i];
		if (DrinkSlot_IsEmpty(pDrinkSlot))
		{
			printf("%d. 음료 없음  ", i + 1);
		}
		else
		{
			printf("%d. %s (%d원)  ", i + 1, DrinkSlot_GetDrinkName(pDrinkSlot), DrinkSlot_GetDrinkPrice(pDrinkSlot));
		}
	}

	if (bManagement)	printf("0. 관리자\n");
	else				printf("\n");
}

void	DrinksMachine_Management()
{
	boolean bLoop;

	do {
		bLoop = true;

		DrinksMachineManager_Menu_Main();

		switch (g_nMenu_Main)
		{
		case 1:
			DrinksMachineManager_Menu_DrinkAdd();
			break;
		case 2:
			DrinksMachineManager_Menu_Sales();
			break;
		case 3: case 0:
			bLoop = false;
			break;
		}

	} while (bLoop);
}

void	DrinksMachine_CheckMoney()
{
	int nCh;
	boolean bSelected;

	do {
		int nMoney = 0;

		bSelected = false;

		printf("======== 다음을 선택하세요 ========\n");
		printf("1. 1000원 투입  2. 500원 투입  3. 100원 투입  0. 환불하기\n");

		nCh = _getch();

		switch (nCh)
		{
		case '1': nMoney = 1000; break;
		case '2': nMoney = 500; break;
		case '3': nMoney = 100; break;
		}

		if (nMoney > 0)
		{
			TYPE_DRINKSLOT* pDrinkSlot = &g_DrinkSlot[g_nSelecctDrinkSlot];

			g_nMoney += nMoney;
			if (g_nMoney >= DrinkSlot_GetDrinkPrice(pDrinkSlot))
			{
				bSelected = true;
			}
		}
		else if ('0' == nCh)
		{
			g_nMoney = 0;
			bSelected = true;
		}

		printf("[투입 금액] %d 원\n", g_nMoney);

	} while (false == bSelected);
}

void	DrinksMachine_DispenseDrink()
{
	TYPE_DRINKSLOT* pDrinkSlot = &g_DrinkSlot[g_nSelecctDrinkSlot];
	TYPE_DRINK* pDrink = DrinkSlot_OutputDrink(pDrinkSlot);

	if (g_nMoney <= 0)	return;

	printf("%s (%d원) 가 배출되었습니다~\n", pDrink->szName, pDrink->nPrice);

	g_nMoney -= pDrink->nPrice;

	g_nSales += pDrink->nPrice;
	g_nProfit += pDrink->nProfit;
}
