#include"base.h"
#include"math.h"
#pragma once
#define PI 3.14159265358979323846

class arrow:public base
{
protected:
	int x3,x4,y3,y4;
	double angle,radius,alength;
	CString name;
	CString starttxt;
	CString endtxt;
	base *start;//线的起始类
	base *endl;//线的终点类
public:
	arrow(int tx1,int ty1,int tx2,int ty2);
	int onpressLB(int x,int y);
	void onmove(int cx,int cy);
	void ondraw(CDC *pDC);
	int DblClk(CPoint point);
	void setName(CString str);
	void setV(CString str);
	void setF(CString str);
	void setend(base* b);
	void setstart(base* b);
	base* getend();
	base* getstart();
	void addline(base* b);
	void deleteline(base* b);
	//list<base*> getlines();
};