#ifndef __DRINK_H__
#define __DRINK_H__

#include "Define.h"

#define	DRINK_NAME_MAX	256

typedef struct tagDrink
{
	char	szName[DRINK_NAME_MAX];
	int		nPrice;
	int		nProfit;
} TYPE_DRINK;

TYPE_DRINK* Drink_New();
void	Drink_Init(TYPE_DRINK* pDrink);
void	Drink_Set(TYPE_DRINK* pDrink, char* pszName, int nPrice, int nProfit);
void	Drink_Delete(TYPE_DRINK* pDrink);

#endif // !__DRINK_H__
