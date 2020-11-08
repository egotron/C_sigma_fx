///////////////////////////////////////////////////////////////////////////////
//
// DrinksMachine.c
//
// Created by Egotron, 2020.11.07
//
// Devtainment, All right reserved.
//
///////////////////////////////////////////////////////////////////////////////

#include "DrinksMachine.h"
#include "DrinksMachineManager.h"
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Methods - Declarations
///////////////////////////////////////////////////////////////////////////////

boolean	DrinksMachine_IsOpened( TYPE_LPDRINKSMACHINE pDrinksMachine );

void	DrinksMachine_DrinkSlot_Print( TYPE_LPDRINKSMACHINE pDrinksMachine, boolean bManagement );

void	DrinksMachine_Management( TYPE_LPDRINKSMACHINE pDrinksMachine );

void	DrinksMachine_SelectDrink( TYPE_LPDRINKSMACHINE pDrinksMachine );
void	DrinksMachine_CheckMoney( TYPE_LPDRINKSMACHINE pDrinksMachine );
void	DrinksMachine_DispenseDrink( TYPE_LPDRINKSMACHINE pDrinksMachine );

///////////////////////////////////////////////////////////////////////////////

TYPE_LPDRINKSMACHINE	DrinksMachine_New()
{
	TYPE_LPDRINKSMACHINE	pTemp = (TYPE_LPDRINKSMACHINE)malloc( sizeof(TYPE_DRINKSMACHINE) );
	if ( null == pTemp )	return null;

	memset( pTemp, 0, sizeof(*pTemp) );

	return pTemp;
}

void					DrinksMachine_Delete( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	SAFE_FREE( pDrinksMachine );
}

boolean	DrinksMahcine_Open( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	if ( null == pDrinksMachine )	return false;

	pDrinksMachine->bOpened = true;

	for ( int i = 0; i < DRINKSLOT_MAX; i++ )
	{
		DrinkSlot_Open( &pDrinksMachine->DrinkSlot[ i ] );
	}

	printf("���� �ڵ��Ǹű⸦ �����մϴ�.\n");

	return true;
}

void	DrinksMahcine_Close( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	if ( false == DrinksMachine_IsOpened( pDrinksMachine ) )	return;

	pDrinksMachine->bOpened = false;

	for ( int i = 0; i < DRINKSLOT_MAX; i++ )
	{
		DrinkSlot_Close( &pDrinksMachine->DrinkSlot[ i ] );
	}

	printf("���� �ڵ��Ǹű⸦ �����մϴ�.\n");
}

void	DrinksMahcine_Run( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	if ( false == DrinksMachine_IsOpened( pDrinksMachine ) )	return;

	printf( "���� �ڵ��Ǹű⸦ �����մϴ�.\n" );

	pDrinksMachine->nMoney = 0;
	pDrinksMachine->nSales = 0;
	pDrinksMachine->nProfit = 0;

	pDrinksMachine->bRun = true;
	do {

		DrinksMachine_SelectDrink( pDrinksMachine );

		if ( pDrinksMachine->bSelectDrink )
		{
			DrinksMachine_CheckMoney( pDrinksMachine );
			DrinksMachine_DispenseDrink( pDrinksMachine );
		}
		else if ( pDrinksMachine->bSelectManager )
		{
			DrinksMachine_Management( pDrinksMachine );
		}

	} while ( pDrinksMachine->bRun );
}

///////////////////////////////////////////////////////////////////////////////

boolean	DrinksMachine_IsOpened( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	if ( null == pDrinksMachine )	return false;
	
	return ( pDrinksMachine->bOpened ) ;
}

///////////////////////////////////////////////////////////////////////////////

