// DlgF.cpp : 实现文件
//

#include "stdafx.h"
#include "kstemp.h"
#include "DlgF.h"


// DlgF 对话框

IMPLEMENT_DYNAMIC(DlgF, CDialog)

DlgF::DlgF(CWnd* pParent /*=NULL*/)
	: CDialog(DlgF::IDD, pParent)
	, n_edit(_T(""))
	, f_type(_T(""))
	, f_p(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	EnableAutomation();

}

DlgF::~DlgF()
{
}

void DlgF::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void DlgF::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n_edit);
	DDX_CBString(pDX, COMBOF, f_type);
	DDX_CBString(pDX, COMBO, f_p);
}


BEGIN_MESSAGE_MAP(DlgF, CDialog)
	ON_CBN_SELCHANGE(COMBO, &DlgF::OnCbnSelchangeCombo)
	ON_LBN_SELCHANGE(IDC_LIST1, &DlgF::OnLbnSelchangeList1)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(DlgF, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IDlgF 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {1FA7C89C-5D34-4740-8042-51D9705F83A0}
static const IID IID_IDlgF =
{ 0x1FA7C89C, 0x5D34, 0x4740, { 0x80, 0x42, 0x51, 0xD9, 0x70, 0x5F, 0x83, 0xA0 } };

BEGIN_INTERFACE_MAP(DlgF, CDialog)
	INTERFACE_PART(DlgF, IID_IDlgF, Dispatch)
END_INTERFACE_MAP()


// DlgF 消息处理程序

void DlgF::OnCbnSelchangeCombo()
{
	// TODO: 在此添加控件通知处理程序代码
}

void DlgF::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
}
