#include"stdafx.h"
#include"zhushi.h"
#define LINE 16
zhushi::zhushi(int l,int u,int r,int d,int p1,int p2,int p3):base(l,u,r,d)
{
	type=1;
	this->p1=p1;
	this->p2=p2;
	this->p3=p3;
	//name=_T("未命名");
}

int zhushi::onpressLB(int x,int y)
{
	CRgn rgn;
	CPoint p[5];
	p[0].x=x1;p[0].y=y1;
	p[1].x=x1;p[1].y=y2;
	p[2].x=x2;p[2].y=y2;
	p[3].x=x2;p[3].y=p2;
	p[4].x=p1;p[4].y=y1;

	rgn.CreatePolygonRgn(p,5,ALTERNATE);
	if(PtInRegion(rgn,x,y))		//移动  state==1 move
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

void zhushi::onmove(int cx, int cy)
{
	if(state==1)
	{
		x1+=cx;
		x2+=cx;
		y1+=cy;
		y2+=cy;
		p1+=cx;
		p2+=cy;
		p3+=cx;
	}
}

void zhushi::ondraw(CDC *pDC)
{
	if(choose==0)                              //没选中画实线
	{
		CPoint p[5];
		p[0].x=x1;p[0].y=y1;
		p[1].x=x1;p[1].y=y2;
		p[2].x=x2;p[2].y=y2;
		p[3].x=x2;p[3].y=p2;
		p[4].x=p1;p[4].y=y1;
		pDC->Polygon(p,5);
		pDC->MoveTo(p1,y1);
		pDC->LineTo(p3,p2);
		pDC->LineTo(x2,p2);
	}
	else if(choose==1)							//选中画虚线
	{
		CPen *oldpen;
		CPen pen(PS_DOT,1,RGB(0,0,0));
		oldpen=pDC->SelectObject(&pen);

		CPoint p[5];
		p[0].x=x1;p[0].y=y1;
		p[1].x=x1;p[1].y=y2;
		p[2].x=x2;p[2].y=y2;
		p[3].x=x2;p[3].y=p2;
		p[4].x=p1;p[4].y=y1;
		pDC->Polygon(p,5);
		pDC->MoveTo(p1,y1);
		pDC->LineTo(p3,p2);
		pDC->LineTo(x2,p2);

		pDC->SelectObject(oldpen);
	}

	pDC->TextOutW(x1+10,y1+10,name);
}

int zhushi::DblClk(CPoint point)
{
	CRgn rgn;
	CPoint p[5];
	p[0].x=x1;p[0].y=y1;
	p[1].x=x1;p[1].y=y2;
	p[2].x=x2;p[2].y=y2;
	p[3].x=x2;p[3].y=p2;
	p[4].x=p1;p[4].y=y1;

	rgn.CreatePolygonRgn(p,5,ALTERNATE);
	if(PtInRegion(rgn,point.x,point.y))	
	{
		return 6;
	}
}
void zhushi::setName(CString str)
{
	name=str;		
}
void zhushi::setV(CString str)
{
	//vlist.push_back(str);		
}
void zhushi::setF(CString str)
{
	//flist.push_back(str);
}

void zhushi::addline(base *b)
{
	lines.push_back(b);
}


void zhushi::deleteline(base* b)
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

void zhushi::setend(base* b)
{
}

void zhushi::setstart(base* b)
{
}

base* zhushi::getend()
{
	return NULL;
}
base* zhushi::getstart()
{
	return NULL;
}