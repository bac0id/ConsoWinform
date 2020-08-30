#pragma once
#ifndef __COMPONENT_H
#define __COMPONENT_H
#include <typeinfo>
#include "Form.h"
#include "Text.h"
#include "SplitLine.h"
#include "Rect.h"
class Control
{
public:
	//λ����Ϣ
	Rect Transform;
	//�����λ��
	Control* Parent;
	//��ʾ���
	virtual void Draw() = 0;
private:
	static const char* ControlsOrderTable[];
};
#endif // !__COMPONENT_H