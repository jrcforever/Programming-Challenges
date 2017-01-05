
// Poker Hands
// Created by Kim Jong-uk at 2016.12.22
// Protected by MIT license

#include<stdio.h>
#include <stdlib.h>

#define INPUT_SIZE 100
#define TOTAL_PAIRS 10
#define RANK_SCORE 8

#define TRUE 1
#define FALSE 0

#define WHITE_WIN "White wins."
#define BLACK_WIN "Black wins."
#define TIE "Tie."

// 9 57

struct card
{
	int card_number;
	char card_type;
};


int compare(const void *first, const void *second)
{
	if (((const card*)first)->card_number > ((const card*)second)->card_number)
		return 1;
	else if (((const card*)first)->card_number < ((const card*)second)->card_number)
		return -1;
	else
		return 0;
}

struct user {
	card pair[5];
	int rank;
	int card_result[3];

	void init()
	{
		int i;

		rank = 0;

		for (i = 0; i < 3; i++)
			card_result[i] = 0;
	}

	void sort()
	{
		qsort(pair, TOTAL_PAIRS / 2, sizeof(card), compare);
	}

	void score()
	{
		int i = 0;
		int sameTwo = 0;
		int sameThree = 0;
		int sameFour = 0;

		int totalsameTwo = 0;
		int totalsameThree = 0;
		int totalsameFour = 0;

		int straight = TRUE;
		int flush = TRUE;

		for (i = 0; i < 3; i++)
			card_result[i] = FALSE;

		//for (i = 0; i < TOTAL_PAIRS / 2; i++)
		//	printf("%d %c \n", pair[i].card_number, pair[i].card_type);

		for (i = 1; i < TOTAL_PAIRS / 2; i++)
			if (pair[i].card_number == pair[i - 1].card_number)
			{
				if (sameTwo >= 1)
				{
					sameThree++;
					sameTwo--;

					card_result[0] = pair[i].card_number;
				}

				else if (sameThree >= 1)
				{
					sameFour++;
					sameThree--;
					card_result[0] = pair[i].card_number;
				}
				else if (sameTwo == 0)
				{
					sameTwo++;

					if (sameTwo == 1 && sameThree == 0)
						card_result[0] = pair[i].card_number;
				}

				printf("%d %d %d %d \n", i, sameTwo, sameThree, sameFour);


				if ((sameTwo == 1 && sameThree == 1) || sameTwo == 2)
				{
					card_result[1] = pair[i].card_number;
				}

				if (i == TOTAL_PAIRS/2 - 1)
				{
					totalsameTwo += sameTwo;
					totalsameThree += sameThree;
					totalsameFour += sameFour;
				}

			}
			else
			{
				totalsameTwo += sameTwo;
				totalsameThree += sameThree;
				totalsameFour += sameFour;

				sameTwo = 0;
				sameThree = 0;
				sameFour = 0;
			}

		//	printf("%d %d \n", card_result[0], card_result[1]);

		for (i = 1; i < TOTAL_PAIRS / 2; i++)
		{
			if (pair[i].card_number != pair[i - 1].card_number + 1)
				straight = FALSE;

			if (pair[i].card_type != pair[i - 1].card_type)
				flush = FALSE;
		}

		if (totalsameTwo == 1)
			ranking(1);
		if (totalsameTwo == 2)
			ranking(2);
		if (totalsameThree == 1)
			ranking(3);
		if (straight == TRUE)
			ranking(4);
		if (flush == TRUE)
			ranking(5);
		if (totalsameTwo == 1 && totalsameThree == 1)
			ranking(6);
		if (totalsameFour == 1)
			ranking(7);
		if (straight == TRUE && flush == TRUE)
			ranking(8);

		if (rank == 0)
			card_result[0] = pair[4].card_number;

		printf("%d %d %d %d %d %d\n", totalsameTwo, totalsameThree, totalsameFour, straight, flush, rank);

	}

	void ranking(int A)
	{
		if (A > rank)
			rank = A;

		if (rank > RANK_SCORE)
			exit(0);
	}

	int getRank()
	{
		return rank;
	}

