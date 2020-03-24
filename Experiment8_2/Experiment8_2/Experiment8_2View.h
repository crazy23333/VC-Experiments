
// Experiment8_2View.h : CExperiment8_2View 类的接口
//

#pragma once


class CExperiment8_2View : public CView
{
protected: // 仅从序列化创建
	CExperiment8_2View();
	DECLARE_DYNCREATE(CExperiment8_2View)

// 特性
public:
	CExperiment8_2Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	bool line, circle, rect;
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
	virtual ~CExperiment8_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Online();
	afx_msg void Oncircle();
	afx_msg void Onrect();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment8_2View.cpp 中的调试版本
inline CExperiment8_2Doc* CExperiment8_2View::GetDocument() const
   { return reinterpret_cast<CExperiment8_2Doc*>(m_pDocument); }
#endif

