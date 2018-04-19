// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "kstemp.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
}

CMainFrame::~CMainFrame()
{
}





int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
	if (!m_MyToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_LEFT
        | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
        !m_MyToolBar.LoadToolBar(IDR_TOOLBAR1))
    {
        TRACE0("Failed to create toolbar\n");
        return -1;      // fail to create
    }
    m_MyToolBar.EnableDocking(CBRS_ALIGN_ANY);
    EnableDocking(CBRS_ALIGN_ANY);
    DockControlBar(&m_MyToolBar);

	m_imagelist.Create(32,32,ILC_COLOR32|ILC_MASK,0,0);
	CBitmap bmp;
	for(int i=0;i<9;++i)
    {
        bmp.LoadBitmap(IDB_BITMAP1+i);
        m_imagelist.Add(&bmp,RGB(255,255,255));
        bmp.DeleteObject();
    }
	UINT nArray[9];
	nArray[0]=ID_32771;
	nArray[1]=ID_32772;
	nArray[2]=ID_32773;
	nArray[3]=ID_32774;
	nArray[4]=ID_32777;
	nArray[5]=ID_32778;
	nArray[6]=ID_32776;
	nArray[7]=ID_32780;
	nArray[8]=ID_32779;


  //  for(int k=0;k<2;++k)
  //  {
 //       nArray[k]=ID_BUTTON+k;
  //  }
	m_MyToolBar.SetButtons(nArray,9);
    m_MyToolBar.SetSizes(CSize(45,45),CSize(32,32));
	m_MyToolBar.GetToolBarCtrl().SetImageList(&m_imagelist);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}


// CMainFrame 诊断

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame 消息处理程序



