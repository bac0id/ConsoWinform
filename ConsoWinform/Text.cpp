#include <string>

#include "Text.h"
#include "Display.h"
using namespace std;
/*
�ı��Ĺ��캯��
������	��
���أ�	Textʵ��
*/
Text::Text()
{
	this->Str = "";
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, 0, 0 };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = nullptr;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
���أ�	Textʵ��
*/
Text::Text(int x, int y)
{
	this->Str = "";
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = nullptr;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		parent: �������λ����Ϣ
���أ�	Textʵ��
*/
Text::Text(int x, int y, Component* parent)
{
	this->Str = "";
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = parent;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
���أ�	Textʵ��
*/
Text::Text(int x, int y, const char* text)
{
	//this->Str = string(text);
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = nullptr;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
���أ�	Textʵ��
*/
Text::Text(int x, int y, string text)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT,x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = nullptr;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
		parent: �������λ����Ϣ
���أ�	Textʵ��
*/
Text::Text(int x, int y, const char* text, Component* parent)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = parent;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
		parent: �������λ����Ϣ
���أ�	Textʵ��
*/
Text::Text(int x, int y, string text, Component* parent)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	this->Parent = parent;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		color: �ı���ɫ
���أ�	Textʵ��
*/
Text::Text(int x, int y, int color)
{
	this->Str = "";
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = nullptr;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
		color: �ı���ɫ
���أ�	Textʵ��
*/
Text::Text(int x, int y, const char* text, int color)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = nullptr;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
		color: �ı���ɫ
���أ�	Textʵ��
*/
Text::Text(int x, int y, string text, int color)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = nullptr;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
		color: �ı���ɫ
		parent: �������λ����Ϣ
���أ�	Textʵ��
*/
Text::Text(int x, int y, const char* text, int color, Component* parent)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = parent;
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
		color: �ı���ɫ
		parent: �������λ����Ϣ
���أ�	Textʵ��
*/
Text::Text(int x, int y, string text, int color, Component* parent)
{
	this->Str = text;
	this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	this->Color = color;
	this->Parent = parent;
}
/*
�õ��ı��ڵ��ַ���
������	��
���أ�	�ı��ڵ��ַ���
*/
string Text::GetStr()
{
	return this->Str;
}
/*
�����ı��ڵ��ַ���
������	str: �ַ���
���أ�	��
*/
void Text::SetStr(string str)
{
	this->Str = str;
	Draw();
}
/*
�õ��ı���ɫ
������	��
���أ�	�ı���ɫ
*/
int Text::GetColor()
{
	return this->Color;
}
/*
�����ı���ɫ
������	color: ��ɫ
���أ�	��
*/
void Text::SetColor(int color)
{
	this->Color = color;
	Draw();
}

void Text::Focus()
{
	if (!this->Parent) {
		Display::SetCursorPos(this->Transform.locX, this->Transform.locY);
	}
	else {
		Display::SetCursorPos(this->Transform.locX + this->Parent->Transform.locX,
			this->Transform.locY + (this->Parent->Transform.locY << 1));
	}
}

/*
����ı�
������	��
���أ�	��
*/
void Text::Clear()
{
	//�˴����Ͻ���
	//Ӧ����transform.Y�ĳ���������ı�
	SetStr("");
}
/*
�����ı�
������	��
���أ�	��
*/
void Text::Draw()
{
	Display::DrawLabel(this);
}