#include"stdafx.h"
#include"base.h"

base::base(int a,int b,int c,int e)
{
	connect1=0;
	connect2=0;
	cal=10;
	state=0;
	choose=0;
	ctrl=0;
	x1=a;
	y1=b;
	x2=c;
	y2=e;
	dbClk=0;
}

int base::getx1()
{
	return x1;
}

int base::gety1()
{
	return y1;
}

int base::getx2()
{
	return x2;

}

int base::gety2()
{
	return y2;
}
int base::onrelease()
{
	state=0;
	return 1;
	
}
