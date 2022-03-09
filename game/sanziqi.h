#define szqrow  3//y
#define szqcol  3//x
#define szqrows szqrow-1
#define szqcols szqcol-1

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void sanziqi();


void InitBoard(char Board[szqrow][szqcol], int row, int col);
void PrintBoard(char Board[szqrow][szqcol], int row, int col);
void Player_Play_snaziqi(char Board[szqrow][szqcol], int row, int col);
void Computer_Play_snaziqi(char Board[szqrow][szqcol], int row, int col);
int Is_Win_sanziqi(char Board[szqrow][szqcol], int row, int col);
//赢返回1
//输返回2
//平返回0
