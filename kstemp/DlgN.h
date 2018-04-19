#pragma once


// DlgN 对话框

class DlgN : public CDialog
{
	DECLARE_DYNAMIC(DlgN)

public:
	DlgN(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgN();

	virtual void OnFinalRelease();

// 对话框数据
	enum { IDD = IDD_N };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	CString n_edit;
};
