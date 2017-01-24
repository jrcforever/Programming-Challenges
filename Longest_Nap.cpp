
// Longest Nap
// Created by Kim Jong-uk at 2017.01.17
// Protected by MIT license

#include <stdio.h>

#define MAXIMUM_LENGTH 255
#define MAXIMUM_SCHEDULE 100

int parser(char* temp) {
	int h;
	int m;
	int total;

	h = ((temp[0] - '0') * 10 + temp[1] - '0');
	m = ((temp[3] - '0') * 10 + temp[4] - '0');

	return m+h*60-600;
}

int main()
{
	char temp[MAXIMUM_LENGTH];
	char schedule[MAXIMUM_LENGTH];
	int testCase;
	int i, j;
	int count, result, indicator;
	int scheduleDay = 0;

	while (gets(temp) && *temp) {
		int day[480+1];
		char start[6], end[6];
		count = result= indicator= 0;

		for (i = 0; i <= 480; i++)
			day[i] = 0;
		
		sscanf(temp, "%d", &testCase);


		for (i = 0; i < testCase; i++)
		{
			gets(temp);
			sscanf(temp, "%s %s", &start, &end);

			for (j = parser(start); j < parser(end); j++)
				day[j] = 1;

		}

		for (i = 0; i <= 480; i++)
			if (day[i] == 1)
			{
				if (result < count)
				{
					indicator = i;
					result = count;
				}
				count = 0;
			}
			else if (i == 480 && result < count) {
				indicator = (i);
				result = count;
			}
			else
				count++;

		//printf("%d:%d", (indicator - result + 600) / 60, (indicator - result + 600) % 60);
		//printf("%d:%d", result/ 60, result% 60);

		scheduleDay++;

		printf("Day #%d: the longest nap starts at %d", scheduleDay, (indicator - result + 600) / 60);

		if(((indicator - result + 600) % 60) <10)
			printf(":0%d", (indicator - result + 600) % 60);
		else
			printf(":%d", (indicator - result + 600) % 60);

		printf(" and will last for");

		if(result / 60 >0)
			printf(" %d hours and %d minutes.\n", result / 60, result % 60);
		else
			printf(" %d minutes.\n", result % 60);
	}

	return 0;
}