#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//ѡ����Ϸ
void menu()
{
	int input2 = 0;
	do
	{
		printf("**********************************\n");
		printf("*     0.����                     *\n");
		printf("*     1.������                   *\n");
		printf("*     2.��ŵ��                   *\n");
		printf("*     3.����������               *\n");
		printf("*                                *\n");
		printf("**********************************\n");
		printf("                       ��ѡ��>:");
		scanf("%d", &input2);
		switch (input2)
		{
		case 0:
			break;
		case 1:
			//��������Ϸ
			sanziqi();
			break;
		case 2:
			hannuota();
			break;
		default:
			printf("��TM˵�˴��������㻹��\n");
			break;
		}
	} while (input2);
}

//��ʼ����
void start()
{
	int input1 = 0;
	srand((unsigned int)time(NULL));
	do
	{
		printf("**********************************\n");
		printf("*                                *\n");
		printf("*                                *\n");
		printf("*     1.��ʼ��Ϸ  0.�˳���Ϸ     *\n");
		printf("*                                *\n");
		printf("*                                *\n");
		printf("**********************************\n");
		printf("                       ��ѡ��>:");
		scanf("%d", &input1);
		switch (input1)
		{
		case 1:
			menu();
			break;
		case 0:
			break;
		default:
			printf("�����ѡ��\n");
			break;
		}
	} while (input1);
}

//����������
void sanziqi()
{
	char Board[szqcol][szqrow] = { 0 };
	//��ʼ������
	InitBoard(Board, szqrow, szqcol);
	//��ӡ����
	PrintBoard(Board, szqrow, szqcol);
	while (1)
	{
		//�������
		Player_Play_snaziqi(Board, szqrow, szqcol);
		PrintBoard(Board, szqrow, szqcol);
		//�ж��Ƿ��ʤ
		if (Is_Win_sanziqi(Board, szqrow, szqcol) == 1)
		{
			printf("��Ӯ��\n");
			break;
		}
		//��������
		Computer_Play_snaziqi(Board, szqrow, szqcol);
		PrintBoard(Board, szqrow, szqcol);
		//�ж��Ƿ��ʤ
		if (1 == Is_Win_sanziqi(Board, szqrow, szqcol))
		{
			printf("������\n");
			break;
		}
		if (0 == Is_Win_sanziqi(Board, szqrow, szqcol))
		{
			printf("ƽ��\n");
			break;
		}
	}
}

int main()
{
	//��ʼ����
	start();
	return 0;
}