#include"stdafx.h"
#include"arrow.h"

arrow::arrow(int tx1,int ty1,int tx2,int ty2):base(tx1,ty1,tx2,ty2)
{
	type=0;
	endl=NULL;
	start=NULL;
	
	double tx3,ty3,tx4,ty4;
	double ttx2,tty2,ttx1,tty1;

	ttx2=(double)tx2;
	tty2=(double)ty2;
	ttx1=(double)tx1;
	tty1=(double)ty1;

	x1=tx1;y1=ty1;
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
}

int arrow::onpressLB(int x, int y)
{
	CRgn rgn;
	CPoint p[3],t[4];
	p[0].x=x2;p[0].y=y2;
	p[1].x=x3;p[1].y=y3;
	p[2].x=x4;p[2].y=y4;

	int a=(x3+x4)/2;
	int b=(y3+y4)/2;

	t[0].x=x1-cal;t[0].y=y1-cal;
	t[1].x=x1+cal;t[1].y=y1+cal;
	t[2].x=a+cal;t[2].y=b-cal;
	t[3].x=a-cal;t[3].y=b+cal;

	rgn.CreatePolygonRgn(p,3,ALTERNATE);

	if(PtInRegion(rgn,x,y))
	{
		state=2;
		choose=1;
		return 1;
	}
	rgn.DeleteObject();

	if(x>x1-cal&&x<x1+cal&&y>y1-cal&&y<y1+cal)
	{
		state=3;
		choose=1;
		return 1;
	}

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


void arrow::onmove(int cx, int cy)
{
	if(state==1)
	{
		x1+=cx;
		y1+=cy;
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
	}

}

void arrow::ondraw(CDC *pDC)
{

	/*if(start!=NULL)
	{
		if(1)//连接在类左边
		x2=(start->x1+start->x2)/2;
		y2=start->y2;
	}*/


	double tx1,tx2,tx3,tx4,ty1,ty2,ty3,ty4;
	
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

	if(choose==0)                              //没选中画实线
	{
		pDC->MoveTo(x1,y1);
		pDC->LineTo(x2,y2);
		pDC->MoveTo(x2,y2);
		pDC->LineTo(x3,y3);
		pDC->MoveTo(x2,y2);
		pDC->LineTo(x4,y4);
	}

	else if(choose==1)							//选中画虚线
	{
		CPen *oldpen;
		CPen pen(PS_DOT,1,RGB(0,0,0));
		oldpen=pDC->SelectObject(&pen);

		pDC->MoveTo(x1,y1);
		pDC->LineTo(x2,y2);
		pDC->MoveTo(x2,y2);
		pDC->LineTo(x3,y3);
		pDC->MoveTo(x2,y2);
		pDC->LineTo(x4,y4);

		pDC->SelectObject(oldpen);
	}
	pDC->TextOutW(x1+10,y1-20,starttxt);//起点
	pDC->TextOutW(x2-35,y2-20,endtxt);//终点

}
int arrow::DblClk(CPoint point)
{
	int R=20,text;
	CRgn rgn1,rgn2;
	CPoint p1[4],p2[4];
	p1[0].x=x1-R;p1[0].y=y1-R;
	p1[1].x=x1-R;p1[1].y=y1+R;
	p1[2].x=x1+R;p1[2].y=y1+R;
	p1[3].x=x1+R;p1[3].y=y1-R;
	
	p2[0].x=x2-R;p2[0].y=y2-R;
	p2[1].x=x2-R;p2[1].y=y2+R;
	p2[2].x=x2+R;p2[2].y=y2+R;
	p2[3].x=x2+R;p2[3].y=y2-R;

	rgn1.CreatePolygonRgn(p1,4,ALTERNATE);
	rgn2.CreatePolygonRgn(p2,4,ALTERNATE);
	if(PtInRegion(rgn1,point.x,point.y))		//移动  state==1 move
	{
		text=4;
	}
	else if(PtInRegion(rgn2,point.x,point.y))
	{
		text=5;
	}
	dbClk=text;
	return text;
}
void arrow::setName(CString str)
{
}
void arrow::setF(CString str)
{
	endtxt=str;
}
void arrow::setV(CString str)
{
	starttxt=str;
}

void arrow::setend(base* b)
{
	endl=b;
}

void arrow::setstart(base* b)
{
	start = b;
}

base* arrow::getend()
{
	return endl;
}

base* arrow::getstart()
{
	return start;
}

void arrow::addline(base *b)
{
	
}


void arrow::deleteline(base* b)
{
	
}


