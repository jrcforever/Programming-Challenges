
// Erdös Numbers
// Created by Kim Jong-uk at 2016.12.29
// Protected by MIT license

#include <stdio.h>

#define MAXIMUMTHESIS 1000
#define LENGTH 100

struc

struct Researcher
{
	char name[LENGTH];
	int Erdos_number = -1;
};

int main()
{
	char thesis[MAXIMUMTHESIS][LENGTH];
	Researcher researcher[LENGTH];

	int scenarioNumber;
	int thesisNumber;
	int targetPeopleNumber;
	int i;
	int scenarioNumber = 0;

	scanf("%d", &scenarioNumber);

	while (scenarioNumber--) {
		scanf("%d %d", &thesisNumber, targetPeopleNumber);

		while (thesisNumber--)
			scanf("%s", &thesis[thesisNumber]);

		for (i = 0; i < targetPeopleNumber; i++)
			scanf("%s", &researcher[i].name);



		printf("Scenario %d\n", scenarioNumber++);
		for (i = 0; i < targetPeopleNumber; i++) {
			printf("%s ", researcher[i].name);
			if (researcher[i].Erdos_number == -1)
				printf("infinity\n");
			else
				printf("%d\n", researcher[i].Erdos_number);
		}

	}

	return 0;
}