
// Graphical Editor
// Created by Kim Jong-uk at 2016.12.18
// Protected by MIT license

#include <stdio.h>
#define TRUE 1
#define MAXSIZE 251

static char bitmap[MAXSIZE][MAXSIZE];
static int bitmap_x = 0, bitmap_y = 0;

void setbitMap(int index_x, int index_y, char origenColor)
{
	bitmap[index_y][index_x] = origenColor;
}

void setbitRecuresiveMap(int index_x, int index_y, char origenColor, char setColor)
{
	if (origenColor == setColor)
		return;
	bitmap[index_y][index_x] = setColor;

	if (index_x < bitmap_x && bitmap[index_y][index_x+1]== origenColor)
		setbitRecuresiveMap(index_x + 1, index_y, origenColor, setColor);
	if (index_x > 1 && bitmap[index_y][index_x - 1] == origenColor)
		setbitRecuresiveMap(index_x - 1, index_y, origenColor, setColor);
	if (index_y < bitmap_y && bitmap[index_y+1][index_x] == origenColor)
		setbitRecuresiveMap(index_x , index_y+1, origenColor, setColor);
	if (index_y > 1 && bitmap[index_y-1][index_x ] == origenColor)
		setbitRecuresiveMap(index_x, index_y-1, origenColor, setColor);
}

int main()
{
	char mode, color;

	int i, j, temp;
	int start_bitmap_x, start_bitmap_y, final_bitmap_x = 0, final_bitmap_y;
	char name[255];

	while (TRUE) {

		scanf("%c", &mode);

		switch (mode) {
		
		case 'I':
			scanf("%d %d", &bitmap_x, &bitmap_y);

			for (i = 1; i <= bitmap_y; i++)
				for (j = 1; j <= bitmap_x; j++)
					setbitMap( j, i, 'O');
			break;
		
		case 'C':
			for (i = 1; i <= bitmap_y; i++)
				for (j = 1; j <= bitmap_x; j++)
					setbitMap( j, i, 'O');

			break;
		
		case 'L':
			scanf("%d %d %c", &start_bitmap_x, &start_bitmap_y, &color);
			setbitMap(start_bitmap_x, start_bitmap_y, color);
			break;
		
		case 'V':
			scanf("%d %d %d %c", &start_bitmap_x, &start_bitmap_y, &final_bitmap_y, &color);
			if (start_bitmap_y > final_bitmap_y)
			{
				temp = start_bitmap_y;
				start_bitmap_y = final_bitmap_y;
				final_bitmap_y = temp;
			}
				
			for (i = start_bitmap_y; i <= final_bitmap_y; i++)
				setbitMap(start_bitmap_x, i, color);
			break;

		case 'H':
			scanf("%d %d %d %c", &start_bitmap_x, &final_bitmap_x, &start_bitmap_y, &color);
			if (start_bitmap_x > final_bitmap_x)
			{
				temp = start_bitmap_x;
				start_bitmap_x = final_bitmap_x;
				final_bitmap_x = temp;
			}

			for (i = start_bitmap_x; i <= final_bitmap_x; i++)
				setbitMap(i, start_bitmap_y, color);
			break;
		
		case 'K':
			scanf("%d %d %d %d %c", &start_bitmap_x, &start_bitmap_y, &final_bitmap_x, &final_bitmap_y, &color);
			if (start_bitmap_x > final_bitmap_x)
			{
				temp = start_bitmap_x;
				start_bitmap_x = final_bitmap_x;
				final_bitmap_x = temp;
			}
			if (start_bitmap_y > final_bitmap_y)
			{
				temp = start_bitmap_y;
				start_bitmap_y = final_bitmap_y;
				final_bitmap_y = temp;
			}

			for (j = start_bitmap_y; j <= final_bitmap_y; j++)
				for (i = start_bitmap_x; i <= final_bitmap_x; i++)
					setbitMap(i, j, color);

			break;
		
		case 'F':
			scanf("%d %d %c", &start_bitmap_x, &start_bitmap_y, &color);
			setbitRecuresiveMap(start_bitmap_x, start_bitmap_y, bitmap[start_bitmap_y][start_bitmap_x], color);
			break;

		case 'S':
			scanf("%s", &name);

			printf("%s\n", name);
			for (j = 1; j <= bitmap_y; j++)
			{
				for (i = 1; i <= bitmap_x; i++)
					printf("%c", bitmap[j][i]);
				printf("\n");
			}
			break;
		
		case 'X':
			return 0;
			break;

		default:
			break;
		}



	}
	return 0;
}