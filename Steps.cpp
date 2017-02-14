// Steps
// Created by Kim Jong-uk at 2017.02.07
// Protected by MIT license

#include <stdio.h>

unsigned solve(unsigned start, unsigned end)
{
	unsigned input = end- start;
	unsigned i;
	unsigned long result = 1;

	if (0 == input)
		return 0;
	if (1 == input)
		return 1;

	for (i = 2; result < input; i++)
		result += (i+1)/ 2;

	return i-1;
}

int main()
{
	unsigned i, testCase;

	scanf("%u", &testCase);

	for ( i = 0; i < testCase; i++)
	{
		unsigned start, end;

		scanf("%u %u", &start, &end);
		printf("%u\n", solve(start, end));
	}

	return 0;
}