#include <stdio.h>

int fibonacci(int number) {
	if (2 <= number)
		return fibonacci(number - 1) + fibonacci(number - 2);
	else 
		return number;

}

int main()
{
	int input;
	char temp[100];

	while (gets(temp) && *temp)
	{
		sscanf(temp, "%d", &input);
		printf("fibonacci %d = %d\n",input, fibonacci(input));
	}

	return 0;
}