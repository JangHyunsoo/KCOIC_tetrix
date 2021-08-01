#include "Tetrix.h"
#include "Block.h"
#include <Windows.h> //gotoxy
#include <conio.h> //_kbhit()
#include <stdio.h> //puts, gets
Tetrix::Tetrix()
{
}

Tetrix::~Tetrix()
{
}

void Tetrix::init()
{
	//table 초기화
	for (int i = 0; i < 22; i++) {//Y좌표
		for (int j = 0; j < 12; j++) {//X좌표
			if( i==0 || i==21 || j==0 || j==11 ) table[i][j] = 1;
			else table[i][j] = 0;
		}
	}

	//Block 초기화
	Block.setBtype(0);
	Block.setBrotstat(0);
	Block.setBlocX(3);
	Block.setBlocY(21);
}

void Tetrix::Play_tetrix()
{
	CursorView(0);
	//변수들 초기화
	char keytemp;
	init();
	//첫 블럭 큐 생성
	
	//게임 진행
	while (1) {
		//게임 실 진행 전 변수 초기화 및 데이터 불러오기
		printTable();
		for (;1;) { //게임 실 진행
			if (_kbhit()) { //키입력 감지
				keytemp = _getch();
				if (keytemp = EXT_KEY) { //방향키 입력
					keytemp = _getch();
					Block.B_move(keytemp);
				}
				if (keytemp = KEY_HOLD) { //홀드키 입력
				
				}

			}

		}
	}
}

void Tetrix::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tetrix::CursorView(char show)
{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		ConsoleCursor.bVisible = show;
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void Tetrix::isitFull()
{
	int x, y, ty;

	for (int i = 0; i < 4; i++) {
		
	}
}

void Tetrix::printTable()
{
	int x, y;
	for (x = 0; x < TW + 2; x++) {
		for (y = 0; y < TH + 2; y++) {
			gotoxy(TX + Block.getBlocX() * 2, TY + Block.getBlocY() * 2);
			puts(arTile[table[Block.getBlocX()][Block.getBlocY()]]);
		}
	}
}
