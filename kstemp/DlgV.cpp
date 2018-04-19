// DlgV.cpp : 实现文件

#include "stdafx.h"
#include "kstemp.h"
#include "DlgV.h"
#include <list>
#include "base.h"
using namespace std;


// DlgV 对话框

IMPLEMENT_DYNAMIC(DlgV, CDialog)

DlgV::DlgV(CWnd* pParent /*=NULL*/)
	: CDialog(DlgV::IDD, pParent)
	, n_edit(_T(""))
	, v_type(_T(""))
	, v_p(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	EnableAutomation();

}

DlgV::~DlgV()
{
}

void DlgV::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void DlgV::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n_edit);
	DDX_CBString(pDX, COMBOV, v_type);
	//DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_CBString(pDX, COMBO, v_p);
}


BEGIN_MESSAGE_MAP(DlgV, CDialog)
	ON_CBN_SELCHANGE(COMBOV, &DlgV::OnCbnSelchangeCombov)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(DlgV, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IDlgV 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {AE9A55F2-DEE1-4566-AE95-37C2B47794A5}
static const IID IID_IDlgV =
{ 0xAE9A55F2, 0xDEE1, 0x4566, { 0xAE, 0x95, 0x37, 0xC2, 0xB4, 0x77, 0x94, 0xA5 } };

BEGIN_INTERFACE_MAP(DlgV, CDialog)
	INTERFACE_PART(DlgV, IID_IDlgV, Dispatch)
END_INTERFACE_MAP()


// DlgV 消息处理程序
DlgV::DlgV(CkstempDoc* p)
{
	pDoc=p;
	//setList();
}
/*void DlgV::setList()
{
		list<base*>::iterator it;	
		for(it=pDoc->base.begin();it!=pDoc->base.end();it++)//寻找双击图元
			if((*it)->dbClk!=0) break;//寻找双击位置
		CRect mRect;
		m_list.GetWindowRect(&mRect);     //获取控件矩形区域
		int kuan = mRect.Width();
		m_list.InsertColumn(0,_T("变量类型"),LVCFMT_LEFT,kuan/4,-1);
		//m_list.InsertColumn(1,_T("变量名"),LVCFMT_CENTER,kuan/4,-1);

		DWORD dwStyle = m_list.GetExtendedStyle(); //获取当前扩展样式
		dwStyle |= LVS_EX_FULLROWSELECT; //选中某行使整行高亮（report风格时）
		dwStyle |= LVS_EX_GRIDLINES; //网格线（report风格时）
		dwStyle |= LVS_EX_CHECKBOXES; //item前生成checkbox控件
		m_list.SetExtendedStyle(dwStyle); //设置扩展风格
}*/
void DlgV::OnCbnSelchangeCombov()
{
	// TODO: 在此添加控件通知处理程序代码
}
