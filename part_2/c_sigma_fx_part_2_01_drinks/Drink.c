///////////////////////////////////////////////////////////////////////////////
//
// Drink.c
//
// Created by Egotron, 2020.11.07
//
// Devtainment, All right reserved.
//
///////////////////////////////////////////////////////////////////////////////

#include "Drink.h"
#include <malloc.h>
#include <string.h>

///////////////////////////////////////////////////////////////////////////////
// Attributes
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// Methods
///////////////////////////////////////////////////////////////////////////////

TYPE_LPDRINK	Drink_New()
{
	TYPE_LPDRINK	pTemp = (TYPE_LPDRINK)malloc( sizeof(TYPE_DRINK) );
	if ( null == pTemp )	return null;

	memset( pTemp, 0, sizeof(*pTemp) );

	return pTemp;
}

void			Drink_Delete( TYPE_LPDRINK pDrink )
{
	SAFE_FREE( pDrink );
}

boolean	Drink_Open( TYPE_LPDRINK pDrink )
{
	if ( null == pDrink )	return false;

	memset( pDrink->szName, 0, sizeof(pDrink->szName) );
	pDrink->nPrice = 0;
	pDrink->nProfit = 0;

	return true;
}

void	Drink_Close( TYPE_LPDRINK pDrink )
{
	if ( null == pDrink )	return;

	memset( pDrink, 0, sizeof(*pDrink) );
}

void	Drink_Set( TYPE_LPDRINK pDrink, char* pszName, int nPrice, int nProfit )
{
	strcpy_s( pDrink->szName, sizeof(pDrink->szName), pszName );
	pDrink->nPrice = nPrice;
	pDrink->nProfit = nProfit;
}
