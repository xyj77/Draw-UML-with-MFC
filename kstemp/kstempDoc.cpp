// kstempDoc.cpp : CkstempDoc 类的实现
//

#include "stdafx.h"
#include "kstemp.h"

#include "kstempDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkstempDoc

IMPLEMENT_DYNCREATE(CkstempDoc, CDocument)

BEGIN_MESSAGE_MAP(CkstempDoc, CDocument)
END_MESSAGE_MAP()


// CkstempDoc 构造/析构

CkstempDoc::CkstempDoc()
{
	// TODO: 在此添加一次性构造代码

}

CkstempDoc::~CkstempDoc()
{
}

BOOL CkstempDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CkstempDoc 序列化

void CkstempDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CkstempDoc 诊断

#ifdef _DEBUG
void CkstempDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CkstempDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CkstempDoc 命令
