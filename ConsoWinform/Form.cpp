#include <string>

#include "Display.h"
#include "Form.h"
using namespace std;
/*
������Ĺ��캯��
������	��
���أ�	Ĭ�ϵĴ���ʵ����
*/
Form::Form()
{
	Rect r{ 0, 0, 0, 0 };
	new (this)Form(r, nullptr, nullptr, 0);
}
/*
������Ĺ��캯��
������	x: �߶�
		y: ���
		startX: ���X����
		startY: ���Y����
���أ�	����ʵ����
*/
Form::Form(int sizeX, int sizeY, int locX, int locY)
{
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, nullptr, nullptr, 0);
}
/*
������Ĺ��캯��
������	x: �߶�
		y: ���
		startX: ���X����
		startY: ���Y����
		texts: �����ڵ��ı�
		textCnt: �����ڵ��ı���
���أ�	����ʵ����
*/
Form::Form(int sizeX, int sizeY, int locX, int locY, Text* texts, int textCnt)
{
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, nullptr, texts, textCnt);
}
Form::Form(int sizeX, int sizeY, int locX, int locY, Component* parent)
{
	//this->Transform = Rect{ sizeX, sizeY, locX, locY };
	//this->Parent = parent;
	//this->Texts = nullptr;
	//this->TextCnt = 0;
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, parent, nullptr, 0);
}
Form::Form(int sizeX, int sizeY, int locX, int locY, Component* parent, Text* texts, int textCnt)
{
	//this->Transform = Rect{ sizeX, sizeY, locX, locY };
	//this->Parent = parent;
	//this->Texts = texts;
	//for (int i = 0; i < textCnt; ++i) {
	//	(texts + i)->Parent = this;
	//}
	//this->TextCnt = textCnt;
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, parent, texts, textCnt);
}
/*
������Ĺ��캯��
������	transform: λ����Ϣ
���أ�	����ʵ����
*/
Form::Form(Rect& transform)
{
	new (this)Form(transform, nullptr, nullptr, 0);
}
/*
������Ĺ��캯��
������	transform: λ����Ϣ
		texts: �����ڵ��ı�
		textCnt: �����ڵ��ı���
���أ�	����ʵ����
*/
Form::Form(Rect& transform, Text* texts, int textCnt)
{
	new (this)Form(transform, nullptr, texts, textCnt);
}
Form::Form(Rect& transform, Component* parent)
{

	new (this)Form(transform, parent, nullptr, 0);
}
Form::Form(Rect& transform, Component* parent, Text* texts, int textCnt)
{
	this->Transform = transform;
	this->Parent = parent;
	this->Texts = texts;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->TextCnt = textCnt;
}
/*
��ʾ����
������	��
���أ�	��
*/
void Form::Draw()
{
	Draw(true);
}
/*
��ʾ����
������	fill: �Ƿ�����ڲ�
���أ�	��
*/
void Form::Draw(bool fill)
{
	int locX = this->Transform.locX;
	int locY = this->Transform.locY;
	Component* cur = this->Parent;
	if (cur != nullptr) {
		do {
			locX += cur->Transform.locX;
			locY += cur->Transform.locY;
			cur = cur->Parent;
		} while (cur != nullptr);
		Display::DrawRect(this->Transform.sizeX,
			this->Transform.sizeY,
			locX,
			locY,
			fill);
	}
	else
	{
		Display::DrawRect(&this->Transform, fill);
	}
	for (int i = 0; i < this->TextCnt; ++i) {
		(Texts + i)->Draw();
	}
}