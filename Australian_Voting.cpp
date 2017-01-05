
// Australian Voting
// Created by Kim Jong-uk at 2016.12.22
// Protected by MIT license

#include <stdio.h>
#define TRUE 1
#define FALSE 0

#define TOTAL_CANDIDATE 20
#define TOTAL_VOTER 1000
int main()
{
	int testCase;
	int i, j, indicator, voter;
	int listOfCandidate;
	char temp[100];
	char namesOfCandidate[TOTAL_CANDIDATE + 1][81];
	int votedByPeople[TOTAL_VOTER][TOTAL_CANDIDATE];
	int votedWinCandidate[TOTAL_CANDIDATE + 1];
	int indexOfFirstCandidate[TOTAL_VOTER];

	int maximumVotedCandidate;
	int minimumVotedCandidate;

	int sameOfVotedScore;

	int firstCandidate;

	scanf("%d", &testCase);

	gets(temp);

	while (testCase-- >0)
	{
		scanf("%d", &listOfCandidate);

		gets(temp);
		for (j = 1; j <= listOfCandidate; j++)
		{
			gets(namesOfCandidate[j]);
			votedWinCandidate[j] = 0;
		}

		voter = 0;
		while (gets(temp) && *temp) {
			indicator = 0;

			for (j = 0; j <= listOfCandidate; j++)
			{
				sscanf(temp + indicator, "%d", &votedByPeople[voter][j]);
				while (temp[indicator] >= '0' && temp[indicator] <= '9')
					indicator++;

				while (temp[indicator] == ' ')
					indicator++;
			}
			votedWinCandidate[votedByPeople[voter][0]]++;
			indexOfFirstCandidate[voter] = 0;
			voter++;
		}

		while (TRUE) {
			maximumVotedCandidate = -1;
			minimumVotedCandidate = TOTAL_VOTER + 1;
			sameOfVotedScore = TRUE;

			for (j = 1; j <= listOfCandidate; j++)
				if (votedWinCandidate[j] > 0) {

					if (votedWinCandidate[j] > maximumVotedCandidate) {
						if (maximumVotedCandidate >= 0)
							sameOfVotedScore = 0;

						maximumVotedCandidate = votedWinCandidate[j];

						firstCandidate = j;
					}

					if (votedWinCandidate[j] < minimumVotedCandidate) {
						if (minimumVotedCandidate <= TOTAL_VOTER)
							sameOfVotedScore = 0;
						minimumVotedCandidate = votedWinCandidate[j];
					}
				}

			if (maximumVotedCandidate * 2 > TOTAL_VOTER || sameOfVotedScore != FALSE)
				break;


			for (j = 0; j < voter; j++)
				if (votedWinCandidate[votedByPeople[j][indexOfFirstCandidate[j]]] == minimumVotedCandidate) {
					for (indexOfFirstCandidate[j]; votedWinCandidate[votedByPeople[j][indexOfFirstCandidate[j]]] <= minimumVotedCandidate; indexOfFirstCandidate[j]++);

					votedWinCandidate[votedByPeople[j][indexOfFirstCandidate[j]]]++;
				}

			for (j = 1; j <= listOfCandidate; j++)
				if (votedWinCandidate[j] == minimumVotedCandidate)
					votedWinCandidate[j] = 0;
		}

		if (maximumVotedCandidate * 2 > TOTAL_VOTER)
			puts(namesOfCandidate[firstCandidate]);
		else
			for (j = 1; j <= listOfCandidate; j++)
				if (votedWinCandidate[j] != 0)
					puts(namesOfCandidate[j]);

		if (testCase >0)
			putchar('\n');
	}


	return 0;
}