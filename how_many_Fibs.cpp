// How many Fibs?
// Created by Kim Jong-uk at 2017.02.09
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define MAXIMUM_STRING_LENGTH 100

char Fib[3][MAXIMUM_STRING_LENGTH + 1];
char Result[2][MAXIMUM_STRING_LENGTH + 1];
int lengthA, lengthB, fibLength[3];

int compare(int targetA,char *point, int len) {
	int i;

	if (len > fibLength[targetA])
		return 0;
	if (len < fibLength[targetA]);
		return 1;
	for (i = len - 1; i >= 0; i--)
		if (point[i] > Fib[targetA][i])
			return 0;
		else
			return 1;
}

void Fibs(int destiny, int second, int first) {
	int i,len = 0, carry = 0;

	for (; len < fibLength[second] && len < fibLength[first]; len++)
	{
		Fib[destiny][len] = (Fib[second][len] + Fib[first][len] + carry);
		if (Fib[destiny][len] >= 10)
			carry = 1;
		else
			carry = 0;
		Fib[destiny][len] %= 10;
	}

	if (len < fibLength[second])
	{
		for (; len < fibLength[second] ; len++)
		{
			Fib[destiny][len] = (Fib[second][len] + carry);
			if (Fib[destiny][len] >= 10)
				carry = 1;
			else
				carry = 0;
			Fib[destiny][len] %= 10;
		}
	}
	else
	{
		for (; len < fibLength[first]; len++)
		{
			Fib[destiny][len] = (Fib[first][len] + carry);
			if (Fib[destiny][len] >= 10)
				carry = 1;
			else
				carry = 0;
			Fib[destiny][len] %= 10;
		}
	}

	if (carry)
		Fib[destiny][len++] = 1;

	fibLength[destiny] = len;

}

int input() {
	int i;
	char temp1[MAXIMUM_STRING_LENGTH + 1], temp2[MAXIMUM_STRING_LENGTH + 1];

	scanf("%s %s", &temp1, &temp2);

	lengthA = strlen(temp1);
	lengthB = strlen(temp2);

	if (temp1[0] == '0' && temp2[0] == '0')
		return 0;
	
	for (i = 0; i < lengthA; i++)
		Result[0][i] = Result[0][lengthA - 1 - i]- '0';
	for (i = 0; i < lengthA; i++)
		Result[1][i] = Result[1][lengthA - 1 - i]- '0';
	return 1;
}

int main()
{
	while (input())
	{
		int i, result;

		fibLength[0] = fibLength[1] = 1;
		Fib[0][0] = Fib[1][0] = 1;

		for (i = 0; compare(i % 3, Result[0], lengthA) == 0; i++)
			Fibs((i + 1) % 3, i % 3, (i - 1) % 3);
		result = i;
		for (i = 0; compare(i % 3, Result[1], lengthA) == 0; i++)
			Fibs((i + 1) % 3, i % 3, (i - 1) % 3);
		result = result - i;

		printf("%d", result);;
	}

	return 0;
}