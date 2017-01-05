
// check the check
// Created by Kim Jong-uk at 2016.12.19
// Protected by MIT license

#include <stdio.h>
#include <string.h>

#define SIZE_H 8
#define SIZE_W 8

#define TRUE 1
#define FALSE 0

#define NUM_BLAKC_LOSE 1
#define NUM_WHITE_LOSE 2

int CheckWay(char(*board)[SIZE_W + 1], char king, int start_y, int start_x, int direction_x, int direction_y)
{
	int x = start_x + direction_x, y = start_y + direction_y;
	int check = FALSE;

	while (x >= 0 && y >= 0 && y < SIZE_H && x < SIZE_W&& board[y][x] == '.')
	{
		x += direction_x;
		y += direction_y;
	}

	return (x >= 0 && y >= 0 && y < SIZE_H && x < SIZE_W&& board[y][x] == king);
}

int checkWin(char unit)
{
	if (unit == 'p' || unit == 'r' || unit == 'b' || unit == 'q' || unit == 'k' || unit == 'n')
		return NUM_WHITE_LOSE;
	else
		return NUM_BLAKC_LOSE;
}

int Process(char(*board)[SIZE_W + 1], char unit, int y, int x, char type)
{
	int result = FALSE;
	int i;
	char king;

	if ('K' == type )
		if (unit == 'P' || unit == 'R' || unit == 'B' || unit == 'Q' || unit == 'K' || unit == 'N')
		return 0;

	if ('k' == type )
		if(unit == 'p' || unit == 'r' || unit == 'b' || unit == 'q' || unit == 'k' || unit == 'n')
		return 0;

	
	if (unit == 'p' || unit == 'r' || unit == 'b' || unit == 'q' || unit == 'k' || unit == 'n')
		king = 'K';
	else
		king = 'k';

	switch (unit)
	{
	case 'p':
		if ((x - 1 >= 0 && y + 1 >= 0 && x - 1 < SIZE_W&& y + 1 < SIZE_H && board[y + 1][x - 1] == king)
			|| (x + 1 >= 0 && y + 1 >= 0 && x + 1 < SIZE_W&& y + 1 < SIZE_H &&board[y + 1][x + 1] == king))
			result = checkWin(unit);
		break;
	case 'P':
		if ((x - 1 >= 0 && y - 1 >= 0 && x - 1 < SIZE_W&& y - 1 < SIZE_H && board[y - 1][x - 1] == king)
			|| (x + 1 >= 0 && y - 1 >= 0 && x + 1 < SIZE_W&& y - 1 < SIZE_H && board[y - 1][x + 1] == king))
			result = checkWin(unit);
		break;

	case 'R':
	case 'r':
		if (CheckWay(board, king, y, x, 1, 0))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, 0, 1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, -1, 0))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, 0, -1))
			result = checkWin(unit);
		break;
	case 'B':
	case 'b':
		if (CheckWay(board, king, y, x, 1, 1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, -1, 1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, -1, -1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, 1, -1))
			result = checkWin(unit);
		break;

	case 'Q':
	case 'q':
		if (CheckWay(board, king, y, x, 1, 1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, -1, 1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, -1, -1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, 1, -1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, 1, 0))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, 0, 1))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, -1, 0))
			result = checkWin(unit);
		if (CheckWay(board, king, y, x, 0, -1))
			result = checkWin(unit);
		break;

	case 'K':
	case 'k':
		if ((x - 1 >= 0 && y - 1 >= 0 && x - 1 < SIZE_W&& y - 1 < SIZE_H && board[y - 1][x - 1] == king)
			|| (x >= 0 && y - 1 >= 0 && x < SIZE_W&& y - 1 < SIZE_H &&board[y - 1][x] == king)
			|| (x + 1 >= 0 && y - 1 >= 0 && x + 1 < SIZE_W&& y - 1 < SIZE_H &&board[y - 1][x + 1] == king)
			|| (x + 1 >= 0 && y >= 0 && x + 1 < SIZE_W&& y < SIZE_H &&board[y][x + 1] == king)
			|| (x + 1 >= 0 && y + 1 >= 0 && x + 1 < SIZE_W&& y + 1 < SIZE_H &&board[y + 1][x + 1] == king)
			|| (x >= 0 && y + 1 >= 0 && x < SIZE_W&& y + 1 < SIZE_H &&board[y + 1][x] == king)
			|| (x - 1 >= 0 && y + 1 >= 0 && x - 1 < SIZE_W&& y + 1 < SIZE_H &&board[y + 1][x - 1] == king)
			|| (x - 1 >= 0 && y >= 0 && x - 1 < SIZE_W&& y < SIZE_H &&board[y][x - 1] == king))
			result = checkWin(unit);
		break;

	case 'N':
	case 'n':if ((x - 1 >= 0 && y + 2 >= 0 && y + 2 < SIZE_H && x - 1 < SIZE_W  && board[y + 2][x - 1] == king)
		|| (x + 1 >= 0 && y + 2 >= 0 && y + 2 < SIZE_H && x + 1 < SIZE_W  && board[y + 2][x + 1] == king)
		|| (x - 2 >= 0 && y - 1 >= 0 && y - 1 < SIZE_H && x - 2 < SIZE_W  && board[y - 1][x - 2] == king)
		|| (x - 2 >= 0 && y + 1 >= 0 && y + 1 < SIZE_H && x - 2 < SIZE_W  && board[y + 1][x - 2] == king)
		|| (x - 1 >= 0 && y - 2 >= 0 && y - 2 < SIZE_H && x - 1 < SIZE_W  && board[y - 2][x - 1] == king)
		|| (x + 1 >= 0 && y - 2 >= 0 && y - 2 < SIZE_H && x + 1 < SIZE_W  && board[y - 2][x + 1] == king)
		|| (x + 2 >= 0 && y - 1 >= 0 && y - 1 < SIZE_H && x + 2 < SIZE_W  && board[y - 1][x + 2] == king)
		|| (x + 2 >= 0 && y + 1 >= 0 && y + 1 < SIZE_H && x + 2 < SIZE_W  && board[y + 1][x + 2] == king))
		result = checkWin(unit);
		break;

	default:
		break;
	}

	return result;
}

