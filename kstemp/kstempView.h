// kstempView.h : CkstempView 类的接口
//


#pragma once


class CkstempView : public CView
{
	int x,y,cx,cy,select,ctrl,lb;//select是判断是要画类还是包还是接口等，ctrl表示作为 lb是用来实现按下并移动的标志位
protected: // 仅从序列化创建
	CkstempView();
	DECLARE_DYNCREATE(CkstempView)

// 属性
public:
	CkstempDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CkstempView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClass();
	afx_msg void OnInterface();
	afx_msg void OnPackage();
	afx_msg void OnRelation();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnGuanLian();
	afx_msg void OnJiCheng();
	afx_msg void OnShiXian();
	afx_msg void OnZuHe();
	afx_msg void OnJuHe();
	afx_msg void Onleft();
	afx_msg void On32785();
	afx_msg void On32788();
	afx_msg void On32789();
	afx_msg void On32786();
	afx_msg void On32787();
};

#ifndef _DEBUG  // kstempView.cpp 中的调试版本
inline CkstempDoc* CkstempView::GetDocument() const
   { return reinterpret_cast<CkstempDoc*>(m_pDocument); }
#endif

