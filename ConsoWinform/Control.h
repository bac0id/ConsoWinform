#pragma once
#ifndef __CONTROL_H
#define __CONTROL_H
#include <typeinfo>
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
#endif // !__CONTROL_H
