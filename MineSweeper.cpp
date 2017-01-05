
// MineSweeper
// Created by Kim Jong-uk at 2016.12.16
// Protected by MIT license

#include <stdio.h>

int main()
{
	int x, y;
	int i, j;
	char field[100][100];
	int stage_num = 1;
	char temp;

	while (1) {
		scanf("%d %d", &y, &x);

		if (x <= 0 || y <= 0 || x >100 || y > 100)
			return 0;

		for (j = 0; j < y; j++)
		{
			scanf("%s", &field[j]);
		}

		for (i = 0; i < x; i++)
			for (j = 0; j < y; j++)
				if (field[j][i] != '*')
					field[j][i] = 48;

		for (j = 0; j < y; j++)
			for (i = 0; i < x; i++)
			{
				temp = field[j][i];

				if (temp == '*') {
					if (i - 1 >= 0 && j - 1 >= 0 && field[j - 1][i - 1] != '*') {
						field[j - 1][i - 1]++;
					}
					if (j - 1 >= 0 && field[j - 1][i] != '*') {
						field[j - 1][i]++;
					}
					if (i + 1 < x && j - 1 >= 0 && field[j - 1][i + 1] != '*') {
						field[j - 1][i + 1]++;
					}
					if (i - 1 >= 0 && field[j][i - 1] != '*') {
						field[j][i - 1]++;
					}
					if (i + 1 < x && field[j][i + 1] != '*') {
						field[j][i + 1]++;
					}
					if (i - 1 >= 0 && j + 1 < y && field[j + 1][i - 1] != '*') {
						field[j + 1][i - 1]++;
					}
					if (j + 1 < y && field[j + 1][i] != '*') {
						field[j + 1][i]++;
					}
					if (i + 1 < x && j + 1 < y && field[j + 1][i + 1] != '*') {
						field[j + 1][i + 1]++;
					}
				}
			}

		if (stage_num > 1)
			printf("\n");

		printf("Field #%d:\n", stage_num++);

		for (j = 0; j < y; j++)
		{
			for (i = 0; i < x; i++)
				printf("%c", field[j][i]);
			printf("\n");
		}
	}

	return 0;
}