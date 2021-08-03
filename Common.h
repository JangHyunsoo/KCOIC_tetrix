#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <conio.h>
#include <Windows.h>

using namespace std;

#include "Type.h"
#include "Mecro.h"

inline void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}