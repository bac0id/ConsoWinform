#pragma once
#ifndef __COMPONENT_H
#define __COMPONENT_H
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
};
#endif // !__COMPONENT_H