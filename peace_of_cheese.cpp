// Peace of Cheese
// Created by Kim Jong-uk at 2017.02.06
// Protected by MIT license

/* test case

8 9
0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0
0 0 0 1 1 0 1 1 0
0 0 1 1 1 1 1 1 0
0 0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
result 4

9 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
result 3
*/

#include <stdio.h>

#define WIDTH 100
#define HIGH 100

static unsigned map[WIDTH][HIGH];
static unsigned x, y;

void melt(unsigned _y, unsigned _x) {
	unsigned check = 0;

	if (map[_y][_x] != 1)
		return;

	if (_x+1 <x && map[_y][_x + 1] == 7)
		check++;
	if (_x-1 >=0 && map[_y][_x -1] == 7)
		check++;
	if (_y+1 <y && map[_y+1][_x] == 7)
		check++;
	if (_y-1 >= 0 &&map[_y-1][_x] == 7)
		check++;

	if (check >= 2)
		map[_y][_x] = 0;
}

int check() {
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			if (map[i][j] == 1)
				return 1;

	return 0;
}

void fill(unsigned _y, unsigned _x, unsigned from, unsigned to)
{

	map[_y][_x] = to;

    if (_x >= 1 && map[_y][_x - 1] == from)
		fill(_y, _x - 1,from,to);
	if (_x < x-1 && map[_y][_x + 1] == from)
		fill(_y, _x + 1,from,to);
	if (_y >= 1 && map[_y -1][_x] == from)
		fill(_y - 1, _x,from,to);
	if (_y  < y-1 && map[_y + 1][_x] == from)
		fill(_y + 1, _x,from,to);

}

int main()
{
	while (scanf("%u %u", &y, &x) == 2)
	{
		unsigned hour = 0;

		for (int i = 0; i < y; i++)
			for (int j = 0; j < x; j++)
				scanf("%d", &map[i][j]);
		 
		while (check()) {
			fill(0, 0,0 , 7);

			for (int i = 0; i < y; i++)
				for (int j = 0; j < x; j++)
					melt(i, j);

			hour++;
			fill(0, 0, 7, 0);

		}
		
		printf("hour:%u\n", hour);

	}

	return 0;
}