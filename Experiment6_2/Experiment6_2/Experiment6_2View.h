
// Experiment6_2View.h : CExperiment6_2View 类的接口
//

#pragma once


class CExperiment6_2View : public CView
{
protected: // 仅从序列化创建
	CExperiment6_2View();
	DECLARE_DYNCREATE(CExperiment6_2View)

// 特性
public:
	CExperiment6_2Doc* GetDocument() const;

// 操作
public:
	CRect rect;
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
	virtual ~CExperiment6_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment6_2View.cpp 中的调试版本
inline CExperiment6_2Doc* CExperiment6_2View::GetDocument() const
   { return reinterpret_cast<CExperiment6_2Doc*>(m_pDocument); }
#endif

