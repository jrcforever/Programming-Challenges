
// The 3n+1 Problem
// Created by Kim Jong-uk at 2016.12.18
// Protected by MIT license

#include <stdio.h>
int main()
{
	unsigned long i = 0, j= 0, temp = 0;
	unsigned long tag, cycleCount, innerCount, prog;
	unsigned long ii = 0, jj = 0;

	while (scanf("%ld %ld",&ii,&jj) != EOF) {

		i = ii;
		j = jj;

		cycleCount = 0;

		if (jj < ii)
		{
			temp = j;
			j = i;
			i = temp;
		}

		for (tag = i; tag <= j; tag++)
		{
			prog = tag;
			innerCount = 1;

			while (prog != 1)
			{
				if (prog & 1)
				{
					prog = prog * 3 + 1;
					innerCount++;
				}
				while (!(prog & 1)) {
					prog >>= 1;
					innerCount++;
				}
				
			}

			if (innerCount > cycleCount)
				cycleCount = innerCount;
		}

		printf("%ld %ld %ld\n", ii, jj, cycleCount);

	}

	return 0;
}