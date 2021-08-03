#pragma once
#include "Common.h"

using namespace std;
class CTetrix
{
public:
	CTetrix();
	~CTetrix();
private:
	bool table[TH + 2][TW + 2] = { 0, }; //[y][x] 가로10칸, 세로20칸
	class CBlock* m_pBlock;
	queue<int> m_queBlock;
	queue<int> m_quePreview;
private:
	void init();
	void Print();
	bool checkAround(int x, int y,int bt, int r); //충돌감지
//	void refillque(); //블록 새로 채우기
	void makeNewque(); //게임 시작전 블록 목록 만들기
//	void printQue(); //앞으로 나올 블록 몇개 보여주기
	void CursorView(char show);
public:
	void Run();

};