	int* getCardResult()
	{
		return card_result;
	}

};

void allocator(char *input, int *user) {
	switch (*input) {
	case 'T':
		*user = 58;
		break;
	case'J':
		*user = 59;
		break;
	case'Q':
		*user = 60;
		break;
	case'K':
		*user = 61;
		break;
	case 'A':
		*user = 62;
		break;
	default:
		*user = *input;
		break;
	}
}

int main()
{
	char temp[INPUT_SIZE];
	int indicator;
	int i, j, deci;
	char numtemp;

	user black;
	user white;


	while (gets_s(temp) && *temp) {
		indicator = 0;

		black.init();
		white.init();

		for (i = 0; i < TOTAL_PAIRS; i++)
		{
			if (i < 5) {
				sscanf(temp + indicator++, "%c", &numtemp);
				allocator(&numtemp, &black.pair[i].card_number);
				sscanf(temp + indicator++, "%c", &black.pair[i].card_type);
			}
			else {
				sscanf(temp + indicator++, "%c", &numtemp);
				allocator(&numtemp, &white.pair[i - TOTAL_PAIRS / 2].card_number);
				sscanf(temp + indicator++, "%c", &white.pair[i - TOTAL_PAIRS / 2].card_type);

			}
			while (temp[indicator] == ' ')
				indicator++;
		}

		black.sort();
		white.sort();

		black.score();
		white.score();

		if (black.getRank() > white.getRank())
			printf("%s\n", BLACK_WIN);
		else if (black.getRank() < white.getRank())
			printf("%s\n", WHITE_WIN);
		else if (black.getRank() == white.getRank())
		{
			switch (black.getRank()) {
			case 1:
			case 2:
			case 6:
			case 7:

				deci = 0;

				for (j = 0; j < TOTAL_PAIRS / 2; j++)
					if (black.pair[j].card_number < white.pair[j].card_number)
						deci = 1;
					else if (black.pair[j].card_number > white.pair[j].card_number)
						deci = 2;

				if (deci == 2)
					printf("%s\n", BLACK_WIN);
				else if (deci == 1)
					printf("%s\n", WHITE_WIN);
				else
					printf("%s\n", TIE);
				break;



			case 3:
			
				if (black.card_result[0] < white.card_result[0])
					printf("%s\n", WHITE_WIN);
				else if (black.card_result[0] > white.card_result[0])
					printf("%s\n", BLACK_WIN);
				else {
					if (black.card_result[1] < white.card_result[1])
						printf("%s\n", WHITE_WIN);
					else if (black.card_result[1] > white.card_result[1])
						printf("%s\n", BLACK_WIN);
					else
						printf("%s\n", TIE);
				}
				break;

			case 4:
			case 5:
				printf("%d\n", black.getRank());
				if (black.pair[4].card_number < white.pair[4].card_number)
					printf("%s\n", WHITE_WIN);
				else if (black.pair[4].card_number > white.pair[4].card_number)
					printf("%s\n", BLACK_WIN);
				else
				{
					deci = 0;

					for (j = 0; j < TOTAL_PAIRS / 2; j++)
						if (black.pair[j].card_number < white.pair[j].card_number)
							deci = 1;
						else if (black.pair[j].card_number > white.pair[j].card_number)
							deci = 2;

					if (deci == 2)
						printf("%s\n", BLACK_WIN);
					else if (deci == 1)
						printf("%s\n", WHITE_WIN);
					else
						printf("%s\n", TIE);
				}
				break;
			case 8:
			case 0:
				printf("%d\n", black.getRank());
				if (black.pair[4].card_number < white.pair[4].card_number)
					printf("%s\n", WHITE_WIN);
				else if (black.pair[4].card_number > white.pair[4].card_number)
					printf("%s\n", BLACK_WIN);
				else
					printf("%s\n", TIE);
				break;
			default:
				break;
			}

			putchar('\n');

		}


		//for (i = 0; i < TOTAL_PAIRS / 2; i++)
		//	printf("%d %c \n", black.pair[i].card_number, black.pair[i].card_type);

	}

	return 0;
}