#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char Board[szqrow][szqrow], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			Board[i][j] = ' ';
		}
	}
}

void PrintBoard(char Board[szqrow][szqcol], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", Board[i][j]);
			if (j != col - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < col + 1 && i != row - 1; j++)
		{
			printf("---");
		}
		printf("\n");
	}
}

void Player_Play_snaziqi(char Board[szqrow][szqcol], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家下(x,y)>:");
		scanf("%d,%d", &x, &y);
		printf("\n");
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			if (Board[y - 1][x - 1] == ' ')
			{
				Board[y - 1][x - 1] = '*';
				break;
			}
			else
			{
				printf("你输入的坐标被占用\n");
			}
		}
		else
		{
			printf("你输入的坐标不合法，请从新输入\n");
		}
	}
}

void Computer_Play_snaziqi(char Board[szqrow][szqcol], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下>:\n");
	Sleep(1000);
	while (1)
	{
		x = rand() % col;
		y = rand() % row;
		if (Board[y][x] == ' ')
		{
			Board[y][x] = '#';
			break;
		}
	}
}

int Is_Full(char Board[szqrow][szqcol], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (Board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

int Is_Win_sanziqi(char Board[szqrow][szqcol], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//所有赢的情况
		if ((Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ') ||//横
			(Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[0][i] != ' ') ||//竖
			(Board[1][1] == Board[0][0] && Board[2][2] == Board[0][0] && Board[0][0] != ' ') ||//
			(Board[1][1] == Board[0][2] && Board[2][0] == Board[0][0] && Board[0][0] != ' '))//  斜
			return 1;
		//判断平局
		if (1 == Is_Full(Board, row, col))
			return 0;
	}
}