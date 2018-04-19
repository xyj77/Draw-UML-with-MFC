#include"stdafx.h"
#include"Generalization.h"

Generalization::Generalization(int tx1,int ty1,int tx2,int ty2):arrow(tx1,ty1,tx2,ty2)
{
	type=0;
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

void Generalization::ondraw(CDC *pDC)
{
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
		pDC->LineTo((x3+x4)/2,(y3+y4)/2);
		pDC->LineTo(x3,y3);
		pDC->LineTo(x2,y2);
		pDC->LineTo(x4,y4);
		pDC->LineTo((x3+x4)/2,(y3+y4)/2);
	}

	else if(choose==1)							//选中画虚线
	{
		CPen *oldpen;
		CPen pen(PS_DOT,1,RGB(0,0,0));
		oldpen=pDC->SelectObject(&pen);

		pDC->MoveTo(x1,y1);
		pDC->LineTo((x3+x4)/2,(y3+y4)/2);
		pDC->LineTo(x3,y3);
		pDC->LineTo(x2,y2);
		pDC->LineTo(x4,y4);
		pDC->LineTo((x3+x4)/2,(y3+y4)/2);

		pDC->SelectObject(oldpen);
	}
	pDC->TextOutW(x1+10,y1-20,starttxt);//起点
	pDC->TextOutW(x2-35,y2-20,endtxt);//终点
}