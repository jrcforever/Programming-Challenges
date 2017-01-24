
// Bridge
// Created by Kim Jong-uk at 2017.01.17
// Protected by MIT license


#include <stdio.h>
#include <stdlib.h>

#define MAXIMUM_GUY 1000

int compare(const void *inputA, const void *inputB) {
	return *(int *)inputA - *(int *)inputB;
}


int main()
{
	int i, testcase;
	int j, k, testcase_man_number;
	int manSpeed[MAXIMUM_GUY];
	char temp[MAXIMUM_GUY];
	
	int totalConsumptionTime;
	int indicator;
	int manCaseNum[MAXIMUM_GUY * 2 - 1] = { 0 };
	int manCaseEachSpeed[MAXIMUM_GUY * 2 - 1][2] = { 0 };

	int man1, man2, man3, man4;

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {

		totalConsumptionTime = 0;
		indicator = 0;

		scanf("%d", &testcase_man_number);

		for (j = 0; j < testcase_man_number; j++)
			scanf("%d", &manSpeed[j]);

		qsort((int *)manSpeed, testcase_man_number, sizeof(int), compare);

		while (testcase_man_number > 3) {
			man1 = man2 = man3 = man4 = 0;

			man1 = manSpeed[0];
			man2 = manSpeed[1];
			man3 = manSpeed[testcase_man_number - 2];
			man4 = manSpeed[testcase_man_number - 1];

			if (man2 + man2 < man3 + man1) {
				
				manCaseNum[indicator] = 2;
				manCaseEachSpeed[indicator][0] = man1;
				manCaseEachSpeed[indicator][1] = man2;

				indicator++;
				manCaseNum[indicator] = 1;
				manCaseEachSpeed[indicator][0] = man1;

				indicator++;
				manCaseNum[indicator] = 2;
				manCaseEachSpeed[indicator][0] = man3;
				manCaseEachSpeed[indicator][1] = man4;
			
				indicator++;
				manCaseNum[indicator] = 1;
				manCaseEachSpeed[indicator][0] = man2;
				indicator++;
				totalConsumptionTime += man2 +man1 +man4+ man2 ;
			}
			else
			{
				manCaseNum[indicator] = 2;
				manCaseEachSpeed[indicator][0] = man1;
				manCaseEachSpeed[indicator][1] = man3;

				indicator++;
				manCaseNum[indicator] = 1;
				manCaseEachSpeed[indicator][0] = man1;

				indicator++;
				manCaseNum[indicator] = 2;
				manCaseEachSpeed[indicator][0] = man1;
				manCaseEachSpeed[indicator][1] = man4;

				indicator++;
				manCaseNum[indicator] = 1;
				manCaseEachSpeed[indicator][0] = man1;
				indicator++;
				totalConsumptionTime += man3 + man1 + man4 + man1;

			}

			testcase_man_number -= 2;
		}

		if (testcase_man_number == 3)
		{
			manCaseNum[indicator] = 2;
			manCaseEachSpeed[indicator][0] = manSpeed[0];
			manCaseEachSpeed[indicator][1] = manSpeed[2];

			indicator++;
			manCaseNum[indicator] = 1;
			manCaseEachSpeed[indicator][0] = manSpeed[0];

			indicator++;
			totalConsumptionTime += manSpeed[0] + manSpeed[2];
			testcase_man_number--;
		}

		manCaseNum[indicator] = testcase_man_number;

		for (j = 0; j < testcase_man_number; j++) {
			manCaseEachSpeed[indicator][j] = manSpeed[j];
		}

		totalConsumptionTime += manSpeed[testcase_man_number - 1];
		indicator++;

		printf("%d\n", totalConsumptionTime);

		for (j = 0; j < indicator; j++)
			for (k = 0; k < manCaseNum[j]; k++)
			{
				printf("%d", manCaseEachSpeed[j][k]);
				if (k < manCaseNum[j] - 1)
					putchar(' ');
				else
				    putchar('\n');
			}
		if (i < testcase-1)
			putchar('\n');
	}

	return 0;
}