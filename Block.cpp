#include "Block.h"


void CBlock::Input(char inputKey)
{
	//1. 움직이기전에 충돌검사
	//2. 변한 상태 재출력
	switch (inputKey) {
	case KEY_UP: //회전
		Print(false);
		m_iRotation = ++m_iRotation % 4;
		Print(true);
		break;
	case KEY_LEFT: //좌로
		Print(false);
		--m_tPos.x;
		Print(true);
		break;
	case KEY_RIGHT: //우로
		Print(false);
		++m_tPos.x;
		Print(true);		
		break;
	case KEY_DOWN: //하강
		Print(false);
		++m_tPos.y;
		Print(true);
		break;
	}
}

void CBlock::Print(bool show)
{
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			gotoxy(TX + (block[m_iType][m_iRotation][i][j] + m_tPos.x) * 2, TY + block[m_iType][m_iRotation][i][j] + m_tPos.y);
			if(show) puts("■");
			else puts("  ");
		}
	}
}

void CBlock::Merge()
{
}

int CBlock::GetType()
{
	return m_iType;
}

void CBlock::SetType(int type)
{
	m_iType = type;
}

int CBlock::GetRotation()
{
	return this->m_iRotation;
}

void CBlock::SetRotation(int stat)
{
	m_iRotation = stat;
}

int CBlock::GetX()
{
	return this->m_tPos.x;
}

void CBlock::SetX(int loc)
{
	m_tPos.x = loc;
}

int CBlock::GetY()
{
	return m_tPos.y;
}

void CBlock::SetY(int loc)
{
	m_tPos.y = loc;
}

CBlock::CBlock() : m_tPos(0, 0), m_iType(0),m_iRotation(0)
{
}


CBlock::~CBlock()
{
}
