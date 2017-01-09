
// Crypt Kicker ll 
// Created by Kim Jong-uk at 2017.01.05
// Protected by MIT license

#include<stdio.h>
#include<string.h>

#define MAXIMUM_STRING_LENGTH 80

#define MAXIMUM_INPUT_STRING_CASE 100

#define FALSE 0
#define TRUE 1

int main()
{
	int i, j, k;
	int testcase;
	char line[MAXIMUM_STRING_LENGTH + 1];
	char *hint = "the quick brown fox jumps over the lazy dog";

	char inputStrings[MAXIMUM_INPUT_STRING_CASE][MAXIMUM_STRING_LENGTH + 1];
	char mapping[256];
	char reverseMapping[256];
	int inputStringCase;
	int checkSuccess;


	scanf("%d", &testcase);
	gets(line);
	gets(line);

	while (testcase-- > 0)
	{
		inputStringCase = 0;
		checkSuccess = FALSE;

		while (gets(inputStrings[inputStringCase]) && *inputStrings[inputStringCase]) {
			inputStringCase++;
		}

		for (i = 0; i < inputStringCase; i++)
		{
			if (strlen(hint) != strlen(inputStrings[i]))
				continue;

			for (j = 'a'; j <= 'z'; j++)
			{
				mapping[j] = '\0';
				reverseMapping[j] = '\0';
			}

			mapping[' '] = ' ';
			reverseMapping[' '] = ' ';

			for (k = 0; inputStrings[i][k]; k++)
				if (mapping[inputStrings[i][k]] && mapping[inputStrings[i][k]] != hint[k] ||
					reverseMapping[hint[k]] && reverseMapping[hint[k]] != inputStrings[i][k]) {
					goto exit;
				}
				else
				{
					mapping[inputStrings[i][k]] = hint[k];
					reverseMapping[hint[k]] = inputStrings[i][k];
				}

			checkSuccess = TRUE;
			break;
		exit:;
		}

		if (checkSuccess) {
			for (i = 0; i < inputStringCase; i++)
			{
				for (j = 0; j < strlen(inputStrings[i]); j++)
					printf("%c", mapping[inputStrings[i][j]]);
				putchar('\n');
			}
		}
		else
			printf("No solution.\n");

		if (testcase > 0)
			putchar('\n');
	}

	return 0;
}