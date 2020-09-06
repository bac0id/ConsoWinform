#pragma once
#ifndef __DISPLAY_H
#define __DISPLAY_H
#include <string>
#include <Windows.h>
#include "ConsoleColor.h"
#include "Rect.h"
#include "Form.h"
#include "Text.h"
#include "SplitLine.h"
using namespace std;
class Text;
class SplitLine;
//��ʾ������
static class Display
{
public:
	//���ù������
	static void SetCursorPos(int x, int y);
	//��ù������
	static COORD GetCursorPos();
	//���ù��ɼ���
	static void SetCursorVisibility(bool visible);
	//���ô��ڳߴ�
	static void SetConsoleSize(int x, int y);
	//����������ɫ
	static void SetColor(int color);
	//����������ɫ
	static void ResetColor();
	//����
	static void Clear();
	//��ԭ�����ָ������
	static void DrawRect(int x, int y);
	//��ָ���������ָ������
	static void DrawRect(int x, int y, int offsetX, int offsetY);
	//��ָ���������ָ������
	static void DrawRect(int x, int y, int offsetX, int offsetY, bool fill);
	//���ƾ���
	static void DrawRect(Rect* rect);
	//���ƾ���
	static void DrawRect(Rect* rect, bool fill);
	//��ָ�������ӡ�ַ���
	static void DrawString(int x, int y, char* str);
	//��ָ�������ӡ�ַ���
	static void DrawString(int x, int y, string str);
	//��ָ�������ڵ�ָ����������ӡ�ַ���
	static void DrawString(Rect* rect, int x, int y, char* str);
	//��ָ�������ڵ�ָ����������ӡ�ַ���
	static void DrawString(Rect* rect, int x, int y, string str);
	//�����ı�
	static void DrawLabel(Text* text);
	//��ָ�������ڵĻ����ı�
	static void DrawLabel(Rect* rect, Text* text);
	//���Ʒָ���
	static void DrawSplitLine(SplitLine* sp);
};
#endif // !__DISPLAY_H
