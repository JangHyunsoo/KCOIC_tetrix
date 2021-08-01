#include "CTetrix.h"
#include <Windows.h> //gotoxy
#include <conio.h> //_kbhit()

#include <time.h> // time 함수가 포함되어 있는 헤더파일 
#include <stdlib.h> // srand, rand 함수가 포함되어 있는 헤더파일


CTetrix::CTetrix()
{
}


CTetrix::~CTetrix()
{
}

void CTetrix::init()
{
	//table 초기화
	for (int i = 0; i < 22; i++) {//Y좌표
		for (int j = 0; j < 12; j++) {//X좌표
			if (i == 0 || i == 21 || j == 0 || j == 11) table[i][j] = 1;
			else table[i][j] = 0;
		}
	}
	Block = CBlock();
	//Block 초기화
	Block.setBtype(0);
	Block.setBrotstat(0);
	Block.setBlocX(3);
	Block.setBlocY(0);
	
}

void CTetrix::Play_tetrix()
{
	CursorView(0); //커서가 깜빡이지 않게

	char keytemp;
	init();
	makeNewque();
	printTable();
	
	Block.setBtype(blockQue.front());
	while (1) {
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp = EXT_KEY) { //방향키 입력
				keytemp = _getch();
				if (keytemp != KEY_UP) {
					checkAround(Block.getBlocX(), Block.getBlocY(), Block.getBtype(), Block.getBrotstat());
					Block.B_move(keytemp);
				}
				else Block.B_move(keytemp);
			}
			if (keytemp = KEY_HOLD) { //홀드키 입력

			}
		}
	}
}

void CTetrix::printTable()
{
	int x = 0;
	int y = 0;
	for (x=0; x < TW + 2; x++) {		
		for (y=0; y < TH + 2; y++) {
			gotoxy(TX + x * 2, TY + y);
			if (table[y][x])puts("■");
			//else puts("□"); 걍 공백으로 두는게 깔끔함
			//block은 따로 printBlock 하는 편이 나을듯
			//gotoxy(TX + Block.getBlocX() * 2, TY + Block.getBlocY());
			
		}
	}
	//임시
	gotoxy(42, 3); puts("Tetris Ver 1.0");
	gotoxy(42, 5); puts("좌우:이동, 위:회전, 아래:내림");
	gotoxy(42, 6); puts("공백:전부 내림");
	gotoxy(42, 21); //계속하려면 ~~
	//
}

bool CTetrix::checkAround(int x, int y, int bt, int r)
{
	int i=0,j=0; 
	for (i = 0; i < 4; i++) {
		for (; j < 4; j++) {
		if (table[x + Block.block[bt][r][j][i]][y + Block.block[bt][r][j][i]])
			return true;
		}
	}
	return false;
}

void CTetrix::makeNewque()
{
	while (!blockQue.empty())
		blockQue.pop();
	while (!previewQue.empty())
		previewQue.pop();
	//두개의 큐 초기화
	srand(time(NULL));
	int temp[7] = { 0, };
	for (int i = 0; i < 7; i++) {
		int randm = rand() % 7;
		if(i==0) temp[i] = randm;
		else {
			for (int j = 0; j < i; j++) {
				if (randm == temp[i]) {
					i--; break;
				}
				if(j == i-1) temp[i] = randm;
			}
		} 
	}
	for(int i = 0; i<7;i++)
		blockQue.push(temp[i]);
}



void CTetrix::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CTetrix::CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
