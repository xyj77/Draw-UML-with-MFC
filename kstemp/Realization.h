#include"arrow.h"

class Realization:public arrow
{
public:
	Realization(int tx1,int ty1,int tx2,int ty2);
	void ondraw(CDC *pDC);
};