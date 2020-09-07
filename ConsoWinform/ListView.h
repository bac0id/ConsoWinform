#pragma once
#ifndef __LISTVIEW_H
#define __LISTVIEW_H
#include "Display.h"
#include "Control.h"
using namespace std;

class ListView : public Control
{
public:
	ListView();
	ListView(Rect& transform);

	void DrawColumns();
	void DrawPage(int pageIndex);
	void Select(int index);
	int GetColumnCount();
	int GetItemCount();
	int GetCurrentItemIndex();
	int GetLastItemIndex();
	int GetPageCount();
	int GetCurrentPageIndex();
	int GetItemCountPerPage();
private:
	//������
	int ColumnCount;
	//������
	int ItemCount;
	//��ǰѡ��������
	int CurrentItemIndex;
	//��һ��ѡ��������
	int LastItemIndex;

	//ҳ������
	int PageCount;
	//��ǰҳ������
	int CurrentPageIndex;
	
	//ÿҳ����
	int ItemCountPerPage;

	int PageInterval(int index);
};
#endif // !__LISTVIEW_H
class 