
// Reverse and Add v2
// Created by Kim Jong-uk at 2017.01.23
// Protected by MIT license

#include <stdio.h>

int main()
{
	int testCase, inverseTime;
	long int testNumber,number, temp;

	scanf("%d", &testCase);

	while (testCase-- > 0)
	{
		scanf("%ld", &testNumber);

		inverseTime = 0;

		while (inverseTime <1000)
		{
			number = testNumber;
			temp = 0;
			
			while (number > 0)
			{
				temp = (temp * 10) + (number % 10);
				number /= 10;
			}

			if (testNumber == temp)
			{
				printf("%d %ld\n", inverseTime, testNumber);
				break;
			}

			testNumber += temp;

			inverseTime++;
			
		}

	}

	return 0;
}