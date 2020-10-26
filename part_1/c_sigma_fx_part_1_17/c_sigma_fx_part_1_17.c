#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define	SEX_MALE	1
#define	SEX_FEMALE	2

struct tagRecord
{
	char	szName[256];
	int		nAge;
	int		nSex;

	char	cData[1024];
};

struct tagRecord	function_record_set(struct tagRecord aRecord)
{
	aRecord.cData[0] = 'T';
	return aRecord;
}

void	function_record_print(struct tagRecord aRecord)
{
	printf("[Record]\n");
	printf("Name : %s\n", aRecord.szName);
	printf("Age  : %d\n", aRecord.nAge);
	printf("Sex  : %s\n", SEX_MALE == aRecord.nSex ? "Male" : "Female");
	printf("Data : %c\n", aRecord.cData[0]);
}

void	main(void)
{
	struct tagRecord aRecord;
	
	strcpy(aRecord.szName, "Tom Cruze");
	aRecord.nAge = 30;
	aRecord.nSex = SEX_MALE;
	aRecord.cData[0] = 'M';

	function_record_print(aRecord);

	function_record_set(aRecord);

	function_record_print(aRecord);

	aRecord = function_record_set(aRecord);

	function_record_print(aRecord);
}
