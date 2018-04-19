#pragma once


// DlgF 对话框

class DlgF : public CDialog
{
	DECLARE_DYNAMIC(DlgF)

public:
	DlgF(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgF();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_F };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CString n_edit;
	afx_msg void OnCbnSelchangeCombo();
	CString f_type;
	afx_msg void OnLbnSelchangeList1();
	CString f_p;
};
