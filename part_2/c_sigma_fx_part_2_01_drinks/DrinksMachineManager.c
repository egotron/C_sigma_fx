///////////////////////////////////////////////////////////////////////////////
//
// DrinksMahcineManager.c
//
// Created by Egotron, 2020.11.07
//
// Devtainment, All right reserved.
//
///////////////////////////////////////////////////////////////////////////////

#include "DrinksMachineManager.h"
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Methods - Declarations
///////////////////////////////////////////////////////////////////////////////

void	DrinksMachineManager_Menu_Main( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager, TYPE_LPDRINKSMACHINE pDrinksMahchine );
void	DrinksMachineManager_DrinkSlot_Print( TYPE_LPDRINKSMACHINE pDrinksMachine, boolean bManagement );

void	DrinksMachineManager_Menu_DrinkAdd( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager, TYPE_LPDRINKSMACHINE pDrinksMachine );
void	DrinksMachineManager_Menu_Sales( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager, TYPE_LPDRINKSMACHINE pDrinksMachine );

///////////////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////////////

TYPE_LPDRINKSMACHINEMANAGER	DrinksMachineManager_New()
{
	TYPE_LPDRINKSMACHINEMANAGER	pTemp = (TYPE_LPDRINKSMACHINEMANAGER)malloc( sizeof(TYPE_LPDRINKSMACHINEMANAGER) );
	if ( null == pTemp )	return null;

	memset( pTemp, 0, sizeof(*pTemp) );

	return pTemp;
}

void						DrinksMachineManager_Delete( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager )
{
	SAFE_FREE( pDrinksMachineManager );
}

///////////////////////////////////////////////////////////////////////////////

boolean	DrinksMachineManager_Open( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager )
{
	if ( null == pDrinksMachineManager )	return false;

	pDrinksMachineManager->bOpened = true;

	return true;
}

void	DrinksMachineManager_Close( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager )
{
	if ( null == pDrinksMachineManager )	return;
	if ( false == pDrinksMachineManager->bOpened )	return;

	memset( pDrinksMachineManager, 0, sizeof(*pDrinksMachineManager) );
}

///////////////////////////////////////////////////////////////////////////////

void	DrinksMachineManager_Run( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager, TYPE_LPDRINKSMACHINE pDrinksMahchine )
{
	boolean bLoop;

	do {
		bLoop = true;

		DrinksMachineManager_Menu_Main( pDrinksMachineManager, pDrinksMahchine );

		switch ( pDrinksMachineManager->nMenu_Main )
		{
		case 1:
			DrinksMachineManager_Menu_DrinkAdd( pDrinksMachineManager, pDrinksMahchine );
			break;
		case 2:
			DrinksMachineManager_Menu_Sales( pDrinksMachineManager, pDrinksMahchine );
			break;
		case 3: case 0:
			bLoop = false;
			break;
		}

	} while ( bLoop );
}

///////////////////////////////////////////////////////////////////////////////

void	DrinksMachineManager_Menu_Main( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager, TYPE_LPDRINKSMACHINE pDrinksMahchine )
{
	boolean bSelected = false;

	do {
		int nCh;

		printf( "[ ������ ] ======== �޴��� �����ϼ��� ========\n" );
		printf( "[ ������ ] 1. ���� �߰�  2. �����ϱ�  3. ������  0. ���� ����\n" );

		bSelected = false;
		pDrinksMachineManager->nMenu_Main = 0;

		nCh = _getch();

		switch ( nCh )
		{
		case '1': case '2': case '3':
			pDrinksMachineManager->nMenu_Main = nCh - '0';
			bSelected = true;
			break;
		case '0':
			pDrinksMachineManager->nMenu_Main = 0;
			pDrinksMahchine->bRun = false;
			bSelected = true;
			break;
		}

	} while ( false == bSelected );
}

///////////////////////////////////////////////////////////////////////////////

void	DrinksMachineManager_Menu_DrinkAdd( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager, TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	TYPE_LPDRINKSLOT pDrinkSlot;

	boolean bSelected = false;

	do {
		int nCh;

		printf( "[ ������ ] ���� ������ �����ϼ���\n" );
		DrinksMachineManager_DrinkSlot_Print( pDrinksMachine, false );

		bSelected = false;

		nCh = _getch();

		if ( '0' == nCh )
		{
			bSelected = true;
		}
		else if ( 0 <= nCh - '1' && nCh - '1' < DRINKSLOT_MAX )
		{
			pDrinkSlot = &pDrinksMachine->DrinkSlot[ nCh - '1' ];
			if ( DrinkSlot_IsFull( pDrinkSlot ) )
			{
				printf( "������ �� á���ϴ� !\n" );
				bSelected = true;
			}
			else
			{
				TYPE_DRINK aDrink;
				Drink_Open( &aDrink );

				printf( "[ ������ ] ���� �̸��� �Է��ϼ���\n" );
				scanf_s( "%s", aDrink.szName, (unsigned)_countof( aDrink.szName ) );

				printf( "[ ������ ] ���� ����(��)�� �Է��ϼ���\n" );
				scanf_s( "%d", &aDrink.nPrice );

				printf( "[ ������ ] ���� ����(��)�� �Է��ϼ���\n" );
				scanf_s( "%d", &aDrink.nProfit );

				do {
					printf("[ ������ ] ���Ḧ �߰��Ͻðڽ��ϱ�?\n1.��  2.�ƴϿ�\n");

					nCh = _getch();

					if ( '1' == nCh )
					{
						TYPE_LPDRINK pDrink = Drink_New();
						if ( null != pDrink )
						{
							Drink_Set( pDrink, aDrink.szName, aDrink.nPrice, aDrink.nProfit );
							DrinkSlot_AddDrink( pDrinkSlot, pDrink );

							printf( "[ ������ ] ����(�� %d��)�� �߰��Ǿ����ϴ�.\n", DrinkSlot_GetCount( pDrinkSlot ) );

							if ( DrinkSlot_IsFull( pDrinkSlot ) )
							{
								printf( "[ ������ ] �� �̻� �߰��� �� �����ϴ�.\n" );
								nCh = '2';
								bSelected = true;
							}
						}
					}
					else if ( '2' == nCh )
					{
						bSelected = true;
					}

				} while ( '2' != nCh );

			}
		}

	} while ( false == bSelected );
}

///////////////////////////////////////////////////////////////////////////////

void	DrinksMachineManager_Menu_Sales( TYPE_LPDRINKSMACHINEMANAGER pDrinksMachineManager, TYPE_LPDRINKSMACHINE pDrinksMachine )
{
	printf( "[ ������ ] ���� ����\n" );
	printf( "[ ������ ] �Ǹ� �Ѿ� = %d ��\n", pDrinksMachine->nSales );
	printf( "[ ������ ] ���� �Ѿ� = %d ��\n", pDrinksMachine->nProfit );
}

///////////////////////////////////////////////////////////////////////////////

void	DrinksMachineManager_DrinkSlot_Print( TYPE_LPDRINKSMACHINE pDrinksMachine, boolean bManagement )
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
