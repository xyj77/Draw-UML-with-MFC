// DlgN.cpp : 实现文件
//

#include "stdafx.h"
#include "kstemp.h"
#include "DlgN.h"


// DlgN 对话框

IMPLEMENT_DYNAMIC(DlgN, CDialog)

DlgN::DlgN(CWnd* pParent /*=NULL*/)
	: CDialog(DlgN::IDD, pParent)
	, n_edit(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif

	EnableAutomation();

}

DlgN::~DlgN()
{
}

void DlgN::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。基类将自动
	// 删除该对象。在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialog::OnFinalRelease();
}

void DlgN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, EDIT_NAME, n_edit);
}


BEGIN_MESSAGE_MAP(DlgN, CDialog)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(DlgN, CDialog)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IDlgN 支持
//  以支持来自 VBA 的类型安全绑定。此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {34218BF5-87C2-404E-9159-55024AF94F16}
static const IID IID_IDlgN =
{ 0x34218BF5, 0x87C2, 0x404E, { 0x91, 0x59, 0x55, 0x2, 0x4A, 0xF9, 0x4F, 0x16 } };

BEGIN_INTERFACE_MAP(DlgN, CDialog)
	INTERFACE_PART(DlgN, IID_IDlgN, Dispatch)
END_INTERFACE_MAP()


// DlgN 消息处理程序