int main()
{
	int run = TRUE;
	char temp[SIZE_W + 1];
	char board[SIZE_H][SIZE_W + 1];
	int i, j;
	int game_count = 0;;
	int game_result;
	int tagK, tagKK;

	while (TRUE)
	{
		run = FALSE;

		for (i = 0; i < SIZE_H; i++)
			if (strcmp(gets(board[i]), "........"))
				run = TRUE;

		tagK = 0;
		tagKK = 0;

		for (i = 0; i < SIZE_H; i++)
			for (j = 0; j < SIZE_W; j++)
			{ 
				if (board[i][j] == 'k')
					tagK = 1;
				
				if (board[i][j] =='K')
					tagKK = 1;
				
			}

		if (FALSE == run)
			break;

		if (tagK == 0 || tagKK == 0)
			goto next;

		game_count++;

		for (i = 0; i < SIZE_H; i++)
			for (j = 0; j < SIZE_W + 1; j++)
				if (board[i][j] != '.' && Process(board, board[i][j], i, j, 'k'))
				{
					game_result = Process(board, board[i][j], i, j, 'k');
					goto result;
				}

		for (i = 0; i < SIZE_H; i++)
			for (j = 0; j < SIZE_W + 1; j++)
				if (board[i][j] != '.' && Process(board, board[i][j], i, j, 'K'))
				{
					game_result = Process(board, board[i][j], i, j, 'K');
					goto result;
				}

		game_result = 0;

	result:
		if (NUM_BLAKC_LOSE == game_result)
			printf("Game #%d: black king is in check.\n", game_count);
		else if (NUM_WHITE_LOSE == game_result)
			printf("Game #%d: white king is in check.\n", game_count);
		else
			printf("Game #%d: no king is in check.\n", game_count);

	next:
		gets(board[0]);

		

	}

	return 0;
}
