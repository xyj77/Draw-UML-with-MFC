// kstempDoc.h : CkstempDoc 类的接口
//
#include<list>
using namespace std;
#include"Class.h"
#include"arrow.h"
#include<iostream>
using namespace std;

#pragma once


class CkstempDoc : public CDocument
{
protected: // 仅从序列化创建
	CkstempDoc();
	DECLARE_DYNCREATE(CkstempDoc)

// 属性
public:
	list<base*>base;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CkstempDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


