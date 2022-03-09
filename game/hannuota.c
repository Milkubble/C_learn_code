#include "game.h"

void move(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("%c --> %c\n", a, c);
	}
	else
	{
		move(n - 1, a, c, b);
		printf("%c --> %c\n", a, c);
		move(n - 1, b, a, c);
	}
}

void hannuota()
{
	int i = 0;
	char a = 'A';
	char b = 'B';
	char c = 'C';
	printf("ÇëÊäÈëººÅµËþµÄ²ãÊý>:");
	scanf("%d", &i);
	move(i, a, b, c);
	system("pause");
}