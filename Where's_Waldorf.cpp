
// Where's Waldorf?
// Created by Kim Jong-uk at 2017.01.04
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define MAXIMUM_TEXT 50
#define SEARCH_MAXIMUM_TEXT 20
#define DIRECTION_SORT 8

char textGrid[MAXIMUM_TEXT][MAXIMUM_TEXT];
int inputCase, inputCharLength;

int search(char* word, int startY, int startX) {
	int directionX[DIRECTION_SORT] = { -1, -1, 0, 1, 1, 1, 0, -1 };
	int directionY[DIRECTION_SORT] = {  0, -1,-1,-1, 0, 1, 1,  1 };
	int i, j, k;
	int wordStart, wordLength = strlen(word);

	for (i = 0; i < 8; i++)
	{
		wordStart = 0;

		for (j = startX, k = startY; (j < inputCharLength && j >= 0) && (k < inputCase&& k >= 0); j =j + directionX[i], k = k + directionY[i])
		{
			if (textGrid[k][j] == word[wordStart])
			{
				wordStart++;

				if (wordStart == wordLength)
					return 1;
			}
			else
				break;
		}
	}

	return 0;

}

int main()
{
	int testCase;
	int i, j, k, l;
	int searchCase;
	char searchText[SEARCH_MAXIMUM_TEXT][MAXIMUM_TEXT];
	char line[MAXIMUM_TEXT];

	scanf("%d", &testCase);

	for (i = 0; i < testCase; i++)
	{
		if (i > 0)
			putchar('\n');
		gets(line);

		scanf("%d %d", &inputCase, &inputCharLength);
		gets(line);

		for (j = 0; j < inputCase; j++) {
			for (k = 0; k < inputCharLength; k++) {
				textGrid[j][k] = getchar();
				textGrid[j][k] = ('Z' >= textGrid[j][k] && textGrid[j][k] >= 'A') ? textGrid[j][k] + ('a' - 'A') : textGrid[j][k];
			}
			gets(line);
		}
				 
		scanf("%d", &searchCase);
		gets(line);
		for (j = 0; j < searchCase; j++){
			scanf("%s", &searchText[j]);

			for(k = 0 ; k < strlen(searchText[j]); k++)
				searchText[j][k] = ('Z' >= searchText[j][k] && searchText[j][k] >= 'A') ? searchText[j][k] + ('a' - 'A') : searchText[j][k];

			for(k = 0 ; k <inputCase; k++)
				for(l = 0; l <inputCharLength; l++)
					if (search(searchText[j], k, l))
					{
						printf("%d %d\n", k+1, l+1);
						goto endLabel;
					}
		endLabel:;
		}

	}


	return 0;
}