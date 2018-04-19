#include"base.h"
#include<list>
using namespace std;
class jiekou:public base
{
protected:
	int part;
	CString name;
	list<CString>vlist;
	list<CString>flist;
public:
	jiekou(int l,int u,int r,int d,int p);
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