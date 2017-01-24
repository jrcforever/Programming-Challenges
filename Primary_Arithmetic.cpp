
// Primary Arithmetic
// Created by Kim Jong-uk at 2017.01.23
// Protected by MIT license

#include <stdio.h>


int main()
{
	while (1) {
		int compareA, compareB;
		int carry = 0;
		int carryCount = 0;
		int temp;

		scanf("%d %d", &compareA, &compareB);

		if (compareA == 0 && compareB == 0)
			break;

		while (1) {
			if (compareA == 0 && compareB == 0)
				break;
			temp = compareA % 10 + compareB % 10 + carry;

			if (temp >= 10)
			{
				carry = 1;
				carryCount++;
			}
			else
				carry = 0;

			compareA /= 10;
			compareB /= 10;
		}

		if (carryCount == 0)
			printf("No carry operation.\n");
		else
			printf("%d carry operation.\n",carryCount);
	}

	return 0;
}