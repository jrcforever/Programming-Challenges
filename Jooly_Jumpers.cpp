
// Jolly Jumpers
// Created by Kim Jong-uk at 2016.12.22
// Protected by MIT license

#include<stdio.h>
#include<math.h>

#define MAXMUMSIZE 10000
#define SUCCESS "Jolly"
#define FAIL "Not jolly"
#define TRUE 1
#define FALSE 0

int main()
{
	int maximumNumber;
	int i = 0;
	int previousNumber;
	int nowNumber;
	int tag;
	char temp[MAXMUMSIZE];
	int check[MAXMUMSIZE];

	while (scanf("%d", &maximumNumber) == TRUE)
	{

		tag = TRUE;

		for (i = 0; i < maximumNumber && tag == TRUE; i++)
		{
			scanf("%d", &nowNumber);

			if (i != 0)
			{
				check[abs(nowNumber - previousNumber)] = TRUE;
			}
			else if( i == 0)
				check[i] = TRUE;

			previousNumber = nowNumber;
			
		}

		for (i = 0; i < maximumNumber; i++)
			if (check[i] != TRUE)
				tag = FALSE;

		gets(temp);
		puts(tag ? SUCCESS : FAIL);

		for (i = 0; i < maximumNumber; i++)
			check[i] = FALSE;
	}

	return 0;
}