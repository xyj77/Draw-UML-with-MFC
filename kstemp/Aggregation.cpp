#include"stdafx.h"
#include"Aggregation.h"

//		x5			x3
//	x1------x7---------x2
//		x6			x4
Aggregation::Aggregation(int tx1, int ty1, int tx2, int ty2):arrow(tx1,ty1,tx2,ty2)
{
	type=0;
	double tx3,ty3,tx4,ty4;
	double ttx2,tty2,ttx1,tty1;
	double tx5,ty5,tx6,ty6;

	ttx2=(double)tx2;
	tty2=(double)ty2;
	ttx1=(double)tx1;
	tty1=(double)ty1;

	x7=tx1;y7=ty1;
	x2=tx2;y2=ty2;
	alength=25;

	angle=atan2(tty1 - tty2, ttx1 - ttx2);
	radius=sqrt(pow(ttx1 - ttx2, 2) + pow(tty1 - tty2, 2));
	tx3= ttx2+ alength * cos(angle + PI / 6);
	ty3= tty2+ alength * sin(angle + PI / 6);
	tx4= ttx2+ alength * cos(angle - PI / 6);
	ty4= tty2+ alength * sin(angle - PI / 6);

	x3=(int)tx3;
	y3=(int)ty3;
	x4=(int)tx4;
	y4=(int)ty4;

	tx5= ttx1+ alength * cos(angle + PI / 6);
	ty5= tty1+ alength * sin(angle + PI / 6);
	tx6= ttx1+ alength * cos(angle - PI / 6);
	ty6= tty1+ alength * sin(angle - PI / 6);

	x5=(int)tx5;
	y5=(int)ty5;
	x6=(int)tx6;
	y6=(int)ty6;

	x1=x5+x6-x7;
	y1=y5+y6-y7;
}

void Aggregation::ondraw(CDC *pDC)
{
	double tx1,tx2,tx3,tx4,ty1,ty2,ty3,ty4;
	double tx5,ty5,tx6,ty6;
	
	tx1=(double)x1;
	tx2=(double)x2;
	ty1=(double)y1;
	ty2=(double)y2;

	angle=atan2(ty1 - ty2, tx1 - tx2);
	radius=sqrt(pow(tx1 - tx2, 2) + pow(ty1 - ty2, 2));
	tx3= tx2+ alength * cos(angle + PI / 6);
	ty3= ty2+ alength * sin(angle + PI / 6);
	tx4= tx2+ alength * cos(angle - PI / 6);
	ty4= ty2+ alength * sin(angle - PI / 6);

	x3=(int)tx3;
	y3=(int)ty3;
	x4=(int)tx4;
	y4=(int)ty4;

	tx5= tx1- alength * cos(angle + PI / 6);
	ty5= ty1- alength * sin(angle + PI / 6);
	tx6= tx1- alength * cos(angle - PI / 6);
	ty6= ty1- alength * sin(angle - PI / 6);

	x5=(int)tx5;
	y5=(int)ty5;
	x6=(int)tx6;
	y6=(int)ty6;

	x7=x5+x6-x1;
	y7=y5+y6-y1;

	if(choose==0)                              //没选中画实线
	{
		pDC->MoveTo(x1,y1);
		pDC->LineTo(x5,y5);
		pDC->LineTo(x7,y7);
		pDC->LineTo(x6,y6);
		pDC->LineTo(x1,y1);
		pDC->MoveTo(x7,y7);
		pDC->LineTo(x2,y2);
		pDC->LineTo(x3,y3);
		pDC->MoveTo(x2,y2);
		pDC->LineTo(x4,y4);
	}

	else if(choose==1)							//选中画虚线
	{
		CPen *oldpen;
		CPen pen(PS_DOT,1,RGB(0,0,0));
		oldpen=pDC->SelectObject(&pen);

		/*pDC->MoveTo(x7,y7);
		pDC->LineTo(x5,y5);
		pDC->LineTo(x1,y1);
		pDC->LineTo(x6,y6);
		pDC->LineTo(x7,y7);
		pDC->MoveTo(x1,y1);
		pDC->LineTo(x2,y2);
		pDC->LineTo(x3,y3);
		pDC->MoveTo(x2,y2);
		pDC->LineTo(x4,y4);*/

		pDC->MoveTo(x1,y1);
		pDC->LineTo(x5,y5);
		pDC->LineTo(x7,y7);
		pDC->LineTo(x6,y6);
		pDC->LineTo(x1,y1);
		pDC->MoveTo(x7,y7);
		pDC->LineTo(x2,y2);
		pDC->LineTo(x3,y3);
		pDC->MoveTo(x2,y2);
		pDC->LineTo(x4,y4);

		pDC->SelectObject(oldpen);
	}
	pDC->TextOutW(x1+45,y1-20,starttxt);//起点
	pDC->TextOutW(x2-35,y2-20,endtxt);//终点
}

int Aggregation::onpressLB(int x, int y)
{
	CRgn rgn;
	CPoint p[3],t[4],l[4];
	p[0].x=x2;p[0].y=y2;
	p[1].x=x3;p[1].y=y3;
	p[2].x=x4;p[2].y=y4;

	int a=(x3+x4)/2;
	int b=(y3+y4)/2;

	t[0].x=x7-cal;t[0].y=y7-cal;
	t[2].x=x7+cal;t[2].y=y7+cal;
	t[1].x=a+cal;t[1].y=b-cal;
	t[3].x=a-cal;t[3].y=b+cal;

	l[0].x=x1;l[0].y=y1;
	l[1].x=x5;l[1].y=y5;
	l[2].x=x7;l[2].y=y7;
	l[3].x=x6;l[3].y=y6;

	rgn.CreatePolygonRgn(p,3,ALTERNATE);
	if(PtInRegion(rgn,x,y))
	{
		state=2;
		choose=1;
		return 1;
	}
	rgn.DeleteObject();

	rgn.CreatePolygonRgn(l,4,ALTERNATE);
	if(PtInRegion(rgn,x,y))
	{
		state=3;
		choose=1;
		return 1;
	}
	rgn.DeleteObject();

	rgn.CreatePolygonRgn(t,4,ALTERNATE);
	if(PtInRegion(rgn,x,y))
	{
		state=1;
		choose=1;
		return 1;
	}
	else 
	{
		choose=0;
		return 0;
	}
}

void Aggregation::onmove(int cx, int cy)
{
	if(state==1)
	{
		x7+=cx;
		y7+=cy;
		x2+=cx;
		y2+=cy;
	}
	else if(state==2)
	{
		x2+=cx;
		y2+=cy;
	}
	else if(state==3)
	{
		x1+=cx;
		y1+=cy;
		x5+=cx;
		y5+=cy;
		x6+=cx;
		y6+=cy;
		x7+=cx;
		y7+=cy;
	}
}
