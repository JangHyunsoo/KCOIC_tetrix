#pragma once
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
#define EMPTY			0
#define EXT_KEY			0xffffffe0 //확장키 인식값
#define KEY_HOLD		0x5A	//Z

#define TX 5 //벽안에 들어가기 위한 보정치
#define TY 1 //벽안에 들어가기 위한 보정치
#define TW 10 //가로 길이
#define TH 20 //세로 길이

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }