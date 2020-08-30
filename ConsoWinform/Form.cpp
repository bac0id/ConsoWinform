#include <string>

#include "Display.h"
#include "Form.h"
using namespace std;

/// <summary>
/// ������
/// </summary>
Form::Form() {
	Rect r{ 0, 0, 0, 0 };
	new (this)Form(r, nullptr, nullptr, 0);
}
/// <summary>
/// ������
/// </summary>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="locX"></param>
/// <param name="locY"></param>
Form::Form(int sizeX, int sizeY, int locX, int locY) {
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, nullptr, nullptr, 0);
}
/// <summary>
/// ������
/// </summary>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="locX"></param>
/// <param name="locY"></param>
/// <param name="texts">Form�ڵ��ı�</param>
/// <param name="textCnt">Form�ڵ��ı�����</param>
Form::Form(int sizeX, int sizeY, int locX, int locY, Text* texts, int textCnt) {
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, nullptr, texts, textCnt);
}
/// <summary>
/// ������
/// </summary>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="locX"></param>
/// <param name="locY"></param>
/// <param name="parent">���ؼ�</param>
Form::Form(int sizeX, int sizeY, int locX, int locY, Control* parent) {
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, parent, nullptr, 0);
}
/// <summary>
/// ������
/// </summary>
/// <param name="sizeX"></param>
/// <param name="sizeY"></param>
/// <param name="locX"></param>
/// <param name="locY"></param>
/// <param name="parent">���ؼ�</param>
/// <param name="texts">Form�ڵ��ı�</param>
/// <param name="textCnt">Form�ڵ��ı�����</param>
Form::Form(int sizeX, int sizeY, int locX, int locY, Control* parent, Text* texts, int textCnt) {
	Rect r{ sizeX, sizeY, locX, locY };
	new (this)Form(r, parent, texts, textCnt);
}
/// <summary>
/// ������
/// </summary>
/// <param name="transform">λ����Ϣ</param>
Form::Form(Rect& transform) {
	new (this)Form(transform, nullptr, nullptr, 0);
}
/// <summary>
/// ������
/// </summary>
/// <param name="transform">λ����Ϣ</param>
/// <param name="texts">Form�ڵ��ı�</param>
/// <param name="textCnt">Form�ڵ��ı�����</param>
Form::Form(Rect& transform, Text* texts, int textCnt) {
	new (this)Form(transform, nullptr, texts, textCnt);
}
Form::Form(Rect& transform, Control* parent) {
	new (this)Form(transform, parent, nullptr, 0);
}
Form::Form(Rect& transform, Control* parent, Text* texts, int textCnt) {
	this->Transform = transform;
	this->Parent = parent;
	this->Texts = texts;
	for (int i = 0; i < textCnt; ++i) {
		(texts + i)->Parent = this;
	}
	this->TextCnt = textCnt;
}
/// <summary>
/// ��ʾ����
/// </summary>
void Form::Draw() {
	Draw(true);
}
/// <summary>
/// ��ʾ����
/// </summary>
/// <param name="fill">�Ƿ�����ڲ�</param>
void Form::Draw(bool fill) {
	int locX = this->Transform.locX;
	int locY = this->Transform.locY;
	Control* cur = this->Parent;
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
	} else {
		Display::DrawRect(&this->Transform, fill);
	}
	for (int i = 0; i < this->TextCnt; ++i) {
		(Texts + i)->Draw();
	}
}