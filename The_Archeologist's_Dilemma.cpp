
// The Archeologist's Dilemma
// Created by Kim Jong-uk at 2017.01.24
// Protected by MIT license

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXIMUM_LENGTH 10

int main()
{
	char temp[MAXIMUM_LENGTH + 1];
	char compare[MAXIMUM_LENGTH + 1];

	while (gets_s(temp) && * temp) {
		int length = strlen(temp);
		int i, j;
		int exponent = 0;

		while(1) { 
			unsigned long int Numtemp;
			int tag = 1;
			
			Numtemp = (unsigned long int)powl(2.0f, (double)exponent);

			printf("%ld\n", Numtemp);


			snprintf(compare, MAXIMUM_LENGTH + 1, "%ld", Numtemp);
			printf("%s %d %d\n", compare, strlen(compare),length);
			
			if (strlen(compare) >= length * 2 + 1)
			{
				

				for (i = length - 1, j = strlen(compare) - 1; i >= 0; i--, j--)
				{
					if (temp[i] == compare[j])
						;
					else
						tag = 0;
				}
			
				if (tag == 1)
				{
					printf("%d\n", exponent);
					break;
				}
			
			}
			
			exponent++;
		}

	}
	

	return 0;
}