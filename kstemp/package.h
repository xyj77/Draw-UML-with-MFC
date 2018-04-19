#include"base.h"
#include<list>
using namespace std;


//	(X1,Y1)		   P1
//		|-----------|
//    P2|-----------|----|
//		|				 |
//		|----------------|
//						(X2,Y2)



class package:public base
{
protected:
	int p1,p2;
	CString name;
	list<CString>vlist;
	list<CString>flist;
public:
	package(int l,int u,int r,int d,int p1,int p2);
	int onpressLB(int x,int y);
	int DblClk(CPoint point);
	void onmove(int cx,int cy);
	void ondraw(CDC *pDC);
	void setName(CString str);//设置类名
	void setV(CString str);
	void setF(CString str);
	void addline(base* b);
	void deleteline(base* b);
	base* getend();
	base* getstart();
	void setend(base* b);
	void setstart(base* b);
	//void output(ostream &out);                  以后再做
};
