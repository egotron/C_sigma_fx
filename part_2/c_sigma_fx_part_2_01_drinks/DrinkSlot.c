///////////////////////////////////////////////////////////////////////////////
//
// DrinkSlot.c
//
// Created by Egotron, 2020.11.07
//
// Devtainment, All right reserved.
//
///////////////////////////////////////////////////////////////////////////////

#include "DrinkSlot.h"
#include <malloc.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////////////

TYPE_LPDRINKLINK	DrinkLink_New()
{
	TYPE_LPDRINKLINK pTemp = (TYPE_LPDRINKLINK)malloc( sizeof(TYPE_DRINKLINK) );
	if ( null == pTemp )	return null;

	memset( pTemp, 0, sizeof(*pTemp) );

	return pTemp;
}

void				DrinkLink_Delete( TYPE_LPDRINKLINK pDrinkLink )
{
	SAFE_FREE( pDrinkLink->pDrink );
	SAFE_FREE( pDrinkLink );
}

void				DrinkLink_AddDrink( TYPE_LPDRINKLINK pDrinkLink, TYPE_LPDRINK pDrink )
{
	pDrinkLink->pDrink = pDrink;
}

TYPE_LPDRINK		DrinkLink_GetDrink( TYPE_LPDRINKLINK pDrinkLink )
{
	return pDrinkLink->pDrink;
}

///////////////////////////////////////////////////////////////////////////////

TYPE_LPDRINKSLOT	DrinkSlot_New()
{
	TYPE_LPDRINKSLOT	pTemp = (TYPE_LPDRINKSLOT)malloc( sizeof(TYPE_DRINKSLOT) );
	if ( null == pTemp )	return null;

	memset( pTemp, 0, sizeof(*pTemp) );

	return pTemp;
}

void				DrinkSlot_Delete( TYPE_LPDRINKSLOT pDrinkSlot )
{
	SAFE_FREE( pDrinkSlot );
}

boolean	DrinkSlot_Open( TYPE_LPDRINKSLOT pDrinkSlot )
{
	if ( null == pDrinkSlot )	return false;

	pDrinkSlot->pTop = null;
	pDrinkSlot->pBottom = null;

	pDrinkSlot->nCount = 0;

	return true;
}

void	DrinkSlot_Close( TYPE_LPDRINKSLOT pDrinkSlot )
{
	if ( null == pDrinkSlot )	return;

	memset( pDrinkSlot, 0, sizeof(*pDrinkSlot) );
}

char*	DrinkSlot_GetDrinkName( TYPE_LPDRINKSLOT pDrinkSlot )
{
	TYPE_LPDRINK pDrink;

	if ( null == pDrinkSlot )	return null;

	pDrink = DrinkLink_GetDrink( pDrinkSlot->pBottom );
	if ( null == pDrink )	return null;

	return pDrink->szName;
}

int		DrinkSlot_GetDrinkPrice( TYPE_LPDRINKSLOT pDrinkSlot )
{
	TYPE_LPDRINK pDrink;

	if ( null == pDrinkSlot )	return 0;

	pDrink = DrinkLink_GetDrink( pDrinkSlot->pBottom );
	if ( null == pDrink )	return 0;

	return pDrink->nPrice;
}

boolean	DrinkSlot_IsEmpty( TYPE_LPDRINKSLOT pDrinkSlot )
{
	if ( null == pDrinkSlot )	return true;

	return pDrinkSlot->nCount <= 0;
}

boolean	DrinkSlot_IsFull( TYPE_LPDRINKSLOT pDrinkSlot )
{
	if ( null == pDrinkSlot )	return true;

	return pDrinkSlot->nCount >= DRINKSLOT_DRINK_MAX;
}

int		DrinkSlot_GetCount( TYPE_LPDRINKSLOT pDrinkSlot )
{
	if (null == pDrinkSlot)	return 0;

	return pDrinkSlot->nCount;
}

void	DrinkSlot_AddDrink( TYPE_LPDRINKSLOT pDrinkSlot, TYPE_LPDRINK pDrink )
{
	TYPE_LPDRINKLINK pDrinkLink = DrinkLink_New();
	DrinkLink_AddDrink( pDrinkLink, pDrink );

	if ( null == pDrinkSlot->pTop )
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

TYPE_LPDRINK	DrinkSlot_OutputDrink( TYPE_LPDRINKSLOT pDrinkSlot )
{
	TYPE_LPDRINKLINK pDrinkLink = pDrinkSlot->pBottom;
	TYPE_LPDRINK pDrink = pDrinkLink->pDrink;

	if ( null == pDrinkLink )	return null;

	pDrinkSlot->pBottom = pDrinkLink->pNext;

	pDrinkLink->pDrink = null;
	DrinkLink_Delete( pDrinkLink );

	pDrinkSlot->nCount--;

	return pDrink;
}
