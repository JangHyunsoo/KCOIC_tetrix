#include "Tetrix.h"
#include "Block.h"

CTetrix::CTetrix()
{
}


CTetrix::~CTetrix()
{
	SAFE_DELETE(m_pBlock);
}

void CTetrix::init()
{
	//table �ʱ�ȭ
	for (int i = 0; i < 22; i++) {//Y��ǥ
		for (int j = 0; j < 12; j++) {//X��ǥ
			if (i == 0 || i == 21 || j == 0 || j == 11) table[i][j] = 1;
			else table[i][j] = 0;
		}
	}
	m_pBlock = new CBlock();
	//Block �ʱ�ȭ
	m_pBlock->SetType(0);
	m_pBlock->SetRotation(0);
	m_pBlock->SetX(3);
	m_pBlock->SetY(0);
	
}

void CTetrix::Run()
{
	CursorView(0); //Ŀ���� �������� �ʰ�

	char keytemp;
	init();
	makeNewque();
	Print();
	
	m_pBlock->SetType(m_queBlock.front());
	while (1) {
		if (_kbhit()) {
			keytemp = _getch();
			if (keytemp = EXT_KEY) { //����Ű �Է�
				keytemp = _getch();
				if (keytemp != KEY_UP) {
					checkAround(m_pBlock->GetX(), m_pBlock->GetY(), m_pBlock->GetType(), m_pBlock->GetRotation());
					m_pBlock->Input(keytemp);
				}
				else m_pBlock->Input(keytemp);
			}
			if (keytemp = KEY_HOLD) { //Ȧ��Ű �Է�

			}
		}
	}
}

void CTetrix::Print()
{
	int x = 0;
	int y = 0;
	for (x=0; x < TW + 2; x++) {		
		for (y=0; y < TH + 2; y++) {
			gotoxy(TX + x * 2, TY + y);
			if (table[y][x]) puts("��");
			//else puts("��"); �� �������� �δ°� �����
			//block�� ���� printBlock �ϴ� ���� ������
			//gotoxy(TX + Block.GetX() * 2, TY + Block.GetY());
			
		}
	}
	//�ӽ�
	gotoxy(42, 3); puts("Tetris Ver 1.0");
	gotoxy(42, 5); puts("�¿�:�̵�, ��:ȸ��, �Ʒ�:����");
	gotoxy(42, 6); puts("����:���� ����");
	gotoxy(42, 21); //����Ϸ��� ~~
	//
}

bool CTetrix::checkAround(int x, int y, int bt, int r)
{
	int i=0,j=0; 
	for (i = 0; i < 4; i++) {
		for (; j < 4; j++) {
		if (table[x + m_pBlock->block[bt][r][j][i]][y + m_pBlock->block[bt][r][j][i]])
			return true;
		}
	}
	return false;
}

void CTetrix::makeNewque()
{
	while (!m_queBlock.empty())
		m_queBlock.pop();
	while (!m_quePreview.empty())
		m_quePreview.pop();
	//�ΰ��� ť �ʱ�ȭ
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
		m_queBlock.push(temp[i]);
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
