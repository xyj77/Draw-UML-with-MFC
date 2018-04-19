// kstempView.cpp : CkstempView 类的实现
//

#include "stdafx.h"
#include "kstemp.h"

#include "kstempDoc.h"
#include "kstempView.h"
#include "DlgN.h"
#include "DlgV.h"
#include "DlgF.h"
#include "Dlg_SE1.h"
#include "DlgZ.h"
#include"jiekou.h"
#include"zhushi.h"
#include"package.h"
#include"Composition.h"
#include"Aggregation.h"
#include"Generalization.h"
#include"Realization.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkstempView

IMPLEMENT_DYNCREATE(CkstempView, CView)

BEGIN_MESSAGE_MAP(CkstempView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CkstempView::OnClass)
	ON_COMMAND(ID_32772, &CkstempView::OnInterface)
	ON_COMMAND(ID_32773, &CkstempView::OnPackage)
	ON_COMMAND(ID_32774, &CkstempView::OnRelation)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_COMMAND(ID_32776, &CkstempView::OnGuanLian)
	ON_COMMAND(ID_32777, &CkstempView::OnJiCheng)
	ON_COMMAND(ID_32778, &CkstempView::OnShiXian)
	ON_COMMAND(ID_32779, &CkstempView::OnZuHe)
	ON_COMMAND(ID_32780, &CkstempView::OnJuHe) 
	ON_COMMAND(ID_32784, &CkstempView::Onleft)
	ON_COMMAND(ID_32785, &CkstempView::On32785)
	ON_COMMAND(ID_32788, &CkstempView::On32788)
	ON_COMMAND(ID_32789, &CkstempView::On32789)
	ON_COMMAND(ID_32786, &CkstempView::On32786)
	ON_COMMAND(ID_32787, &CkstempView::On32787)
END_MESSAGE_MAP()

// CkstempView 构造/析构

CkstempView::CkstempView()
{
	// TODO: 在此处添加构造代码

}

CkstempView::~CkstempView()
{
}
BOOL CkstempView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CkstempView 绘制

void CkstempView::OnDraw(CDC *pDC)               //画图
{
	CkstempDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	list<base*>::reverse_iterator it;
	for(it=GetDocument()->base.rbegin();it!=GetDocument()->base.rend();it++)
		(*it)->ondraw(pDC);

	// TODO: 在此处为本机数据添加绘制代码
}


// CkstempView 打印

BOOL CkstempView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CkstempView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CkstempView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CkstempView 诊断

#ifdef _DEBUG
void CkstempView::AssertValid() const
{
	CView::AssertValid();
}

void CkstempView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CkstempDoc* CkstempView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CkstempDoc)));
	return (CkstempDoc*)m_pDocument;
}
#endif //_DEBUG


// CkstempView 消息处理程序

void CkstempView::OnClass()                   //画类
{
	// TODO: 在此添加命令处理程序代码
	select=1;
}

void CkstempView::OnInterface()                   //接口
{
	// TODO: 在此添加命令处理程序代码
	select=2;
}


void CkstempView::OnPackage()                   //包                
{ 
	// TODO: 在此添加命令处理程序代码
	select=3;
}

void CkstempView::OnRelation()                    //关系
{
	// TODO: 在此添加命令处理程序代码
	select=4;
}


