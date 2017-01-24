
// Reverse and Add
// Created by Kim Jong-uk at 2017.01.23
// Protected by MIT license

#include <stdio.h>

int Inverse(unsigned long number) {
	unsigned long temp = 0;

	while(number != 0)
	{ 
		temp = (temp *10) + (number % 10);
		number /= 10;
	}
	return temp;
}

int main()
{
	int testCase, inverseTime ;
	unsigned long testNumber, temp;

	scanf("%d", &testCase);

	while (testCase-- > 0)
	{
		scanf("%lu", &testNumber);

		inverseTime = 0;

		while (testNumber != (temp = Inverse(testNumber)) || inverseTime ==0 )
		{ 
			testNumber += temp;
			inverseTime++;
		} 

		printf("%d %lu\n", inverseTime, testNumber);

	}

	return 0;
}