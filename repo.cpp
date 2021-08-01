#include <iostream>
#include <algorithm>
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define BX 5
#define BY 1
#define BW 10
#define BH 20

void DrawScreen();
void DrawBoard();
bool ProcessKey();
void PrintBrick(bool Show);
int GetAround(int x, int y, int b, int r);
bool MoveDown();
void TestFull();

struct Point {
	int x, y;
};

Point Shape[][4][4] = {
	{ { 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 },{ 0,0,1,0,2,0,-1,0 },{ 0,0,0,1,0,-1,0,-2 } },

{ { 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 },{ 0,0,1,0,0,1,1,1 } },

{ { 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 },{ 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,1,-1,0,-1,-1 } },

{ { 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 },{ 0,0,-1,-1,0,-1,1,0 },{ 0,0,-1,0,-1,1,0,-1 } },

{ { 0,0,-1,0,1,0,-1,-1 },{ 0,0,0,-1,0,1,-1,1 },{ 0,0,-1,0,1,0,1,1 },{ 0,0,0,-1,0,1,1,-1 } },

{ { 0,0,1,0,-1,0,1,-1 },{ 0,0,0,1,0,-1,-1,-1 },{ 0,0,1,0,-1,0,-1,1 },{ 0,0,0,-1,0,1,1,1 } },

{ { 0,0,-1,0,1,0,0,1 },{ 0,0,0,-1,0,1,1,0 },{ 0,0,-1,0,1,0,0,-1 },{ 0,0,-1,0,0,-1,0,1 } },
};

enum { EMPTY, BRICK, WALL };
char *arTile[] = { ". ","■","□" };
int board[BW + 2][BH + 2];
int nx, ny;
int brick, rot;

void main()
{
	int nFrame, nStay;
	int x, y;

	setcursortype(NOCURSOR);
	randomize();
	clrscr();

	for (x = 0; x<BW + 2; x++) {
		for (y = 0; y<BH + 2; y++) {
			board[x][y] = (y == 0 || y == BH + 1 || x == 0 || x == BW + 1) ? WALL : EMPTY;
		}
	}

	DrawScreen();
	nFrame = 20;

	for (; 1;) {
		brick = random(sizeof(Shape) / sizeof(Shape[0]));
		nx = BW / 2;
		ny = 3;
		rot = 0;
		PrintBrick(1);

		if (GetAround(nx, ny, brick, rot) != EMPTY) break;
		nStay = nFrame;
		for (; 2;) {
			if (--nStay == 0) {
				nStay = nFrame;
				if (MoveDown()) break;
			}
			if (ProcessKey()) break;
			delay(1000 / 20);
		}
	}
	clrscr();
	gotoxy(30, 12); puts("G A M E  O V E R");
	setcursortype(NORMALCURSOR);
}



void DrawScreen()
{
	int x, y;
	for (x = 0; x<BW + 2; x++) {
		for (y = 0; y<BH + 2; y++) {
			gotoxy(BX + x * 2, BY + y);
			puts(arTile[board[x][y]]);
		}
	}
	gotoxy(50, 3); puts("Tetris Ver 1.0");
	gotoxy(50, 5); puts("좌우:이동, 위:회전, 아래:내림");
	gotoxy(50, 6); puts("공백:전부 내림");
}

void DrawBoard()
{
	int x, y;
	for (x = 1; x<BW + 1; x++) {
		for (y = 1; y<BH + 1; y++) {
			gotoxy(BX + x * 2, BY + y);
			puts(arTile[board[x][y]]);
		}
	}
}



bool ProcessKey()
{
	int ch, trot;
	if (kbhit()) {
		ch = getch();
		if (ch == 0xE0 || ch == 0) {
			ch = getch();
			switch (ch) {
			case LEFT:
				if (GetAround(nx - 1, ny, brick, rot) == EMPTY) {
					PrintBrick(0);
					nx--;
					PrintBrick(1);
				}
				break;
			case RIGHT:
				if (GetAround(nx + 1, ny, brick, rot) == EMPTY) {
					PrintBrick(0);
					nx++;
					PrintBrick(1);
				}
				break;
			case UP:
				trot = (rot == 3 ? 0 : rot + 1);
				if (GetAround(nx, ny, brick, trot) == EMPTY) {
					PrintBrick(0);
					rot = trot;
					PrintBrick(1);
				}
				break;
			case DOWN:
				if (MoveDown()) {
					return 1;
				}
				break;
			}
		}
		else {

			switch (ch) {
			case ' ':
				while (MoveDown() == 0) { ; }
				return 1;
			}
		}
	}
	return 0;
}



void PrintBrick(bool Show)
{
	int i;
	for (i = 0; i<4; i++) {
		gotoxy(BX + (Shape[brick][rot][i].x + nx) * 2, BY + Shape[brick][rot][i].y + ny);
		puts(arTile[Show ? BRICK : EMPTY]);
	}
}



int GetAround(int x, int y, int b, int r)
{
	int i, k = EMPTY;
	for (i = 0; i<4; i++) {
		k = max(k, board[x + Shape[b][r][i].x][y + Shape[b][r][i].y]);
	}
	return k;
}

bool MoveDown()
{
	if (GetAround(nx, ny + 1, brick, rot) != EMPTY) {
		TestFull();
		return 1;
	}
	PrintBrick(0);
	ny++;
	PrintBrick(1);
	return 0;
}



void TestFull()
{
	int i, x, y, ty;
	for (i = 0; i<4; i++) {
		board[nx + Shape[brick][rot][i].x][ny + Shape[brick][rot][i].y] = BRICK;
	}

	for (y = 1; y<BH + 1; y++) {
		for (x = 1; x<BW + 1; x++) {
			if (board[x][y] != BRICK) break;
		}

		if (x == BW + 1) {
			for (ty = y; ty>1; ty--) {
				for (x = 1; x<BW + 1; x++) {
					board[x][ty] = board[x][ty - 1];
				}
			}
			DrawBoard();
			delay(200);
		}
	}
}