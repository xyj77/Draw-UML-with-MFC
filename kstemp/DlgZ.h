#pragma once


// DlgZ 对话框

class DlgZ : public CDialog
{
	DECLARE_DYNAMIC(DlgZ)

public:
	DlgZ(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgZ();

// 对话框数据
	enum { IDD = IDD_Z };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString n_edit;
};
