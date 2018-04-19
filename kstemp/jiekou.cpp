#include"stdafx.h"
#include"jiekou.h"
#define LINE 16
jiekou::jiekou(int l,int u,int r,int d,int p):base(l,u,r,d)
{
	type=1;

	part=p;
	name=_T("未命名");
}

int jiekou::onpressLB(int x,int y)
{
	if(x>x1&&x<x2&&y>y1&&y<part)  //移动  state==1 move
	{
		choose=1;
		state=1;
		return 1;
	}
	else if(ctrl==0)
	{
		choose=0;
		return 0;
	}
	else
	{
		return 0;
	}
}

void jiekou::onmove(int cx, int cy)
{
	if(state==1)
	{
		x1+=cx;
		x2+=cx;
		y1+=cy;
		y2+=cy;
		part+=cy;
	}
}

void jiekou::ondraw(CDC *pDC)
{
	if(choose==0)                              //没选中画实线
	{
		pDC->Rectangle(x1,y1,x2,y2);
		pDC->Rectangle(x1,y1,x2,part);
	}
	else if(choose==1)							//选中画虚线
	{
		CPen *oldpen;
		CPen pen(PS_DOT,1,RGB(0,0,0));
		oldpen=pDC->SelectObject(&pen);

		pDC->Rectangle(x1,y1,x2,y2);
		pDC->Rectangle(x1,y1,x2,part);

		pDC->SelectObject(oldpen);
	}
	pDC->TextOutW(x1+(x2-x1)/2-25,y1+5,name);//文字
	list<CString>::iterator it;	
	int vy=part+5;
	for(it=flist.begin();it!=flist.end();it++)
	{
		pDC->TextOutW(x1+8,vy,it->GetBuffer(0));
		vy=vy+LINE;
		if(vy>y2)
			y2=y2+LINE;
	}
}

int jiekou::DblClk(CPoint point)
{
	int text=0;
	if(point.x>x1&&point.x<x2&&point.y>y1&&point.y<y2) //双击
	{
		if(point.y<part)
			text=1;
		else
			text=3;
	}
	dbClk=text;
	return text;
}
void jiekou::setName(CString str)
{
	name=str;		
}
void jiekou::setV(CString str)
{
	vlist.push_back(str);		
}
void jiekou::setF(CString str)
{
	flist.push_back(str);
}

void jiekou::addline(base *b)
{
	lines.push_back(b);
}


void jiekou::deleteline(base* b)
{
	list< base*>::iterator itList;
	for( itList = lines.begin(); itList != lines.end(); )
	{
		if( ( *itList) == b)
		{
			itList = lines.erase( itList);
		}
		else
		{
			itList++;
		}
	}
}


void jiekou::setend(base* b)
{
}

void jiekou::setstart(base* b)
{
}

base* jiekou::getend()
{
	return NULL;
}
base* jiekou::getstart()
{
	return NULL;
}
