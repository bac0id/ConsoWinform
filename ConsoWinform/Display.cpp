#include <iostream>
#include <string>
#include <Windows.h>

#include "Display.h"
#include "Control.h"
using namespace std;
/// <summary>
/// ���ù������
/// </summary>
/// <param name="x">��</param>
/// <param name="y">��</param>
void Display::SetCursorPos(int x, int y) {
	//x��y����һ�£�������
	COORD coord = { y,x };
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}
/*
�õ��������
������	��
���أ�	��ʾ��������COORD�͡�
*/
COORD Display::GetCursorPos() {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO pBuffer;
	GetConsoleScreenBufferInfo(hout, &pBuffer);
	return pBuffer.dwCursorPosition;
}
/*
���ù��ɼ���
������	visible: ����Ƿ�ɼ�
���أ�	��
*/
void Display::SetCursorVisibility(bool visible) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(hout, &CursorInfo);
	CursorInfo.bVisible = visible;
	SetConsoleCursorInfo(hout, &CursorInfo);
}
/*
���ô��ڳߴ�
������	x: ��
		y: ��
���أ�	��
*/
void Display::SetConsoleSize(int x, int y) {
	////x��y����һ�£�������
	//SMALL_RECT size = { y,x };
	//HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleWindowInfo(hout, true, &size);
	char szStrCmd[ 32 ];
	sprintf_s(szStrCmd, "mode con lines=%d cols=%d", x, y);
	system(szStrCmd);
}
/*
����������ɫ
������	color: ��ɫ
���أ�	��
*/
void Display::SetColor(int color) {
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	//auto a = FOREGROUND_RED
	SetConsoleTextAttribute(hout, color);
}
void Display::ResetColor() {
	SetColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
}
/*
����
������	��
���أ�	��
*/
void Display::Clear() {
	system("cls");
}
/*
��ԭ�����ָ������
������	x: �߶�
		y: ���
���أ�	��
*/
void Display::DrawRect(int x, int y) {
	DrawRect(x, y, 0, 0);
}
/*
��ָ���������ָ������
������	x: �߶�
		y: ���
		offsetX: ��ʼ��X����
		offsetY: ��ʼ��Y����
���أ�	��
*/
void Display::DrawRect(int x, int y, int offsetX, int offsetY) {
	DrawRect(x, y, offsetX, offsetY, false);
}
/*
��ָ���������ָ������
������	x: �߶�
		y: ���
		offsetX: ��ʼ��X����
		offsetY: ��ʼ��Y����
		fill: �Ƿ�����ڲ�
���أ�	��
*/
void Display::DrawRect(int x, int y, int offsetX, int offsetY, bool fill) {
	int i;
	//1�����ַ�ռ2��
	y <<= 1, offsetY <<= 1;
	//�ϱ�
	SetCursorPos(offsetX, offsetY);
	cout << "�X";
	for (i = 0; i <= y; cout << "�T", ++i);
	cout << "�[";
	//�м�
	if (fill) {
		for (i = 1; i <= x; ++i) {
			SetCursorPos(offsetX + i, offsetY);
			cout << "�U";
			for (int j = 0; j <= y; ++j) {
				cout << ' ';
			}
			cout << "�U";
		}
	} else {
		for (i = 1; i <= x; ++i) {
			SetCursorPos(offsetX + i, offsetY);
			cout << "�U";
			SetCursorPos(offsetX + i, offsetY + y + 2);
			cout << "�U";
		}
	}
	//�±�
	SetCursorPos(offsetX + x + 1, offsetY);
	cout << "�^";
	for (i = 0; i <= y; cout << "�T", ++i);
	cout << "�a";
}
/*
����ִ�о���
������	rect: ָ��1������
���أ�	��
*/
void Display::DrawRect(Rect* rect) {
	DrawRect(rect->sizeX, rect->sizeY, rect->locX, rect->locY);
}
/*
����ִ�о���
������	rect: ָ��1������
		fill: �Ƿ�����ڲ�
���أ�	��
*/
void Display::DrawRect(Rect* rect, bool fill) {
	DrawRect(rect->sizeX, rect->sizeY, rect->locX, rect->locY, fill);
}
/*
��ָ�������ӡ�ַ���
������	x: �߶�
		y: ���
		str: �ַ���
���أ�	��
*/
void Display::DrawString(int x, int y, char* str) {
	SetCursorPos(x, y);
	cout << str;
}
/*
��ָ�������ӡ�ַ���
������	x: �߶�
		y: ���
		str: �ַ���
���أ�	��
*/
void Display::DrawString(int x, int y, string str) {
	SetCursorPos(x, y);
	cout << str;
}
/*
��ָ�������ڵ�ָ����������ӡ�ַ���
������	rect*: ����
		x: �߶�
		y: ���
		str: �ַ���
���أ�	��
*/
void Display::DrawString(Rect* rect, int x, int y, char* str) {
	DrawString(rect->locX + x, (rect->locY << 1) + y, str);
	//SetCursor(rect->startX + x, (rect->startY << 1) + y);
	//cout << str;
}
/*
��ָ�������ڵ�ָ����������ӡ�ַ���
������	rect*: ����
		x: �߶�
		y: ���
		str: �ַ���
���أ�	��
*/
void Display::DrawString(Rect* rect, int x, int y, string str) {
	DrawString(rect->locX + x, (rect->locY << 1) + y, str);
	//SetCursor(rect->startX + x, (rect->startY<<1) + y);
	//cout << str;
}
/*
��ӡ�ı�
������	rect: ����
		label: �ı�
���أ�	��
*/
void Display::DrawLabel(Text* label) {
	//if (!label->Parent) {
	//	SetColor(label->GetColor());
	//	DrawString(label->Transform.locX, label->Transform.locY, label->GetStr());
	//	ResetColor();
	//	return;
	//}
	//DrawLabel(&label->Parent->Transform, label);

	int x = label->Transform.locX;
	int y = label->Transform.locY;
	if (label->Parent!=nullptr) {
		x += label->Parent->Transform.locX;
		y += label->Parent->Transform.locY << 1;
	}
	SetColor(label->GetColor());
	DrawString(x, y, label->GetStr());
	ResetColor();
}
/*
��ָ�������ڵĴ�ӡ�ı�
������	rect: ����
		label: �ı�
���أ�	��
*/
void Display::DrawLabel(Rect* rect, Text* label) {
	SetColor(label->GetColor());
	DrawString(rect->locX + label->Transform.locX,
		(rect->locY << 1) + label->Transform.locY, label->GetStr());
	ResetColor();
}
///*
//���Ʒָ���
//������	rect: ����
//		isHerizon: �Ƿ���ˮƽ��
//		start: �������
//		length: ����
//���أ�	��
//*/
//void Display::DrawSplitLine(Rect* rect, bool isHerizon, int start, int length)
//{
//	//ˮƽ��
//	if (isHerizon) {
//		DrawSplitLine(rect, true, start, 0, length);
//	}
//	else {
//		DrawSplitLine(rect, false, 0, start, length);
//	}
//}
///*
//���Ʒָ���
//������	isHerizon: �Ƿ���ˮƽ��
//		startX: ���X����
//		startY: ���Y����
//		length: ����
//���أ�	��
//*/
//void Display::DrawSplitLine(bool isHerizon, int startX, int startY, int length)
//{
//	SetCursorPos(startX, startY);
//	int i;
//	//ˮƽ��
//	if (isHerizon) {
//		cout << "�d";
//		for (i = 0; i <= length; cout << "�T", ++i);
//		cout << "�g";
//	}
//	//Ǧ����
//	else {
//		cout << "�j";
//		for (i = 0; i <= length; ++i) {
//			SetCursorPos(startX++, startY);
//			cout << "�U";
//		}
//		cout << "�m";
//	}
//}
///*
//���Ʒָ���
//������	rect: ����
//		isHerizon: �Ƿ���ˮƽ��
//		startX: ���X����
//		startY: ���Y����
//		length: ����
//���أ�	��
//*/
//void Display::DrawSplitLine(Rect* rect, bool isHerizon, int startX, int startY, int length)
//{
//	SetCursorPos(rect->locX + startX, (rect->locY << 1) + startY);
//	int i;
//	//ˮƽ��
//	if (isHerizon) {
//		cout << "�d";
//		for (i = 0; i <= length; cout << "�T", ++i);
//		cout << "�g";
//	}
//	//Ǧ����
//	else {
//		int x = rect->locX + startX;
//		int y = (rect->locY << 1) + startY;
//		cout << "�j";
//		for (i = 0; i < length; ++i) {
//			SetCursorPos(++x, y);
//			cout << "�U";
//		}
//		SetCursorPos(++x, y);
//		cout << "�m";
//	}
//}

void Display::DrawSplitLine(SplitLine* sp) {
	int x = sp->Transform.locX;
	int y = sp->Transform.locY;
	if (sp->Parent) {
		x += sp->Parent->Transform.locX;
		y += sp->Parent->Transform.locY << 1;
	}
	SetCursorPos(x, y);
	int i;
	int len = sp->GetLength();
	//ˮƽ��
	if (sp->IsHorizon()) {
		cout << "�d";
		for (i = 0; i <= len; cout << "�T", ++i);
		cout << "�g";
	}
	//Ǧ����
	else {
		cout << "�j";
		for (i = 0; i <= len; ++i) {
			SetCursorPos(++x, y);
			cout << "�U";
		}
		SetCursorPos(x, y);
		cout << "�m";
	}
}
