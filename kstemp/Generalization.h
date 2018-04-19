#include"arrow.h"

class Generalization:public arrow
{
public:
	Generalization(int tx1,int ty1,int tx2,int ty2);
	void ondraw(CDC *pDC);
};