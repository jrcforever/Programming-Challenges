
// Reverse and Add
// Created by Kim Jong-uk at 2017.01.25
// Protected by MIT license


#include <stdio.h>

int main()
{
	unsigned long int input;

	while (scanf("%d", &input) == 1) {
		int flag = 0;

		while (1 < input)
		{
			input = (input-1) / (flag ? 2 : 9) +1;
			flag = flag ^ 1;
		}

		printf("%s wins.\n", flag ?"Stan": "Ollie");

	}
	return 0;
}