
// Shoemaker's problem  
// Created by Kim Jong-uk at 2017.01.17
// Protected by MIT license

#include <stdio.h>

#define TOTAL_LOCAL_TEST_CASE 1000

int main()
{
	int totalTestCase;
	int i,j, k;
	int localTestCase;

	scanf("%d", &totalTestCase);

	for (i = 0; i < totalTestCase; i++) {
		int costDay[TOTAL_LOCAL_TEST_CASE];
		int delayCost[TOTAL_LOCAL_TEST_CASE];
		int result[TOTAL_LOCAL_TEST_CASE];
		int temp;

		scanf("%d", &localTestCase);

		for (j = 0; j < localTestCase; j++)
			scanf("%d %d", &costDay[j], &delayCost[j]);
		
		for (j = 0; j < localTestCase; j++)
			result[j] = j;

		for(j = 1; j < localTestCase; j++)
			for (k = 0; k < localTestCase - j; k++)
				if (costDay[result[k]]*delayCost[result[k+1]] > delayCost[result[k]]*costDay[result[k+1]]) {
					temp = result[k];
					result[k] = result[k + 1];
					result[k + 1] = temp;
				}

		if (i > 0)
			putchar('\n');
		for (j = 0; j < localTestCase -1; j++)
			printf("%d ", result[j]+1);
		printf("%d\n", result[localTestCase-1] + 1);
	}

	return 0;
}