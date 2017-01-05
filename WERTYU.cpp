
// WERTYU
// Created by Kim Jong-uk at 2017.01.04
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define MAXIMUM_LINE_LENGTH 1000
#define KEYBOARD_LINE 4
#define TRUE 1
#define FALSE 0

static char* KeyBoardMapping[KEYBOARD_LINE] = { "`1234567890-=","QWERTYUIOP[]\\","ASDFGHJKL;'","ZXCVBNM,./" };

int main()
{
	char line[MAXIMUM_LINE_LENGTH];
	char parsingText[MAXIMUM_LINE_LENGTH];
	int i,j,length, spaceOrEtc;

	while (gets(line) && *line) {
		for (i = 0; i < strlen(line); i++) {
			spaceOrEtc = FALSE;

			for(j = 0; j <KEYBOARD_LINE ; j++)
				if (strchr(KeyBoardMapping[j], line[i]))
				{
					printf("%c", *(strchr(KeyBoardMapping[j], line[i]) - 1));
						spaceOrEtc = TRUE;
				}
			if (FALSE == spaceOrEtc)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}