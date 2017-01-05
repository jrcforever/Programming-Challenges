
//Yahtzee
// Created by Kim Jong-uk at 2017.01.01
// Protected by MIT license

#include <stdio.h>

#define MAXIMUM_LINE_LENGTH 100

#define OPTIMAL_CASE 10000
#define DICE_CASE 6
#define INPUT_SIZE 5
#define CASE_INPUT 13

int OptimalValue[OPTIMAL_CASE][CASE_INPUT + 2];
int DiceCase[CASE_INPUT][DICE_CASE];
int Indicator;
int Score[CASE_INPUT][CASE_INPUT];
int CheckTheCategory[CASE_INPUT];
int Temp[CASE_INPUT + 2];

void resortScoring(int category) {
	int i, j;
	int previousIndicator;

	if (category > 5 && OptimalValue[Indicator][14] != -1)
		return;

	if (12 == category) {
		for (i = 0; i < 13; i++)
		{
			if (CheckTheCategory[i]) continue;

			OptimalValue[Indicator][category] = Score[i][category];
			OptimalValue[Indicator][14] = Score[i][category];

			return;
		}
	}

	previousIndicator = Indicator;
	for (i = 0; i < 13; i++) {
		if (CheckTheCategory[i]) continue;
		Indicator += 1 << i;
		CheckTheCategory[i] = 1;

		Temp[category] = Score[i][category];
		resortScoring(category + 1);

		if (category > 5) {
			if (Score[i][category] + OptimalValue[Indicator][14] > OptimalValue[previousIndicator][14])
			{
				for (j = 0; j < 15; j++)
					OptimalValue[previousIndicator][j] = OptimalValue[Indicator][j];
				OptimalValue[previousIndicator][category] = Score[i][category];
				OptimalValue[previousIndicator][14] += Score[i][category];
			}
		}
		else if (5 == category) {
			Temp[14] = 0;
			for (j = 0; j < 6; j++)
				Temp[14] += Temp[j];
			if (Temp[14] >= 63)
				Temp[13] = 35;
			else
				Temp[13] = 0;

			if (Temp[13] + Temp[14] + OptimalValue[Indicator][14] > OptimalValue[0][14]) {
				for (j = 0; j < 6; j++)
					OptimalValue[0][j] = Temp[j];
				for (j = 6; j < 13; j++)
					OptimalValue[0][j] = OptimalValue[Indicator][j];
				OptimalValue[0][13] = Temp[13];
				OptimalValue[0][14] = Temp[13] + Temp[14] + OptimalValue[Indicator][14];
			}

		}

		CheckTheCategory[i] = 0;
		Indicator -= 1 << i;

	}

}

void blackBox() {
	int i, j, fullhouse;

	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 13; j++)
			Score[i][j] = 0;
		fullhouse = 0;

		for (j = 0; j < 6; j++) {
			Score[i][j] = DiceCase[i][j] * (j + 1);
			Score[i][6] += Score[i][j];

			if (DiceCase[i][j] == 2)
				fullhouse += 2;
			if (DiceCase[i][j] == 3)
				fullhouse += 3;
		}

		for (j = 0; j < 6; j++)
		{
			if (DiceCase[i][j] >= 3)
				Score[i][7] = Score[i][6];
			if (DiceCase[i][j] >= 4)
				Score[i][8] = Score[i][6];
			if (DiceCase[i][j] >= 5)
				Score[i][9] = 50;
		}

		if ((DiceCase[i][0] && DiceCase[i][1] && DiceCase[i][2] && DiceCase[i][3]) ||
			(DiceCase[i][1] && DiceCase[i][2] && DiceCase[i][3] && DiceCase[i][4]) ||
			(DiceCase[i][2] && DiceCase[i][3] && DiceCase[i][4] && DiceCase[i][5]))
			Score[i][10] = 25;

		if ((DiceCase[i][0] && DiceCase[i][1] && DiceCase[i][2] && DiceCase[i][3] && DiceCase[i][4]) ||
			(DiceCase[i][1] && DiceCase[i][2] && DiceCase[i][3] && DiceCase[i][4] && DiceCase[i][5]))
			Score[i][11] = 35;

		if (fullhouse == 5)
			Score[i][12] = 40;

		CheckTheCategory[i] = 0;
	}

	for (i = 0; i < OPTIMAL_CASE; i++)
	{
		for (j = 0; j < CASE_INPUT + 2; j++)
			OptimalValue[i][j] = 0;
		OptimalValue[i][14] = -1;
	}

	Indicator = 0;
	resortScoring(0);

}

int main()
{
	char line[MAXIMUM_LINE_LENGTH];
	int temp[INPUT_SIZE];

	int i, j;

	i = 0;

	while (gets(line) && *line) {
		sscanf(line, "%d %d %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4]);

		for (j = 0; j < DICE_CASE; j++)
			DiceCase[i][j] = 0;

		for (j = 0; j < 5; j++)
			DiceCase[i][temp[j] - 1]++;
		i++;

		if (i >= CASE_INPUT) {

			blackBox();

			i = 0;

			for (j = 0; j < 14; j++)
				printf("%d ", OptimalValue[0][j]);
			printf("%d\n", OptimalValue[0][14]);
		}
	}

	return 0;
}