#include <stdio.h>

void	function_matrix_identify(int (*pnMatrix)[4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)	pnMatrix[i][j] = 1;
			else		pnMatrix[i][j] = 0;
		}
	}
}

void	main(void)
{
	// Array pointer
	char	cDigit = 'A';
	char*   pcDigit = &cDigit;
	
	char	szDigits[] = "0123456789";
	char*   pszDigits = szDigits;

	int		nMatrix[4][4];
	int		(*pnMatrix)[4] = nMatrix;

	// Pointer Array
	char	szTextArray0[] = "a";
	char	szTextArray1[] = "ab";
	char	szTextArray2[] = "abc";
	char	szTextArray3[] = "abcd";

	char*   pszTextArray[] = { szTextArray0, szTextArray1, szTextArray2, szTextArray3 };

	printf("[ Array Pointer ]\n");
	
	printf("pcDigit = %c\n", *pcDigit);
	printf("pszDigits = %s\n", pszDigits);

	function_matrix_identify(pnMatrix);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("pnMatrix[%d][%d] = %d", i, j, pnMatrix[i][j]);
			if (j < 4 - 1)	printf(", ");
			else			printf("\n");
		}
	}

	printf("[ Pointer Array ]\n");

	printf("szTextArray0 = %s\n", szTextArray0);
	printf("szTextArray1 = %s\n", szTextArray1);
	printf("szTextArray2 = %s\n", szTextArray2);
	printf("szTextArray3 = %s\n", szTextArray3);

	for (int i = 0; i < 4; i++)
	{
		printf("pszTextArray[%d] = %s\n", i, pszTextArray[i]);
	}

}
