#include"stdafx.h"
#include"Class.h"
#define LINE 16
Class::Class(int l,int u,int r,int d,int p1,int p2):base(l,u,r,d)
{
	type=1;

	part1=p1;
	part2=p2;
	name=_T("未命名");
}

int Class::onpressLB(int x,int y)
{
	if(x>x1&&x<x2&&y>y1&&y<part1)  //移动
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

void Class::onmove(int cx, int cy)
{
	if(state==1)
	{
		x1+=cx;
		x2+=cx;
		y1+=cy;
		y2+=cy;
		part1+=cy;
		part2+=cy;
	}
}

void Class::ondraw(CDC *pDC)
{
	if(choose==0)                              //没选中画实线
	{
		pDC->Rectangle(x1,y1,x2,y2);
		pDC->Rectangle(x1,part1,x2,part2);
	}
	else if(choose==1)							//选中画虚线
	{
		CPen *oldpen;
		CPen pen(PS_DOT,1,RGB(0,0,0));
		oldpen=pDC->SelectObject(&pen);

		pDC->Rectangle(x1,y1,x2,y2);
		pDC->Rectangle(x1,part1,x2,part2);

		pDC->SelectObject(oldpen);
	}

	pDC->TextOutW(x1+(x2-x1)/2-25,y1+5,name);
	//pDC->TextOutW(x1+4,part1+5,variate);
	//pDC->TextOutW(x1+4,part2+5,function);
	list<CString>::iterator it;	
	int vy=part1+5,fy=part2+5;
	for(it=vlist.begin();it!=vlist.end();it++)
	{
		pDC->TextOutW(x1+8,vy,it->GetBuffer(0));
		vy=vy+LINE;
		if(vy>=part2)
		{
			part2+=LINE;
			y2+=LINE;
		}
	}
	for(it=flist.begin();it!=flist.end();it++)
	{
		pDC->TextOutW(x1+8,fy,it->GetBuffer(0));
		fy=fy+LINE;
		if(fy>=y2)
		{
			y2+=LINE;
		}
	}
}

int Class::DblClk(CPoint point)
{
	int text=0;
	if(point.x>x1&&point.x<x2&&point.y>y1&&point.y<y2) //双击
	{
		if(point.y<part1)
			text=1;
		else if(point.y<part2)
			text=2;
		else
			text=3;
	}
	dbClk=text;
	return text;
}
void Class::setName(CString str)
{
	name=str;		
}
void Class::setV(CString str)
{
	vlist.push_back(str);		
}
void Class::setF(CString str)
{
	flist.push_back(str);
}

void Class::addline(base *b)
{
	lines.push_back(b);
}


void Class::deleteline(base* b)
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
int Class::size()
{
	int a=0;
	list< base*>::iterator itList;
	for( itList = lines.begin(); itList != lines.end();itList++ )
	{
		a++;
		
	}
	return 10;
}

void Class::setend(base* b)
{
}

void Class::setstart(base* b)
{
}

base* Class::getend()
{
	return NULL;
}
base* Class::getstart()
{
	return NULL;
}

/*list<base*> Class::getlines()
{
	return lines;
}*/