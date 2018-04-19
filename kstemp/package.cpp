#include"stdafx.h"
#include"package.h"
#define LINE 16
package::package(int l,int u,int r,int d,int p1,int p2):base(l,u,r,d)
{
	type=1;
	this->p1=p1;
	this->p2=p2;
	//name=_T("未命名");
}

int package::onpressLB(int x,int y)
{
	if(x>x1&&x<p1&&y>y1&&y<p2)  //移动  state==1 move
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
}

void package::onmove(int cx, int cy)
{
	if(state==1)
	{
		x1+=cx;
		x2+=cx;
		y1+=cy;
		y2+=cy;
		p1+=cx;
		p2+=cy;
	}
}

void package::ondraw(CDC *pDC)
{
	if(choose==0)                              //没选中画实线
	{
		pDC->Rectangle(x1,y1,p1,p2);
		pDC->Rectangle(x1,p2,x2,y2);
	}
	else if(choose==1)							//选中画虚线
	{
		CPen *oldpen;
		CPen pen(PS_DOT,1,RGB(0,0,0));
		oldpen=pDC->SelectObject(&pen);

		pDC->Rectangle(x1,y1,p1,p2);
		pDC->Rectangle(x1,p2,x2,y2);

		pDC->SelectObject(oldpen);
	}
	pDC->TextOutW(x1+10,y1+5,name);

	
}

int package::DblClk(CPoint point)
{int text=0;
	if(point.x>x1&&point.x<x2&&point.y>y1&&point.y<y2) //双击
	{
		if(point.y<p2)
			text=1;
		//else if(point.y<p2)
			//text=2;
	}
	dbClk=text;
	return text;
}
void package::setName(CString str)
{
	name=str;		
}
void package::setV(CString str)
{
	//vlist.push_back(str);		
}
void package::setF(CString str)
{
	//flist.push_back(str);
}

void package::addline(base *b)
{
	lines.push_back(b);
}


void package::deleteline(base* b)
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


void package::setend(base* b)
{
}

void package::setstart(base* b)
{
}

base* package::getend()
{
	return NULL;
}
base* package::getstart()
{
	return NULL;
}
