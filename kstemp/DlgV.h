#pragma once
#include "afxwin.h"
#include "base.h"
#include "kstempDoc.h"

// DlgV 对话框

class DlgV : public CDialog
{
	DECLARE_DYNAMIC(DlgV)
	CkstempDoc* pDoc;
public:
	DlgV(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgV();
	DlgV(CkstempDoc* p);
	//void setList();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_V };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CString n_edit;
	CString v_type;
	//CListCtrl m_list;
	afx_msg void OnCbnSelchangeCombov();
	CString v_p;
};
