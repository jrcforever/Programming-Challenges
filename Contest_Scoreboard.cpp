
// Contest Scoreboard
// Created by Kim Jong-uk at 2016.12.29
// Protected by MIT license

#include<stdio.h>

#define MAXIMUM_LINE 100
#define MAXIMUM_TEAM_NUMBER 100
#define PENALTY 20
#define MAXIMUM_PROBLEM_NUMBER 10

#define TRUE 1
#define FALSE 0

struct Team
{
	int problemSolveNumber = 0;
	int panelty = 0;
	int submitted = 0;
};

struct Problem
{
	int solved = 0;
	int accumulatedPanelty = 0;

};

int blackbox(Team input_A, Team input_B)
{
	if (input_A.submitted < input_B.submitted) return 1;

	if (input_A.submitted > input_B.submitted) return 0;
	if (input_A.problemSolveNumber < input_B.problemSolveNumber) return 1;
	if (input_A.problemSolveNumber > input_B.problemSolveNumber) return 0;
	if (input_A.panelty > input_B.panelty) return 1;

	return 0;

}

int main()
{
	int testcase;
	int i, j, k, temp;
	char line[MAXIMUM_LINE];
	int tempTeam;
	int tempProblemNumber;
	int tempPanelty;
	char tempProblemtype;
	Team team[MAXIMUM_TEAM_NUMBER + 1];
	Problem problem[MAXIMUM_TEAM_NUMBER + 1][MAXIMUM_PROBLEM_NUMBER + 1];
	int sorter[MAXIMUM_TEAM_NUMBER + 1];
	int indicator;


	scanf("%d", &testcase);

	gets_s(line);
	gets_s(line);

	while(testcase--) {

		for (j = 1; j <= MAXIMUM_TEAM_NUMBER; j++)
		{
			team[j].submitted =
			team[j].panelty =
				team[j].problemSolveNumber = 0;

			for (k = 1; k < MAXIMUM_PROBLEM_NUMBER + 1; k++)
			{
				problem[j][k].accumulatedPanelty =
					problem[j][k].solved = 0;
			}
		}

		while (gets_s(line) && *line) {
			sscanf(line, "%d %d %d %c", &tempTeam, &tempProblemNumber, &tempPanelty, &tempProblemtype);


			if (tempProblemtype == 'C')
			{
				if (FALSE == problem[tempTeam][tempProblemNumber].solved)
				{
					problem[tempTeam][tempProblemNumber].accumulatedPanelty += tempPanelty;

					team[tempTeam].problemSolveNumber++;
					team[tempTeam].panelty += problem[tempTeam][tempProblemNumber].accumulatedPanelty;
					problem[tempTeam][tempProblemNumber].accumulatedPanelty = 0;
					problem[tempTeam][tempProblemNumber].solved = true;
				}

				team[tempTeam].submitted = TRUE;
			}
			else if (tempProblemtype == 'I' && FALSE == problem[tempTeam][tempProblemNumber].solved)
			{
				problem[tempTeam][tempProblemNumber].accumulatedPanelty = PENALTY;
				team[tempTeam].submitted = TRUE;
			}
			else
				team[tempTeam].submitted = TRUE;

		}

		//sort part

		for (j = 1; j <= MAXIMUM_TEAM_NUMBER; j++)
			sorter[j] = j;

		for (j = 1; j < MAXIMUM_TEAM_NUMBER; j++)
		{
			indicator = j;
			for (k = j + 1; k <= MAXIMUM_TEAM_NUMBER; k++)
				if (blackbox(team[sorter[indicator]],team[sorter[k]]))
					indicator = k;
			temp = sorter[indicator];
			sorter[indicator] = sorter[j];
			sorter[j] = temp;
		}
		
		for (j = 1; j <= MAXIMUM_TEAM_NUMBER; j++)
			if (team[sorter[j]].submitted == TRUE)
				printf("%d %d %d\n", sorter[j], team[sorter[j]].problemSolveNumber, team[sorter[j]].panelty);

		if (testcase < 0)
			putchar('\n');
	}

	return 0;
}