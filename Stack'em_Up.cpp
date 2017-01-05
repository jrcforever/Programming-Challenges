
// Stack 'em Up
// Created by Kim Jong-uk at 2016.12.28
// Protected by MIT license

#include<stdio.h>

#define TOTAL_CARD 52
#define MAXIMUM_SHUFFLE_NUMBER 1000

int main()
{
	int testCase;
	int inputCase;
	int card[TOTAL_CARD+1], previousCard[TOTAL_CARD+1];
	int mapping[MAXIMUM_SHUFFLE_NUMBER][TOTAL_CARD+1];
	int k, i, j, choice;
	char line[MAXIMUM_SHUFFLE_NUMBER];

	scanf("%d", &testCase);
	for (k = 0; k < testCase; k++) {

		scanf("%d", &inputCase);

		for (i = 1; i <= inputCase; i++)
			for (j = 1; j <= TOTAL_CARD; j++)
				scanf("%d", &mapping[i][j]);

		for (i = 1; i <= TOTAL_CARD; i++)
			card[i] = i;

		gets(line);
		
		while (gets(line) && *line) {
			sscanf(line, "%d", &choice);

			for (i = 1; i <= TOTAL_CARD; i++)
				previousCard[i] = card[i];

			for(i = 1; i <= TOTAL_CARD; i++)
				card[i] = previousCard[mapping[choice][i]];

		}

		if (k > 0)
			putchar('\n');

		for (i = 1; i <= TOTAL_CARD; i++) {
			switch ((card[i]-1) % 13)
			{
			case 9:
				printf("Jack");
				break;
			case 10:
				printf("Queen");
				break;
			case 11:
				printf("King");
				break;
			case 12:
				printf("Ace");
				break;
			default:
				printf("%d", ((card[i]-1) % 13)+2);

				break;
		   }

			printf(" of ");
			switch ((card[i]-1)/13)
			{
			case 0:
				puts("Clubs");
				break;
			case 1:
				puts("Diamonds");
				break;
			case 2:
				puts("Hearts");
				break;
			case 3:
				puts("Spades");
				break;
			}
		}
	}

	return 0;
}