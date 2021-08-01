#include "Block.h"
#include <stdio.h> //puts, gets


void CBlock::B_move(char inputKey)
{
	//1. 움직이기전에 충돌검사
	//2. 변한 상태 재출력
	switch (inputKey) {
	case KEY_UP: //회전
		printB(false);
		B_rot_stat = ++B_rot_stat % 4;
		printB(true);
		break;
	case KEY_LEFT: //좌로
		printB(false);
		--B_locX;
		printB(true);
		break;
	case KEY_RIGHT: //우로
		printB(false);
		++B_locX;
		printB(true);		
		break;
	case KEY_DOWN: //하강
		printB(false);
		++B_locY;
		printB(true);
		break;
	}
}

void CBlock::printB(bool show)
{
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			gotoxy(TX + (block[B_type][B_rot_stat][i][j] + B_locX) * 2, TY + block[B_type][B_rot_stat][i][j] + B_locY);
			if(show) puts("■");
			else puts("  ");
		}
	}
}

void CBlock::mergeB()
{
}

int CBlock::getBtype()
{
	return this->B_type;
}

void CBlock::setBtype(int type)
{
	B_type = type;
}

int CBlock::getBrotstat()
{
	return this->B_rot_stat;
}

void CBlock::setBrotstat(int stat)
{
	B_rot_stat = stat;
}

int CBlock::getBlocX()
{
	return this->B_locX;
}

void CBlock::setBlocX(int loc)
{
	B_locX = loc;
}

int CBlock::getBlocY()
{
	return this->B_locY;
}

void CBlock::setBlocY(int loc)
{
	B_locY = loc;
}

void CBlock::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

CBlock::CBlock() : B_locX(0), B_locY(0), B_type(0),B_rot_stat(0)
{
}


CBlock::~CBlock()
{
}
