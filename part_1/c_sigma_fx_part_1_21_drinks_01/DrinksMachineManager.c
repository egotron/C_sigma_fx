#include <conio.h>
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Drink.h"
#include "DrinkSlot.h"
#include "DrinksMachine.h"
#include "DrinksMachineManager.h"

extern boolean	g_bRun;

extern int		g_nMoney;

extern TYPE_DRINKSLOT	g_DrinkSlot[DRINKSLOT_MAX];
extern int				g_nSelecctDrinkSlot;

extern boolean	g_bSelectDrink;
extern boolean g_bSelectManager;

extern int		g_nSales;
extern int		g_nProfit;

extern int g_nMenu_Main;

void	DrinksMachineManager_Menu_Main()
{
	boolean bSelected = false;

	do {
		int nCh;

		printf("[ 관리자 ] ======== 메뉴를 선택하세요 ========\n");
		printf("[ 관리자 ] 1. 음료 추가  2. 정산하기  3. 나가기  0. 전원 끄기\n");

		bSelected = false;
		g_nMenu_Main = 0;

		nCh = _getch();

		switch (nCh)
		{
		case '1': case '2': case '3':
			g_nMenu_Main = nCh - '0';
			bSelected = true;
			break;
		case '0':
			g_nMenu_Main = 0;
			g_bRun = false;
			bSelected = true;
			break;
		}

	} while (false == bSelected);
}

void	DrinksMachineManager_Menu_DrinkAdd()
{
	TYPE_DRINKSLOT* pDrinkSlot;

	boolean bSelected = false;

	do {
		int nCh;

		printf("[ 관리자 ] 음료 슬롯을 선택하세요\n");
		DrinksMachineManager_DrinkSlot_Print(false);

		bSelected = false;

		nCh = _getch();

		if ('0' == nCh)
		{
			bSelected = true;
		}
		else if (0 <= nCh - '1' && nCh - '1' < DRINKSLOT_MAX)
		{
			pDrinkSlot = &g_DrinkSlot[nCh - '1'];
			if (DrinkSlot_IsFull(pDrinkSlot))
			{
				printf("슬롯이 꽉 찼습니다 !\n");
				bSelected = true;
			}
			else
			{
				TYPE_DRINK aDrink;
				Drink_Init(&aDrink);

				printf("[ 관리자 ] 음료 이름을 입력하세요\n");
				scanf_s("%s", aDrink.szName, (unsigned)_countof(aDrink.szName));

				printf("[ 관리자 ] 음료 가격(원)을 입력하세요\n");
				scanf_s("%d", &aDrink.nPrice);

				printf("[ 관리자 ] 음료 이윤(원)을 입력하세요\n");
				scanf_s("%d", &aDrink.nProfit);

				do {
					printf("[ 관리자 ] 음료를 추가하시겠습니까?\n1.예  2.아니오\n");

					nCh = _getch();

					if ('1' == nCh)
					{
						TYPE_DRINK* pDrink = Drink_New();
						if (null != pDrink)
						{
							Drink_Set(pDrink, aDrink.szName, aDrink.nPrice, aDrink.nProfit);
							DrinkSlot_AddDrink(pDrinkSlot, pDrink);

							printf("[ 관리자 ] 음료(총 %d개)가 추가되었습니다.\n", DrinkSlot_GetCount(pDrinkSlot));

							if (DrinkSlot_IsFull(pDrinkSlot))
							{
								printf("[ 관리자 ] 더 이상 추가할 수 없습니다.\n");
								nCh = '2';
								bSelected = true;
							}
						}
					}
					else if ('2' == nCh)
					{
						bSelected = true;
					}

				} while ('2' != nCh);

			}
		}

	} while (false == bSelected);
}

void	DrinksMachineManager_Menu_Sales()
{
	printf("[ 관리자 ] 정산 정보\n");
	printf("[ 관리자 ] 판매 총액 = %d 원\n", g_nSales);
	printf("[ 관리자 ] 이윤 총액 = %d 원\n", g_nProfit);
}

void	DrinksMachineManager_DrinkSlot_Print(boolean bManagement)
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
