#pragma once
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
#define EMPTY			0
#define EXT_KEY			0xffffffe0 //Ȯ��Ű �νİ�
#define KEY_HOLD		0x5A	//Z

#define TX 5 //���ȿ� ���� ���� ����ġ
#define TY 1 //���ȿ� ���� ���� ����ġ
#define TW 10 //���� ����
#define TH 20 //���� ����

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }