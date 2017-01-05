
// The Trip
// Created by Kim Jong-uk at 2016.12.16
// Protected by MIT license

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define MAXIMUM_MEMEBER 1000

int compare(void const *first, void const *second) {
	return *(int*)second - *(int*)first;
}

int main()
{
	int member, i;
	int pay[MAXIMUM_MEMEBER];
	int average_pay[MAXIMUM_MEMEBER];
	double temp;
	int total_cost;
	double result_cost;
	int k;

	while(TRUE)
	{
		total_cost = 0;
		result_cost = 0;

		scanf("%d", &member);

		if (member <= 0)
			return 0;

		for (i = 0; i < member; i++)
		{
			scanf("%lf", &temp);
			pay[i] = (int)(temp * 100 + 0.5);
			total_cost += pay[i];
		}
		
		for(i = 0 ; i < member; i ++)
			average_pay[i] = total_cost / member;
		
		k = total_cost % member;

		qsort(pay, member, sizeof(int), compare);
		
		for (i = 0; i < k; i++)
			average_pay[i]++;
		
		for(i = 0 ; i < member; i++)
			result_cost += abs(pay[i] - average_pay[i]);
		
		printf("$%0.2f\n", (result_cost / 100.0) / 2);
	}

	return 0;
}