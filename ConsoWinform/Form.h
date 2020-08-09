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
	Form(int x, int y, int startX, int startY);
	Form(int x, int y, int startX, int startY, Text* texts, int textCnt);
	Form(Rect* transform);
	Form(Rect* transform, Text* texts, int textCnt);

	//�ı�
	Text* Texts;
	//�ı�����
	int TextCnt;
	//��ʾ����
	void Draw();
	void Draw(bool fill);

};
#endif // !__FORM_H