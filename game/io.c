#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//选择游戏
void menu()
{
	int input2 = 0;
	do
	{
		printf("**********************************\n");
		printf("*     0.返回                     *\n");
		printf("*     1.三子棋                   *\n");
		printf("*     2.汉诺塔                   *\n");
		printf("*     3.（待开发）               *\n");
		printf("*                                *\n");
		printf("**********************************\n");
		printf("                       请选择>:");
		scanf("%d", &input2);
		switch (input2)
		{
		case 0:
			break;
		case 1:
			//三子棋游戏
			sanziqi();
			break;
		case 2:
			hannuota();
			break;
		default:
			printf("都TM说了待开发，你还点\n");
			break;
		}
	} while (input2);
}

//开始界面
void start()
{
	int input1 = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("**********************************\n");
		printf("*                                *\n");
		printf("*                                *\n");
		printf("*     1.开始游戏  0.退出游戏     *\n");
		printf("*                                *\n");
		printf("*                                *\n");
		printf("**********************************\n");
		printf("                       请选择>:");
		scanf("%d", &input1);
		switch (input1)
		{
		case 1:
			menu();
			break;
		case 0:
			break;
		default:
			printf("请从新选择\n");
			break;
		}
	} while (input1);
}

//游玩三子棋
void sanziqi()
{
	char Board[szqcol][szqrow] = { 0 };
	//初始化棋盘
	InitBoard(Board, szqrow, szqcol);
	//打印棋盘
	PrintBoard(Board, szqrow, szqcol);
	while (1)
	{
		//玩家下棋
		Player_Play_snaziqi(Board, szqrow, szqcol);
		PrintBoard(Board, szqrow, szqcol);
		//判断是否获胜
		if (Is_Win_sanziqi(Board, szqrow, szqcol) == 1)
		{
			printf("你赢了\n");
			break;
		}
		//电脑下棋
		Computer_Play_snaziqi(Board, szqrow, szqcol);
		PrintBoard(Board, szqrow, szqcol);
		//判断是否获胜
		if (1 == Is_Win_sanziqi(Board, szqrow, szqcol))
		{
			printf("你输了\n");
			break;
		}
		if (0 == Is_Win_sanziqi(Board, szqrow, szqcol))
		{
			printf("平局\n");
			break;
		}
	}
}

int main()
{
	//开始画面
	start();
	return 0;
}