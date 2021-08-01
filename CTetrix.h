#pragma once
#include "Block.h"
#include <queue>
#define EXT_KEY			0xffffffe0 //확장키 인식값
#define KEY_HOLD		0x5A	//Z

using namespace std;
class CTetrix
{
private:
	bool table[TH + 2][TW + 2] = { 0, }; //[y][x] 가로10칸, 세로20칸
	CBlock Block;
	queue<int> blockQue;
	queue<int> previewQue;
public:
	CTetrix();
	~CTetrix();
	void init();
	
	void Play_tetrix();
	void printTable();
	bool checkAround(int x, int y,int bt, int r); //충돌감지
//	void refillque(); //블록 새로 채우기
	void makeNewque(); //게임 시작전 블록 목록 만들기
//	void printQue(); //앞으로 나올 블록 몇개 보여주기

	void gotoxy(int x, int y);
	void CursorView(char show);

};

