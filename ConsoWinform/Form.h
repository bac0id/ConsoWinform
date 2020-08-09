#pragma once
#ifndef __FORM_H
#define __FORM_H
#include <string>
#include <vector>
#include "Rect.h"
#include "Component.h"
#include "Text.h"
#include "SplitLine.h"
//������
class Form : public Component
{
public:
	//������
	Form();
	Form(int sizeX, int sizeY, int locX, int locY);
	Form(int sizeX, int sizeY, int locX, int locY, Text* texts, int textCnt);
	Form(int sizeX, int sizeY, int locX, int locY, Component* parent);
	Form(int sizeX, int sizeY, int locX, int locY, Component* parent, Text* texts, int textCnt);
	Form(Rect* transform);
	Form(Rect* transform, Text* texts, int textCnt);
	Form(Rect* transform, Component* parent);
	Form(Rect* transform, Component* parent, Text* texts, int textCnt);

	//�ı�
	Text* Texts;
	//�ı�����
	int TextCnt;
	//��ʾ����
	void Draw();
	void Draw(bool fill);

};
#endif // !__FORM_H