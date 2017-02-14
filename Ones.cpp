
// Ones
// Created by Kim Jong-uk at 2017.01.24
// Protected by MIT license

#include <stdio.h>

int main()
{
	int input;
	int sum, number, indicator;

	while(scanf("%d", &input) == 1){
		sum = 0;
		number = 0;
		indicator = 1;
		do {
			sum = (sum + indicator) % input;
			number++;
			sum = (sum * 10 )%input;
		} while (sum != 0);
		printf("%d\n", number);
	}

	return 0;
} 