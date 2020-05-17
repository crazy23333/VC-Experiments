
// Experiment15_2View.h : CExperiment15_2View 类的接口
//

#pragma once


class CExperiment15_2View : public CView
{
protected: // 仅从序列化创建
	CExperiment15_2View();
	DECLARE_DYNCREATE(CExperiment15_2View)

// 特性
public:
	CExperiment15_2Doc* GetDocument() const;

// 操作
public:
	int r;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CExperiment15_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment15_2View.cpp 中的调试版本
inline CExperiment15_2Doc* CExperiment15_2View::GetDocument() const
   { return reinterpret_cast<CExperiment15_2Doc*>(m_pDocument); }
#endif

