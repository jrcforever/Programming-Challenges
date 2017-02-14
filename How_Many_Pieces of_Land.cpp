// How Many Pieces of Land?
// Created by Kim Jong-uk at 2017.02.09
// Protected by MIT license

#include <stdio.h>

#define NUMBER_LENGTH 20
#define LIMIT 10000

typedef struct newlong {
	unsigned int value[NUMBER_LENGTH];
} Newlong;

static Newlong Result, TempResult;

void allocate(Newlong *space, unsigned int input) {
	for (int i = 0; i < NUMBER_LENGTH; i++)
	{
		space->value[i] = input % LIMIT;
		input /= LIMIT;
	}
}

void add(Newlong *space, const Newlong *addA, const Newlong *addB) {
	int carry = 0;

	for (int i = 0; i < NUMBER_LENGTH; i++) {
		space->value[i] = addA->value[i] + addB->value[i] + carry;
		carry = space->value[i] / LIMIT;
		space->value[i] %= LIMIT;
	}
}

void mul(Newlong* space, const Newlong *mulA, const Newlong *mulB) {
	Newlong _temp;
	unsigned int temp;
	int indexI, indexJ;

	for (int i = 0; i < NUMBER_LENGTH; i++)
		_temp.value[i] = 0;
	indexI = indexJ = NUMBER_LENGTH - 1;

	while (0 == mulA->value[indexI])
		indexI--;
	indexI++;

	while (0 == mulB->value[indexJ])
		indexJ--;
	indexJ++;

	for (int i = 0; i < indexI + 1; i++)
	{
		int carry = 0;
		for (int j = 0; j <indexJ + 1; j++)
			if (i + j < NUMBER_LENGTH)
			{
				temp = (_temp.value[i + j] + mulA->value[i] * mulB->value[j] + carry) % LIMIT;
				carry = (_temp.value[i + j] + mulA->value[i] * mulB->value[j] + carry) / LIMIT;
				_temp.value[i + j] = temp;
			}
	}

	for (int i = 0; i < NUMBER_LENGTH; i++)
		space->value[i] = _temp.value[i];

}

void print(const Newlong *input) {
	int _check_end_point = 0;
	for (int i = NUMBER_LENGTH - 1; i >= 0; i--)
		if (!(0 == _check_end_point && 0 == input->value[i]))
			if (0 == _check_end_point) {
				printf("%u", input->value[i]);
				_check_end_point = 1;
			}
			else
				printf("%04u", input->value[i]);

	if (0 == _check_end_point)
		printf("0");
}

void comb(int n, int k)
{
	int temp, check[4] = { 0, };
	Newlong _temp;

	allocate(&TempResult, 1);
	for (int i = n; i > n - k; i--) {
		temp = i;
		for (int j = k; j > 0; j--)
		{
			if (check[j - 1]) continue;
			if (0 == temp%j)
			{
				check[j - 1] = 1;
				temp /= j;
			}
		}
		allocate(&_temp, temp);
		mul(&TempResult, &TempResult, &_temp);
	}
}

int main()
{
	int testCase, n;

	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++)
	{
		scanf("%d", &n);

		allocate(&Result, 1);

		comb(n, 2);
		add(&Result, &Result, &TempResult);

		comb(n, 4);
		add(&Result, &Result, &TempResult);

		print(&Result);
		putchar('\n');
	}

	return 0;
}