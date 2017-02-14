
// Polynomial coefficients
// Created by Kim Jong-uk at 2017.01.25
// Protected by MIT license

#include <stdio.h>

#define MAXIMUM_INDEX_NUMBER 13

int main()
{
	unsigned long long index[MAXIMUM_INDEX_NUMBER+1];
	unsigned long long result;
	int k, n, i;

	index[0] = 1;
	for (i = 1; i <= MAXIMUM_INDEX_NUMBER; i++)
		index[i] = index[i - 1] * i;

	while(scanf("%d %d",&k,&n)==2) {
		result = index[k];

		for (i = 0; i < n; i++)
		{
		int temp;

			scanf("%d", &temp);
			if (temp > 1)
				result /= index[temp];
		}

		printf("%lu\n", result);
	}

	return 0;
}