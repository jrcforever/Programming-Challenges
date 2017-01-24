
// ShellSort
// Created by Kim Jong-uk at 2017.01.18
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define MAXIMUMS_NAME_LENGTH 81
#define MAXIMUM_TURTLE_NUMBER 200

int main()
{
	int totalTestCase;
	int i;

	scanf("%d", &totalTestCase);

	for (i = 0; i < totalTestCase; i++)
	{
		char inputTurtles[MAXIMUM_TURTLE_NUMBER][MAXIMUMS_NAME_LENGTH] = {};
		char compareTurtles[MAXIMUM_TURTLE_NUMBER][MAXIMUMS_NAME_LENGTH] = {};
		char localTop[MAXIMUM_TURTLE_NUMBER][MAXIMUMS_NAME_LENGTH] = {};
		char resultTop[MAXIMUM_TURTLE_NUMBER][MAXIMUMS_NAME_LENGTH] = {};
		char temp[MAXIMUMS_NAME_LENGTH];
		int indicator1 = 0, indicator2 = 0, stackindicator = 0;
		int j,k;
		int localTestCase;

		scanf("%d", &localTestCase);
		
		gets(temp);
		for (j = localTestCase-1; j >= 0; j--)
			gets(inputTurtles[j]);
		for (j = localTestCase - 1; j >= 0; j--)
			gets(compareTurtles[j]);

		while (indicator1 < localTestCase && indicator2 < localTestCase)
			if (strcmp(inputTurtles[indicator1], compareTurtles[indicator2]))
			{
				//printf("%d %s\n", indicator1, inputTurtles[indicator1]);
				//printf("%d %s\n", indicator2, compareTurtles[indicator2] );
				strcpy(localTop[stackindicator],inputTurtles[indicator1]);
				stackindicator++;
				indicator1++;
			}
			else
			{
				indicator1++;
				indicator2++;
			}

		indicator1 = 0;

		for(j = indicator2; j <localTestCase; j++)
			for(k = 0; k <stackindicator;k ++)
				if (!strcmp(localTop[k], compareTurtles[j]))
				{
					strcpy(resultTop[indicator1], localTop[k]);
					indicator1++;
				}

		for (j = 0; j < localTestCase - indicator2; j++)
			puts(resultTop[j]);

		if (i < totalTestCase)
			putchar('\n');
	}


	return 0;
}