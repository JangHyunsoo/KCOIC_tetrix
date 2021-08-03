#pragma once
#include "Common.h"

using namespace std;
class CTetrix
{
public:
	CTetrix();
	~CTetrix();
private:
	bool table[TH + 2][TW + 2] = { 0, }; //[y][x] ����10ĭ, ����20ĭ
	class CBlock* m_pBlock;
	queue<int> m_queBlock;
	queue<int> m_quePreview;
private:
	void init();
	void Print();
	bool checkAround(int x, int y,int bt, int r); //�浹����
//	void refillque(); //��� ���� ä���
	void makeNewque(); //���� ������ ��� ��� �����
//	void printQue(); //������ ���� ��� � �����ֱ�
	void CursorView(char show);
public:
	void Run();

};

