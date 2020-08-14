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
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, 0, 0 };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = nullptr;
	new (this)Text(0, 0, nullptr, "", (int)ConsoleFGColor::White);
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
���أ�	Textʵ��
*/
Text::Text(int x, int y)
{
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = nullptr;
	new (this)Text(x,y, nullptr, "", (int)ConsoleFGColor::White);
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
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = color;
	//this->Parent = nullptr;
	//new (this)Text(x, y, nullptr, "", color);
	new (this)Text(x, y, nullptr, "", color);
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
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = nullptr;
	new (this)Text(x, y, nullptr, text, (int)ConsoleFGColor::White);
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
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT,x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = nullptr;
	new (this)Text(x, y, nullptr, text, (int)ConsoleFGColor::White);
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
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = color;
	//this->Parent = nullptr;
	new (this)Text(x, y, nullptr, text, color);
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
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = color;
	//this->Parent = nullptr;
	new (this)Text(x, y, nullptr, text, color);
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
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = parent;
	new (this)Text(x, y, parent, "", (int)ConsoleFGColor::White);
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		parent: �������λ����Ϣ
		color: �ı���ɫ
���أ�	Textʵ��
*/
Text::Text(int x, int y, Component* parent, int color)
{
	//this->Str = "";
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = color;
	//this->Parent = parent;
	new (this)Text(x, y, parent, "", color);
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
		parent: �������λ����Ϣ
���أ�	Textʵ��
*/
Text::Text(int x, int y, Component* parent, const char* text)
{
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = parent;
	new (this)Text(x, y, parent, text, (int)ConsoleFGColor::White);
}
/*
�ı��Ĺ��캯��
������	x: ���X����
		y: ���Y����
		text: �ı��ڵ��ַ���
		parent: �������λ����Ϣ
���أ�	Textʵ��
*/
Text::Text(int x, int y, Component* parent, string text)
{
	//this->Str = text;
	//this->Transform = Rect{ 0, TEXT_WIDTH_DEFAULT, x, y };
	//this->Color = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
	//this->Parent = parent;
	new (this)Text(x, y, parent, text, (int)ConsoleFGColor::White);
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
Text::Text(int x, int y, Component* parent, const char* text, int color)
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
Text::Text(int x, int y, Component* parent, string text, int color)
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
	Clear();
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

void Text::Input()
{
	this->Focus();
	string buf;
	// you can replace cin with another INPUT procedure
	cin >> buf;
	SetStr(buf);
}

/*
����ı�
������	��
���أ�	��
*/
void Text::Clear()
{
	string s(this->Str.size(), ' ');
	this->Str = s;
	Draw();
	this->Str = "";
}
/*
�����ı�
������	��
���أ�	��
*/
void Text::Draw()
{
	//Display::DrawLabel(this);
	int x = this->Transform.locX;
	int y = this->Transform.locY;
	Component* cur = this->Parent;
	while (cur != nullptr) {
		x +=cur->Transform.locX;
		y +=cur->Transform.locY << 1;
		cur = cur->Parent;
	}
	Display::SetColor(this->GetColor());
	Display::DrawString(x, y, this->GetStr());
	Display::ResetColor();
}