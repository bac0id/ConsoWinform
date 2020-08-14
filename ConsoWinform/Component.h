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
	//位置信息
	Rect Transform;
	//父组件位置
	Component* Parent;
	//显示组件
	virtual void Draw() = 0;
private:
	static const char* ComponentOrderTable[];
};
#endif // !__COMPONENT_H