void	DrinksMachine_SelectDrink( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	boolean bSelected;

	do {
		int nCh;
		int nSelectDrinkSlot;

		printf( "======== ���Ḧ �����ϼ��� ========\n" );

		DrinksMachine_DrinkSlot_Print( pDrinksMachine, true );

		bSelected = false;
		pDrinksMachine->bSelectDrink = false;
		pDrinksMachine->bSelectManager = false;

		nCh = _getch();

		if ('0' == nCh)
		{
			bSelected = true;
			pDrinksMachine->bSelectManager = true;
		}
		else
		{
			nSelectDrinkSlot = nCh - '1';

			if (0 <= nSelectDrinkSlot && nSelectDrinkSlot < DRINKSLOT_MAX)
			{
				if (false == DrinkSlot_IsEmpty( &pDrinksMachine->DrinkSlot[ nSelectDrinkSlot ]) )
				{
					pDrinksMachine->bSelectDrink = true;
					pDrinksMachine->nSelecctDrinkSlot = nSelectDrinkSlot;

					bSelected = true;
				}
			}
		}

	} while ( false == bSelected );
}

void	DrinksMachine_DrinkSlot_Print( TYPE_LPDRINKSMACHINE pDrinksMachine, boolean bManagement )
{
	int i;

	if ( bManagement )	printf( "[ ������ ] " );

	for ( i = 0; i < DRINKSLOT_MAX; i++ )
	{
		TYPE_LPDRINKSLOT pDrinkSlot = &pDrinksMachine->DrinkSlot[ i ];
		if ( DrinkSlot_IsEmpty( pDrinkSlot ) )
		{
			printf( "%d. ���� ����  ", i + 1 );
		}
		else
		{
			printf( "%d. %s (%d��)  ", i + 1, DrinkSlot_GetDrinkName( pDrinkSlot ), DrinkSlot_GetDrinkPrice( pDrinkSlot ) );
		}
	}

	if ( bManagement )	printf( "0. ������\n" );
	else				printf( "\n" );
}

void	DrinksMachine_Management( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	TYPE_DRINKSMACHINEMANAGER DrinksMachineManager;

	DrinksMachineManager_Open( &DrinksMachineManager );
	DrinksMachineManager_Run( &DrinksMachineManager, pDrinksMachine );
	DrinksMachineManager_Close( &DrinksMachineManager );
}

void	DrinksMachine_CheckMoney( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	int nCh;
	boolean bSelected;

	do {
		int nMoney = 0;

		bSelected = false;

		printf( "======== ������ �����ϼ��� ========\n" );
		printf( "1. 1000�� ����  2. 500�� ����  3. 100�� ����  0. ȯ���ϱ�\n" );

		nCh = _getch();

		switch ( nCh )
		{
		case '1': nMoney = 1000; break;
		case '2': nMoney = 500; break;
		case '3': nMoney = 100; break;
		}

		if (nMoney > 0)
		{
			TYPE_LPDRINKSLOT pDrinkSlot = &pDrinksMachine->DrinkSlot[ pDrinksMachine->nSelecctDrinkSlot ];

			pDrinksMachine->nMoney += nMoney;
			if ( pDrinksMachine->nMoney >= DrinkSlot_GetDrinkPrice( pDrinkSlot ) )
			{
				bSelected = true;
			}
		}
		else if ( '0' == nCh )
		{
			pDrinksMachine->nMoney = 0;
			bSelected = true;
		}

		printf("[���� �ݾ�] %d ��\n", pDrinksMachine->nMoney);

	} while ( false == bSelected );
}

void	DrinksMachine_DispenseDrink( TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	TYPE_LPDRINKSLOT pDrinkSlot = &pDrinksMachine->DrinkSlot[ pDrinksMachine->nSelecctDrinkSlot ];
	TYPE_LPDRINK pDrink = DrinkSlot_OutputDrink( pDrinkSlot );

	if ( pDrinksMachine->nMoney <= 0 )	return;

	printf( "%s (%d��) �� ����Ǿ����ϴ�~\n", pDrink->szName, pDrink->nPrice );

	pDrinksMachine->nMoney -= pDrink->nPrice;

	pDrinksMachine->nSales += pDrink->nPrice;
	pDrinksMachine->nProfit += pDrink->nProfit;
}
