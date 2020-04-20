
// Experiment11_3View.h : CExperiment11_3View 类的接口
//

#pragma once


class CExperiment11_3View : public CView
{
protected: // 仅从序列化创建
	CExperiment11_3View();
	DECLARE_DYNCREATE(CExperiment11_3View)

// 特性
public:
	CExperiment11_3Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	bool set1, set2;
	int r;
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
	virtual ~CExperiment11_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment11_3View.cpp 中的调试版本
inline CExperiment11_3Doc* CExperiment11_3View::GetDocument() const
   { return reinterpret_cast<CExperiment11_3Doc*>(m_pDocument); }
#endif