void CkstempView::OnLButtonDown(UINT nFlags, CPoint point)           //按下左键
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	lb=1;
	x=point.x;
	y=point.y;

	Class *cla=new Class(x-80,y,x+80,y+100,y+25,y+60);               //初始化
	jiekou *jk=new jiekou(x-80,y,x+80,y+100,y+25);
	package *pac=new package(x-75,y,x+75,y+110,x+35,y+25);
	arrow *arr=new arrow(x-60,y-60,x+60,y+60);
	zhushi *zs=new zhushi(x-60,y,x+60,y+75,x+35,y+30,x+30);
	Generalization *ger=new Generalization(x-80,y,x+80,y);
	Realization *rea=new Realization(x-80,y,x+80,y);
	Aggregation *agg=new Aggregation(x-80,y,x+80,y);
	Composition *com=new Composition(x-80,y,x+80,y);
	switch(select){                                                        //根据不同选择绘制不同的图形
		case 1:
			GetDocument()->base.push_front(cla);
			Invalidate(TRUE);
			break;
		case 2:
			GetDocument()->base.push_front(jk);
			Invalidate(TRUE);
			break;
		case 3:
			GetDocument()->base.push_front(pac);
			Invalidate(TRUE);
			break;
		case 4:
			GetDocument()->base.push_front(zs);
			Invalidate(TRUE);
			break;
		case 51:
			GetDocument()->base.push_front(arr);
			Invalidate(TRUE);
			break;
		case 52:
			GetDocument()->base.push_front(ger);
			Invalidate(TRUE);
			break;
		case 53:
			GetDocument()->base.push_front(rea);
			Invalidate(TRUE);
			break;
		case 54:
			GetDocument()->base.push_front(com);
			Invalidate(TRUE);
			break;
		case 55:
			GetDocument()->base.push_front(agg);
			Invalidate(TRUE);
			break;

	}
	
	list<base*>::iterator it;
	if(ctrl!=1)
	{
		for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)        //如果重叠 将点击的图置于图层顶层
		{
			if(1==(*it)->onpressLB(point.x,point.y))
			{
				GetDocument()->base.push_front(*it);
				GetDocument()->base.erase(it);
				break;
			}

		}
		Invalidate(TRUE);
	}

	it=GetDocument()->base.begin();										//在没按ctrl时将除第一个以外的choose都置为0
	if(ctrl!=1&&it!=GetDocument()->base.end())
	{
		it++;
		for(;it!=GetDocument()->base.end();it++)
			(*it)->choose=0;
	}
	else if(ctrl==1)													//在按ctrl时将选中的choose都置为1
	{
		for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
			if(1==(*it)->onpressLB(point.x,point.y))
				(*it)->choose=1;
	}
	Invalidate(TRUE);

	CView::OnLButtonDown(nFlags, point);
}

void CkstempView::OnLButtonUp(UINT nFlags, CPoint point)              //放开左键
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	lb=0;
	list<base*>::iterator it;
	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
		(*it)->onrelease();

	select=0;

	Invalidate(TRUE);

	CView::OnLButtonUp(nFlags, point);
}

void CkstempView::OnLButtonDblClk(UINT nFlags, CPoint point)           //双击左键
{       
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	list<base*>::iterator it;	int text;
	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)//寻找双击图元
		if((text=(*it)->DblClk(point))!=0) break;//寻找双击位置
