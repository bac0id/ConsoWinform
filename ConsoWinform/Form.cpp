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
	Rect r = Rect{ 0, 0, 0, 0 };
	this->Transform = r;
	this->Texts = nullptr;
	this->TextCnt = 0;
}
/*
������Ĺ��캯��
������	x: �߶�
		y: ���
		startX: ���X����
		startY: ���Y����
���أ�	����ʵ����
*/
Form::Form(int x, int y, int startX, int startY)
{
	Rect r = Rect{ x, y, startX, startY };
	this->Transform = r;
	this->Texts = nullptr;
	this->TextCnt = 0;
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
	Rect r = Rect{ sizeX, sizeY, locX, locY };
	this->Transform = r;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->Texts = texts;
	this->TextCnt = textCnt;
}
/*
������Ĺ��캯��
������	transform: λ����Ϣ
���أ�	����ʵ����
*/
Form::Form(Rect* transform)
{
	this->Transform = *transform;
	this->Texts = nullptr;
	this->TextCnt = 0;
}
/*
������Ĺ��캯��
������	transform: λ����Ϣ
		texts: �����ڵ��ı�
		textCnt: �����ڵ��ı���
���أ�	����ʵ����
*/
Form::Form(Rect* transform, Text* texts, int textCnt)
{
	this->Transform = *transform;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->Texts = texts;
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
	Display::DrawRect(&this->Transform, fill);
	for (int i = 0; i < this->TextCnt; ++i) {
		(Texts + i)->Draw();
	}
}