
// Automated Judge Script
// Created by Kim Jong-uk at 2017.01.06
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define MAXIMUM_INPUT_OUTPUT_SIZE 100
#define MAXIMUM_LINE_LENGTH 256

#define TRUE 1
#define FALSE 0

#define ACCEPTED "Accepted"
#define WRONG "Wrong Answer"
#define PRESENTATION "Presentation Error"

int main()
{
	char line[MAXIMUM_LINE_LENGTH];
	char answers[MAXIMUM_INPUT_OUTPUT_SIZE*MAXIMUM_LINE_LENGTH];
	char inputStrings[MAXIMUM_INPUT_OUTPUT_SIZE*MAXIMUM_LINE_LENGTH];
	char checkHeap1[MAXIMUM_INPUT_OUTPUT_SIZE*MAXIMUM_LINE_LENGTH];
	char checkHeap2[MAXIMUM_INPUT_OUTPUT_SIZE*MAXIMUM_LINE_LENGTH];

	int answerCaseNumber, inputCaseNumber;
	int i, j, indicator, indicatorMax, correct;
	int testcase = 1;;

	while (TRUE) {
		answers[0] = inputStrings[0] = '\0';

		scanf("%d", &answerCaseNumber);

		if (answerCaseNumber < 1)
			break;

		correct = 0;

		gets(line);

		for (i = 0; i < answerCaseNumber; i++)
		{
			gets(line);
			strcat(answers, line);
			strcat(answers, "\n");
		}
		strcat(answers, "\0");

		scanf("%d", &inputCaseNumber);

		gets(line);

		for (i = 0; i < inputCaseNumber; i++)
		{
			gets(line);
			strcat(inputStrings, line);
			strcat(inputStrings, "\n");
		}
		strcat(inputStrings, "\0");

		if (0 == strcmp(answers, inputStrings))
			correct = 1;
		else {

			indicator = 0;
			for (j = 0; j < strlen(answers); j++)
				if (answers[j] >= '0' && answers[j] <= '9')
				{
					checkHeap1[indicator] = answers[j];
					indicator++;
				}
			checkHeap1[indicator] = '\0';

			indicator = 0;
			for (j = 0; j < strlen(inputStrings); j++)
				if (inputStrings[j] >= '0' && inputStrings[j] <= '9')
				{
					checkHeap2[indicator] = inputStrings[j];
					indicator++;
				}
			checkHeap2[indicator] = '\0';

			if (strlen(checkHeap1) != strlen(checkHeap2))
			{
				correct = 0;
			}
			else if (strlen(checkHeap1) < 1)
			{
				correct = 2;
			}
			else {

				for (j = 0; j < strlen(checkHeap1); j++)
					if (checkHeap1[j] == checkHeap2[j])
						correct = 2;
					else
					{
						correct = 0;
						break;
					}
			}
		}

		if (correct == 1)
			printf("Run #%d: %s\n", testcase++, ACCEPTED);
		else if (correct == 2)
			printf("Run #%d: %s\n", testcase++, PRESENTATION);
		else
			printf("Run #%d: %s\n", testcase++, WRONG);

	}

	return 0;
}