#include <conio.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////

typedef unsigned int	dword;
typedef unsigned int	udword;
typedef			 int	sdword;

typedef unsigned short	uword;
typedef			 short	sword;

typedef unsigned char	ubyte;
typedef			 char	sbyte;
typedef			 char	boolean;

#define	true			1
#define	false			0
#define	null			0

#define	RAND(x)		(rand()%(x))

#define	SAFE_FREE( x )			{ if ( x ) { free( x ); ( x ) = null; } }
#define	SAFE_RELEASE( x )		{ if ( x ) { ( x )->Release( x ); ( x ) = null; } }
#define	SAFE_RELEASE_VT( x )	{ if ( x ) { ( x )->lpVtbl->Release( x ); ( x ) = null; } }

///////////////////////////////////////////////////////////////////////////////

#define	DRINK_NAME_MAX	256

typedef struct tagDrink
{
	char	szName[DRINK_NAME_MAX];
	int		nPrice;
	int		nProfit;
} TYPE_DRINK;

TYPE_DRINK*	Drink_New()
{
	TYPE_DRINK*	pTemp = (TYPE_DRINK*)malloc(sizeof(TYPE_DRINK));
	if (null == pTemp)	return null;

	memset(pTemp, 0, sizeof(*pTemp));

	return pTemp;
}

void		Drink_Delete(TYPE_DRINK* pDrink)
{
	SAFE_FREE(pDrink);
}

void	Drink_Init(TYPE_DRINK* pDrink)
{
	if (null == pDrink)	return;

	memset(pDrink->szName, 0, sizeof(pDrink->szName));
	pDrink->nPrice = 0;
	pDrink->nProfit = 0;
}

void	Drink_Set(TYPE_DRINK* pDrink, char* pszName, int nPrice, int nProfit)
{
	if (null == pDrink)	return;

	strcpy_s(pDrink->szName, sizeof(pDrink->szName), pszName);
	pDrink->nPrice = nPrice;
	pDrink->nProfit = nProfit;
}

///////////////////////////////////////////////////////////////////////////////

#define	DRINKSLOT_DRINK_MAX		10

typedef struct tagDrinkLink
{
	TYPE_DRINK*				pDrink;
	struct tagDrinkLink*	pNext;

} TYPE_DRINKLINK;

typedef struct tagDrinkSlot
{
	TYPE_DRINKLINK*	pBottom;
	TYPE_DRINKLINK*	pTop;

	int					nCount;

} TYPE_DRINKSLOT;

TYPE_DRINKLINK*	DrinkLink_New()
{
	TYPE_DRINKLINK* pTemp = (TYPE_DRINKLINK*)malloc(sizeof(TYPE_DRINKLINK));
	if (null == pTemp)	return null;

	memset(pTemp, 0, sizeof(*pTemp));

	return pTemp;
}

void			DrinkLink_Delete(TYPE_DRINKLINK* pDrinkLink)
{
	SAFE_FREE(pDrinkLink->pDrink);
	SAFE_FREE(pDrinkLink);
}

void			DrinkLink_AddDrink(TYPE_DRINKLINK* pDrinkLink, TYPE_DRINK* pDrink)
{
	pDrinkLink->pDrink = pDrink;
}

TYPE_DRINK*		DrinkLink_GetDrink(TYPE_DRINKLINK* pDrinkLink)
{
	return pDrinkLink->pDrink;
}

boolean			DrinkSlot_Init(TYPE_DRINKSLOT* pDrinkSlot)
{
	if (null == pDrinkSlot)	return false;

	pDrinkSlot->pTop = null;
	pDrinkSlot->pBottom = null;

	pDrinkSlot->nCount = 0;

	return true;
}

char*	DrinkSlot_GetDrinkName(TYPE_DRINKSLOT* pDrinkSlot)
{
	TYPE_DRINK* pDrink;

	if (null == pDrinkSlot)	return null;

	pDrink = DrinkLink_GetDrink(pDrinkSlot->pBottom);
	if (null == pDrink)	return null;

	return pDrink->szName;
}

int		DrinkSlot_GetDrinkPrice(TYPE_DRINKSLOT* pDrinkSlot)
{
	TYPE_DRINK* pDrink;

	if (null == pDrinkSlot)	return 0;

	pDrink = DrinkLink_GetDrink(pDrinkSlot->pBottom);
	if (null == pDrink)	return 0;

	return pDrink->nPrice;
}

boolean	DrinkSlot_IsEmpty(TYPE_DRINKSLOT* pDrinkSlot)
{
	if (null == pDrinkSlot)	return true;

	return pDrinkSlot->nCount <= 0;
}

boolean	DrinkSlot_IsFull(TYPE_DRINKSLOT* pDrinkSlot)
{
	if (null == pDrinkSlot)	return true;

	return pDrinkSlot->nCount >= DRINKSLOT_DRINK_MAX;
}

int		DrinkSlot_GetCount(TYPE_DRINKSLOT* pDrinkSlot)
{
	if (null == pDrinkSlot)	return 0;

	return pDrinkSlot->nCount;
}

void	DrinkSlot_AddDrink(TYPE_DRINKSLOT* pDrinkSlot, TYPE_DRINK* pDrink)
{
	TYPE_DRINKLINK* pDrinkLink = DrinkLink_New();
	DrinkLink_AddDrink(pDrinkLink, pDrink);

	if (null == pDrinkSlot->pTop)
	{
		pDrinkSlot->pTop = pDrinkLink;
		pDrinkSlot->pBottom = pDrinkLink;
	}
	else
	{
		pDrinkSlot->pTop->pNext = pDrinkLink;
		pDrinkSlot->pTop = pDrinkLink;
	}

	pDrinkSlot->nCount++;
}

TYPE_DRINK*	DrinkSlot_OutputDrink(TYPE_DRINKSLOT* pDrinkSlot)
{
	TYPE_DRINKLINK* pDrinkLink = pDrinkSlot->pBottom;
	TYPE_DRINK* pDrink = pDrinkLink->pDrink;

	if (null == pDrinkLink)	return null;

	pDrinkSlot->pBottom = pDrinkLink->pNext;

	pDrinkLink->pDrink = null;
	DrinkLink_Delete(pDrinkLink);

	pDrinkSlot->nCount--;

	return pDrink;
}

///////////////////////////////////////////////////////////////////////////////

#define	DRINKSLOT_MAX	4

boolean	g_bRun;

int		g_nMoney;

TYPE_DRINKSLOT	g_DrinkSlot[DRINKSLOT_MAX];
int				g_nSelecctDrinkSlot;

boolean	g_bSelectDrink;
boolean g_bSelectManager;

int		g_nSales;
int		g_nProfit;

int g_nMenu_Main;

///////////////////////////////////////////////////////////////////////////////

void	DrinksMachine_DrinkSlot_Print(boolean bManagement);

void	DrinksMachine_SelectDrink();
void	DrinksMachine_CheckMoney();
void	DrinksMachine_DispenseDrink();

void	DrinksMachine_Management();

void	DrinksMachineManager_Menu_Main();
void	DrinksMachineManager_Menu_DrinkAdd();
void	DrinksMachineManager_Menu_Sales();
void	DrinksMachineManager_DrinkSlot_Print(boolean bManagement);

///////////////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////////////



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

///////////////////////////////////////////////////////////////////////////////

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
