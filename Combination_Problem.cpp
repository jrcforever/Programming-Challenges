#include<stdio.h>

#define MAXIMUM_LENGTH 1000

void recursive(int n,int startK,int k) {
	int _result = 1, i;

	if (0 == n || 0 == startK || n == startK)
		;
	else
	{
		for (i = 1; i <= n; i++)
			_result *= i;

		for (i = 1; i <= startK; i++)
			_result /= i;

		for (i = 1; i <= n - startK; i++)
			_result /= i;
	}

	printf("%dC%d = %d ", n, startK,_result);

	if (startK < n && startK < k)
		recursive(n, startK + 1, k);
	else
		return;
}

int main()
{
	char temp[MAXIMUM_LENGTH];
	int i, n, k;

	while (gets(temp) && *temp) {
		sscanf(temp, "%d %d", &n, &k);

		for (i = 0; i <= n; i++) {
			recursive(i,0,k);
			putchar('\n');
		}
	}

	return 0;
}