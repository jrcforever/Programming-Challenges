
// Stacks of Flapjacks
// Created by Kim Jong-uk at 2017.01.10
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define MAXIMUMSTACK 30

static int stack[MAXIMUMSTACK];

static int workpoint;

void flip(int stackPoint) {
	int i, temp;

	for (i = 0; i <= stackPoint /2; i++) {
		temp = stack[i];
		stack[i] = stack[stackPoint-i];
		stack[stackPoint-i] = temp;
	}

}

int main()
{
	char temp[100];
	char* indicator;
	int number = 0, i, j;
	int nowIndicator;

	while (!feof(stdin)) {

		if (!gets_s(temp))
			break;

		workpoint = 0;

		printf("%s\n", temp);

		indicator = temp;

		while (indicator[0])
		{

			if (indicator[0] >= '0' && indicator[0] <= '9')
			{
				number = number * 10 + (indicator[0] - '0');
			}else
			{
				stack[workpoint] = number;
				workpoint++;
				number = 0;
			}			
			indicator++;
		}


		if (number > 0) {
			stack[workpoint] = number;
			workpoint++;
		}


		number = 0;

		for (i = workpoint - 1; i >= 1; i--) {
			nowIndicator = i;
			for (j = 0; j < i; j++)
				if (stack[nowIndicator] < stack[j]) nowIndicator = j;

			if (nowIndicator < i)
			{
				if (nowIndicator > 0)
				{
					printf("%d ", workpoint - nowIndicator);
					flip(nowIndicator);
				}
				printf("%d ", workpoint - i);
				flip(i);
			}

			
		}
		printf("0\n");	
	
		for (i = 0; i < workpoint; i++)
		{
			stack[i] = 0;
		}
	}
	return 0;
}