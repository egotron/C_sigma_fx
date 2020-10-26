#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>

#define	SEX_MALE	1
#define	SEX_FEMALE	2

struct tagRecord
{
	char	szName[256];
	int		nAge;
	int		nSex;

	char	cData[1024];
};

struct tagRecord	function_record_set_call_by_value(struct tagRecord aRecord)
{
	aRecord.cData[0] = 'T';
	return aRecord;
}

void				function_record_set_call_by_reference(struct tagRecord *paRecord)
{
	paRecord->cData[0] = 'T';
}

void	function_record_print(struct tagRecord *paRecord, time_t ltime)
{
	printf("[Record]\n");
	printf("Name : %s\n", paRecord->szName);
	printf("Age  : %d\n", paRecord->nAge);
	printf("Sex  : %s\n", SEX_MALE == paRecord->nSex ? "Male" : "Female");
	printf("Data : %c\n", paRecord->cData[0]);
	printf("Time = %I64d seconds\n", ltime);
}

#define	LOOP_COUNT	100000000

void	main(void)
{
	struct tagRecord aRecord;
	time_t ltimeBegin, ltimeEnd;

	strcpy(aRecord.szName, "Tom Cruze");
	aRecord.nAge = 30;
	aRecord.nSex = SEX_MALE;
	aRecord.cData[0] = 'M';

	function_record_print(&aRecord, 0);

	time(&ltimeBegin);
	for (int i = 0; i < LOOP_COUNT; i++)
	{
		aRecord = function_record_set_call_by_value(aRecord);
	}
	time(&ltimeEnd);

	function_record_print(&aRecord, ltimeEnd - ltimeBegin);

	time(&ltimeBegin);
	for (int i = 0; i < LOOP_COUNT; i++)
	{
		function_record_set_call_by_reference(&aRecord);
	}
	time(&ltimeEnd);

	function_record_print(&aRecord, ltimeEnd - ltimeBegin);
}
