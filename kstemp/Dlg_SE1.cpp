// Dlg_SE1.cpp : 实现文件
//

#include "stdafx.h"
#include "kstemp.h"
#include "Dlg_SE1.h"


// Dlg_SE1 对话框

IMPLEMENT_DYNAMIC(Dlg_SE1, CDialog)

Dlg_SE1::Dlg_SE1(CWnd* pParent /*=NULL*/)
	: CDialog(Dlg_SE1::IDD, pParent)
	, n_edit(_T(""))
{

}

Dlg_SE1::~Dlg_SE1()
{
}

void Dlg_SE1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n_edit);
}


BEGIN_MESSAGE_MAP(Dlg_SE1, CDialog)
END_MESSAGE_MAP()


// Dlg_SE1 消息处理程序
