
// Vito's Family
// Created by Kim Jong-uk at 2017.01.10
// Protected by MIT license

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXIMUM_FAMILY_NUMBER 500

int compare(const void *inputA, const void *inputB) {
	if (*(int *)inputA > *(int *)inputB) return 1;
	if (*(int *)inputA < *(int *)inputB) return -1;
	return 0;
}

int main()
{
	int testCase;
	int i, j;
	int indicator;
	int familyNumber;
	int familyAddress[MAXIMUM_FAMILY_NUMBER];
	int result;

	scanf("%d", &testCase);

	for (i = 0; i < testCase; i++) {
		
		result = 0;
		indicator = 0;
		scanf("%d", &familyNumber);

		for (j = 0; j < familyNumber; j++) {
			scanf("%d", &familyAddress[j]);
		}

		qsort((int *)familyAddress, familyNumber, sizeof(int), compare);

		if(familyNumber%2 == 0)
			indicator = (familyAddress[familyNumber / 2] + familyAddress[familyNumber / 2 - 1]) / 2;
		else
			indicator = familyAddress[familyNumber / 2];

		for (j = 0; j < familyNumber; j++)
			result += abs((int)indicator - familyAddress[j]);

		printf("%d\n", result);
	}

	return 0;
}