/*
	CDialog *pDlg=new CDialog();//非模态
	if(text==1)//
	{
		pDlg->Create(IDD_V,this);
		pDlg->ShowWindow(SW_SHOW);
		
	}*/

	if(text==1)//模态
	{
		DlgN dlg;
		if(dlg.DoModal()==IDOK)
		{
			CString str=dlg.n_edit;
			//MessageBox(str);
			(*it)->setName(str);
			RedrawWindow();
		}
	}
	else if(text==2)
	{
		//DlgV dlg(GetDocument());
		DlgV dlg;
		if(dlg.DoModal()==IDOK)
		{
			CString str=dlg.n_edit;
			if(dlg.v_type.Compare(_T("public"))==0)
				str=_T("+ ")+str;
			else if(dlg.v_type.Compare(_T("protected"))==0)
				str=_T("# ")+str;
			else
				str=_T("- ")+str;
			if(dlg.v_p.Compare(_T("int"))==0)
				str=str+_T(" : int");
			else if(dlg.v_p.Compare(_T("double"))==0)
				str=str+_T(" : double");
			else if(dlg.v_p.Compare(_T("char"))==0)
				str=str+_T(":char");
			else if(dlg.v_p.Compare(_T("float"))==0)
				str=str+_T(" : float");
			else if(dlg.v_p.Compare(_T("long"))==0)
				str=str+_T(" : long");
			else
				str=str+_T(" : ")+dlg.v_p;
			(*it)->setV(str);
			RedrawWindow();
		}
	}
	else if(text==3)
	{
		DlgF dlg;
		if(dlg.DoModal()==IDOK)
		{
			CString str=dlg.n_edit;
			if(dlg.f_type.Compare(_T("public"))==0)
				str=_T("+ ")+str;
			else if(dlg.f_type.Compare(_T("protected"))==0)
				str=_T("# ")+str;
			else
				str=_T("- ")+str;
			if(dlg.f_p.Compare(_T("int"))==0)
				str=str+_T("( ) : int");
			else if(dlg.f_p.Compare(_T("double"))==0)
				str=str+_T("( ) : double");
			else if(dlg.f_p.Compare(_T("char"))==0)
				str=str+_T("( ) : char");
			else if(dlg.f_p.Compare(_T("float"))==0)
				str=str+_T("( ) : float");
			else if(dlg.f_p.Compare(_T("long"))==0)
				str=str+_T("( ) : long");
			else
				str=str+_T("( ) : ")+dlg.f_p;
			(*it)->setF(str);
			RedrawWindow();
		}
	}
	else if(text==4)
	{
		Dlg_SE1 dlg;
		if(dlg.DoModal()==IDOK)
		{
			CString str=dlg.n_edit;
			(*it)->setV(str);
			RedrawWindow();
		}
	}
	else if(text==5)
	{
		Dlg_SE1 dlg;
		if(dlg.DoModal()==IDOK)
		{
			CString str=dlg.n_edit;
			(*it)->setF(str);
			RedrawWindow();
		}
	}
	else if(text==6)
	{
		DlgZ dlg;
		if(dlg.DoModal()==IDOK)
		{
			CString str=dlg.n_edit;
			(*it)->setName(str);
			RedrawWindow();
		}
	}

	CView::OnLButtonDblClk(nFlags, point);
}


