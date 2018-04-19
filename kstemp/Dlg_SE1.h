#pragma once


// Dlg_SE1 对话框

class Dlg_SE1 : public CDialog
{
	DECLARE_DYNAMIC(Dlg_SE1)

public:
	Dlg_SE1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dlg_SE1();

// 对话框数据
	enum { IDD = IDD_SE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString n_edit;
};
