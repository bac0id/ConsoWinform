#pragma once
#ifndef __Text_h
#define __Text_h
#include <string>
#include "Component.h"
#define TEXT_WIDTH_DEFAULT 16
using namespace std;
//�ı���
class Text : public Component
{
public:
	//������
	Text();
	Text(int x, int y);
	Text(int x, int y, int color);
	Text(int x, int y, const char* text);
	Text(int x, int y, string text);
	Text(int x, int y, const char* text, int color);
	Text(int x, int y, string text, int color);
	Text(int x, int y, Component* parent);
	Text(int x, int y, Component* parent, int color);
	Text(int x, int y, Component* parent, const char* text);
	Text(int x, int y, Component* parent, string text);
	Text(int x, int y, Component* parent, const char* text, int color);
	Text(int x, int y, Component* parent, string text, int color);
	//�õ��ı��ڵ��ַ���
	string GetStr();
	//�����ı��ڵ��ַ���
	void SetStr(string str);
	//�õ��ı���ɫ
	int GetColor();
	//�����ı���ɫ
	void SetColor(int color);
	//�۽���������ƶ����ı���
	void Focus();
	//���ı�������
	void Input();
	//����ı�
	void Clear();
	//�����ı�
	void Draw();
private:
	//�ı�
	string Str;
	//��ɫ
	int Color;
};
#endif // !__Text_h