void CkstempView::OnMouseMove(UINT nFlags, CPoint point)                //鼠标移动    未添加connect功能
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cx=point.x-x;
	cy=point.y-y;

	CPoint t[4];
	list<base*>::iterator it;
	list<base*>::iterator it1;

	if(lb==1)															//lb等于1代表状态：鼠标按下且移动
	{
		for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
			if((*it)->choose==1)
			{
				if((*it)->state==0)
					(*it)->state=1;
				(*it)->onmove(cx,cy);
			}

		x=point.x;
		y=point.y;
		Invalidate(TRUE);
	}

	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
	{
		if((*it)->type==0)    //如果是箭头
		{
			for(it1=GetDocument()->base.begin();it1!=GetDocument()->base.end();it1++)
			{
				switch((*it1)->type)
					case 1:
						t[0].x=(*it1)->x1;t[0].y=((*it1)->y1+(*it1)->y2)/2;
						t[1].x=((*it1)->x1+(*it1)->x2)/2;t[1].y=(*it1)->y1;
						t[2].x=(*it1)->x2;t[2].y=((*it1)->y1+(*it1)->y2)/2;
						t[3].x=((*it1)->x1+(*it1)->x2)/2;t[3].y=(*it1)->y2;
						if((*it)->x1>t[0].x-15&&(*it)->x1<t[0].x+15&&(*it)->y1>t[0].y-15&&(*it)->y1<t[0].y+15) //末尾区域
						{	
							(*it)->x1=t[0].x;(*it)->y1=t[0].y;
							
							if((*it)->connect1==0)
							{
								(*it)->setstart((*it1));
								(*it1)->addline((*it));
								(*it)->connect1=1;
							}	
							
						}
						else if((*it)->x1>t[1].x-15&&(*it)->x1<t[1].x+15&&(*it)->y1>t[1].y-15&&(*it)->y1<t[1].y+15)
						{	
							(*it)->x1=t[1].x;(*it)->y1=t[1].y;
							
							if((*it)->connect1==0)
							{
								(*it)->setstart((*it1));
								(*it1)->addline((*it));
								(*it)->connect1=1;
							}
							
						}
						else if((*it)->x1>t[2].x-15&&(*it)->x1<t[2].x+15&&(*it)->y1>t[2].y-15&&(*it)->y1<t[2].y+15)
						{	
							(*it)->x1=t[2].x;(*it)->y1=t[2].y;
							
							if((*it)->connect1==0)
							{
								(*it)->setstart((*it1));
								(*it1)->addline((*it));
								(*it)->connect1=1;
							}
							
						}

						else if((*it)->x1>t[3].x-15&&(*it)->x1<t[3].x+15&&(*it)->y1>t[3].y-15&&(*it)->y1<t[3].y+15)
						{	
							(*it)->x1=t[3].x;(*it)->y1=t[3].y;
							
							if((*it)->connect1==0)
							{
								(*it)->setstart((*it1));
								(*it1)->addline((*it));
								(*it)->connect1=1;
							}
							
						}
						else 
						{
							(*it)->connect1=0;
							///(*it1)->deleteline((*it));
						}
							
						if((*it)->x2>t[0].x-15&&(*it)->x2<t[0].x+15&&(*it)->y2>t[0].y-15&&(*it)->y2<t[0].y+15)  //箭头区域
						{	
							(*it)->x2=t[0].x;(*it)->y2=t[0].y;
								
							if((*it)->connect2==0)
							{
								(*it)->setend((*it1));
								(*it1)->addline((*it));	
								(*it)->connect2=1;
							}
											        
								
						}
						else if((*it)->x2>t[1].x-15&&(*it)->x2<t[1].x+15&&(*it)->y2>t[1].y-15&&(*it)->y2<t[1].y+15)
						{	
							(*it)->x2=t[1].x;(*it)->y2=t[1].y;
							(*it)->connect2=1;
						
							if((*it)->connect2==0)
							{
								(*it)->setend((*it1));
								(*it1)->addline((*it));	
								(*it)->connect2=1;
							}
						
							       
						}
						else if((*it)->x2>t[2].x-15&&(*it)->x2<t[2].x+15&&(*it)->y2>t[2].y-15&&(*it)->y2<t[2].y+15)
						{	
							(*it)->x2=t[2].x;(*it)->y2=t[2].y;
							(*it)->connect2=1;
						
							if((*it)->connect2==0)
							{
								(*it)->setend((*it1));
								(*it1)->addline((*it));	
								(*it)->connect2=1;
							}
					
						}
						else if((*it)->x2>t[3].x-15&&(*it)->x2<t[3].x+15&&(*it)->y2>t[3].y-15&&(*it)->y2<t[3].y+15)
						{	
							(*it)->x2=t[3].x;(*it)->y2=t[3].y;
							(*it)->connect2=1;
							
							if((*it)->connect2==0)
							{
								(*it)->setend((*it1));
								(*it1)->addline((*it));	
								(*it)->connect2=1;
							}
							
						}
						else
						{
							(*it)->connect2=0;
							//(*it1)->deleteline((*it));
						}
						break;
			}

		}

	}
		//x=point.x;
		//y=point.y;
		//Invalidate(TRUE);
	CView::OnMouseMove(nFlags, point);
}

