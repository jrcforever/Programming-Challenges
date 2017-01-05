
// Common Permutation
// Created by Kim Jong-uk at 2017.01.05
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define MAXIMUM_STRING_LENGTH 1000

int main()
{
	char temp[MAXIMUM_STRING_LENGTH+1];
	int mapChar['z' + 1];
	int resultChar['z' + 1];
	int i,j ,count = 0;

	for (i = 0; i < 'z' + 1; i++)
		mapChar[i] = resultChar[i] = 0;

	while (gets(temp))
	{
		count++;

		if (1 == count)
			for (i = 0; i < strlen(temp); i++)
				mapChar[temp[i]]++;

		if (count >= 2)
		{
			for(i = 0 ; i < strlen(temp); i++)
				if (mapChar[temp[i]] > 0)
				{
					resultChar[temp[i]]++;
					mapChar[temp[i]]--;
				}

			for (i = 'a'; i < 'z' + 1; i++)
				if (resultChar[i] > 0)
					for (j = 0; j < resultChar[i]; j++)
						printf("%c", i);
			putchar('\n');

			for (i = 0; i < 'z' + 1; i++)
				mapChar[i] = resultChar[i] = 0;

			count = 0;
		}
	}


	return 0;
}