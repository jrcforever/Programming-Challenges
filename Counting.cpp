// Counting
// Created by Kim Jong-uk at 2017.02.13
// Protected by MIT license

#include <stdio.h>

#define INPUT_MAXIMUM 3000
#define WIDTH 10000
#define MAXSIZE 10000

// 1 2 3 4  1 == 4
// numberring over head

static unsigned temp[MAXSIZE][INPUT_MAXIMUM];
void present(unsigned k) {

	int sw = 0;

	for (int i = INPUT_MAXIMUM-1; i >=0 ; i--)
	{
		if (!(0 == sw && 0 == temp[k][i]))
		{
			if (0 == sw)
			{
				printf("%u", temp[k][i]);
				sw = 1;
			}
			else
				printf("%04u", temp[k][i]);
		}
	}
	if (0 == sw)
		printf("0");
}

void add(unsigned dest, unsigned a)
{
	unsigned carry = 0;
	unsigned tempValue;

	for (int i = 0; i < INPUT_MAXIMUM; i++)
	{
		tempValue = temp[dest][i] + temp[a][i]+ carry;
		carry = tempValue / WIDTH;
		temp[dest][i] = tempValue % WIDTH;
	}

}

void mul(unsigned result,unsigned dest, unsigned a)
{
	unsigned carry = 0;
	unsigned tempValue;

	for (int i = 0; i < INPUT_MAXIMUM; i++)
	{
		tempValue = temp[result][i]+temp[dest][i]*a + carry;
		carry = tempValue / WIDTH;
		temp[result][i] = tempValue % WIDTH;
	}
}

void counting(unsigned in)
{
	temp[1][0] = 2;
	temp[2][0] = 5;
	temp[3][0] = 13;

	for (int i = 4; i <= in; i++)
	{
		add(i, i - 3);
		add(i, i - 2);
		mul(i, i - 1, 2);
	}
		
	
}

int main()
{
	unsigned inputNumb;

	counting(1000);

	while (scanf("%u", &inputNumb) != EOF)
	{
		present(inputNumb);
		putchar('\n');
	}
	return 0;
}