void CkstempView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)                //按下系统键
{
	int a=0;
	list<base*>::iterator it;
	list<base*>::iterator it1;
	list<base*>::iterator it2;

	if(nChar==17)			//--ctrl
	{
		for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
			(*it)->ctrl=1;
		ctrl=1;
	}

	if(nChar==8)			//--delete 把所有choose为1的全部删除
	{
		for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();)
		{
			
			if((*it)->choose==1)
			{
				int t=(*it)->type;
				if(t!=0)
				{
					list<base*> lines=(*it)->lines;
				
					for(it1=lines.begin();it1!=lines.end();it1++)
					{
						a++;
						if((*it1)->getend()==(*it)&&(*it1)->getstart()!=NULL)
						{
							base *start=(*it1)->getstart();
							start->deleteline((*it1));
						}
						else if((*it1)->getstart()==(*it)&&(*it1)->getend()!=NULL)
						{
							base *end=(*it1)->getend();
							end->deleteline((*it1));
						}
					
						for(it2=GetDocument()->base.begin();it2!=GetDocument()->base.end();)
						{
							if( ( *it2) == (*it1))
							{
								it2 = GetDocument()->base.erase(it2);
							}
							else
							{
								it2++;
							}
						}
					}
				}
				else if(t==0)
				{
					if((*it)->getend()!=NULL)
					{
						base *end=(*it)->getend();
						end->deleteline((*it));
					}
					if((*it)->getstart()!=NULL)
					{
						base *start=(*it)->getstart();
						start->deleteline((*it));
					}

				}
				Invalidate(TRUE);
				it=GetDocument()->base.erase(it);
				Invalidate(TRUE);
			//it=GetDocument()->base.begin();
			//	if(it==GetDocument()->base.end())
			//		break;
			}
			else
				it++;
		}

	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CkstempView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)					//释放系统键
{
	if(nChar==17)			//--ctrl
	{
		list<base*>::iterator it;
		for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
			(*it)->ctrl=0;
		ctrl=0;
	}

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CkstempView::OnGuanLian()				//关联
{
	select=51;
	// TODO: 在此添加命令处理程序代码
}

void CkstempView::OnJiCheng()				//继承
{
	select=52;
	// TODO: 在此添加命令处理程序代码
}
void CkstempView::OnShiXian()				//实现
{
	select=53;
	// TODO: 在此添加命令处理程序代码
}

void CkstempView::OnZuHe()					//组合
{
	select=54;
	// TODO: 在此添加命令处理程序代码
}
void CkstempView::OnJuHe()					//聚合
{
	select=55;
	// TODO: 在此添加命令处理程序代码
}
void CkstempView::Onleft()
{
	// TODO: 在此添加命令处理程序代码
	list<base*>::iterator it;
	list<base*>::iterator it1;
	int first=0;
	int x1=0;
	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
	{
		if((*it)->choose==1&&first==0&&(*it)->type==1)
		{
			x1=(*it)->getx1();
			first=1;
		}
		else if((*it)->choose==1&&first==1&&(*it)->type==1)
		{
			
			int x2=(*it)->getx1();
			int cx=x2-x1;
			list<base*> lines=(*it)->lines;
			for(it1=lines.begin();it1!=lines.end();it1++)
			{
				if((*it1)->getend()==(*it))
					(*it)->state=2;
				else if((*it1)->getstart()==(*it))
					(*it)->state=3;
				//(*it1)->onmove(-cx,0);
			}
			if((*it)->state==0)
					(*it)->state=1;
			(*it)->onmove(-cx,0);
		}
		
	}
	Invalidate(TRUE);
	
}

void CkstempView::On32785()
{
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加命令处理程序代码
	list<base*>::iterator it;
	list<base*>::iterator it1;
	int first=0;
	int x1=0;
	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
	{
		if((*it)->choose==1&&first==0&&(*it)->type==1)
		{
			x1=(*it)->getx2();
			first=1;
		}
		else if((*it)->choose==1&&first==1)
		{
			int x2=(*it)->getx2();
			int cx=x2-x1;
			list<base*> lines=(*it)->lines;
			for(it1=lines.begin();it1!=lines.end();it1++)
			{
				if((*it1)->getend()==(*it))
					(*it1)->state=2;
				else if((*it1)->getstart()==(*it))
					(*it1)->state=3;
				(*it1)->onmove(-cx,0);
			}
			if((*it)->state==0)
					(*it)->state=1;
			(*it)->onmove(-cx,0);
		}
		
	}
	Invalidate(TRUE);
}

void CkstempView::On32788()
{
	// TODO: 在此添加命令处理程序代码
	list<base*>::iterator it;
	list<base*>::iterator it1;
	int first=0;
	int y1=0;
	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
	{
		if((*it)->choose==1&&first==0&&(*it)->type==1)
		{
			y1=(*it)->gety1();
			first=1;
		}
		else if((*it)->choose==1&&first==1)
		{
			int y2=(*it)->gety1();
			int cy=y2-y1;
			list<base*> lines=(*it)->lines;
			for(it1=lines.begin();it1!=lines.end();it1++)
			{
				if((*it1)->getend()==(*it))
					(*it1)->state=2;
				else if((*it1)->getstart()==(*it))
					(*it1)->state=3;
				(*it1)->onmove(0,-cy);
			}
			if((*it)->state==0)
				(*it)->state=1;
			(*it)->onmove(0,-cy);
		}
		
	}
	Invalidate(TRUE);
}

void CkstempView::On32789()
{
	// TODO: 在此添加命令处理程序代码
	list<base*>::iterator it;
	list<base*>::iterator it1;
	int first=0;
	int y1=0;
	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
	{
		if((*it)->choose==1&&first==0&&(*it)->type==1)
		{
			y1=(*it)->gety2();
			first=1;
		}
		else if((*it)->choose==1&&first==1)
		{
			int y2=(*it)->gety2();
			int cy=y2-y1;
			list<base*> lines=(*it)->lines;
			for(it1=lines.begin();it1!=lines.end();it1++)
			{
				if((*it1)->getend()==(*it))
					(*it1)->state=2;
				else if((*it1)->getstart()==(*it))
					(*it1)->state=3;
				(*it1)->onmove(0,-cy);
			}
			if((*it)->state==0)
					(*it)->state=1;
			(*it)->onmove(0,-cy);
		}
		
	}
	Invalidate(TRUE);
}

void CkstempView::On32786()
{
	// TODO: 在此添加命令处理程序代码
	list<base*>::iterator it;
	list<base*>::iterator it1;
	int first=0;
	int y1=0,y2=0;
	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
	{
		if((*it)->choose==1&&first==0&&(*it)->type==1)
		{
			y1=(*it)->gety1();
			y2=(*it)->gety2();
			first=1;
		}
		else if((*it)->choose==1&&first==1)
		{
			int y3=(*it)->gety1();
			int y4=(*it)->gety2();
			int cy=(y1+y2)/2-(y3+y4)/2;
			list<base*> lines=(*it)->lines;
			for(it1=lines.begin();it1!=lines.end();it1++)
			{
				if((*it1)->getend()==(*it))
					(*it1)->state=2;
				else if((*it1)->getstart()==(*it))
					(*it1)->state=3;
				(*it1)->onmove(0,cy);
			}
			if((*it)->state==0)
					(*it)->state=1;
			(*it)->onmove(0,cy);
		}
		
	}
	Invalidate(TRUE);
}

void CkstempView::On32787()
{
	// TODO: 在此添加命令处理程序代码
	list<base*>::iterator it;
	list<base*>::iterator it1;
	int first=0;
	int x1=0,x2=0;
	for(it=GetDocument()->base.begin();it!=GetDocument()->base.end();it++)
	{
		if((*it)->choose==1&&first==0&&(*it)->type==1)
		{

			x1=(*it)->getx1();
			x2=(*it)->getx2();
			first=1;
		}
		else if((*it)->choose==1&&first==1)
		{
			int x3=(*it)->getx1();
			int x4=(*it)->getx2();
			int cx=(x1+x2)/2-(x3+x4)/2;
			list<base*> lines=(*it)->lines;
			for(it1=lines.begin();it1!=lines.end();it1++)
			{
				if((*it1)->getend()==(*it))
					(*it1)->state=2;
				else if((*it1)->getstart()==(*it))
					(*it1)->state=3;
				(*it1)->onmove(cx,0);
			}
			if((*it)->state==0)
					(*it)->state=1;
			(*it)->onmove(cx,0);
		}
		
	}
	Invalidate(TRUE);
}
