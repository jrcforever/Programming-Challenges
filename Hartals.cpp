
// Hartals
// Created by Kim Jong-uk at 2016.12.23
// Protected by MIT license

#include<stdio.h>

#define TRUE 1
#define FALSE 0

#define WEEK 7
#define LIMIT 5

int main()
{
	int partyes[100];
	int holyday;
	int totalTestCase;
	int day;
	int partyNumber;
	int i, j;

	scanf("%d", &totalTestCase);

	while(totalTestCase--) {
		day = 0;
		partyNumber = 0;
		holyday = 0;

		scanf("%d", &day);
		scanf("%d", &partyNumber);

		for (i = 0; i < partyNumber; i++)
			scanf("%d", &partyes[i]);
		
		for (i = 1; i <= day ;i++)
		{
			if ((i-1)% WEEK < LIMIT)
				for(j = 0 ; j < partyNumber; j++)
					if (i %partyes[j] == 0)
					{
						holyday++;
						break;
					}
		}
		printf("%d\n", holyday);

	}

	return 0;
}