#include"arrow.h"

class Aggregation:public arrow
{
protected:
	int x5,x6,x7,y5,y6,y7;
public:
	Aggregation(int tx1,int ty1,int tx2,int ty2);
	void ondraw(CDC *pDC);
	int onpressLB(int x,int y);
	void onmove(int cx,int cy);
};