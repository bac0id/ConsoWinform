#pragma once
#ifndef __COMPONENT_H
#define __COMPONENT_H
#include <typeinfo>
#include "Form.h"
#include "Text.h"
#include "SplitLine.h"
#include "Rect.h"
class Component
{
public:
	//λ����Ϣ
	Rect Transform;
	//�����λ��
	Component* Parent;
	//��ʾ���
	virtual void Draw() = 0;
private:
	static const char* ComponentOrderTable[];
};
#endif // !__COMPONENT_H