
// Experiment6_3View.h : CExperiment6_3View 类的接口
//

#pragma once


class CExperiment6_3View : public CView
{
protected: // 仅从序列化创建
	CExperiment6_3View();
	DECLARE_DYNCREATE(CExperiment6_3View)

// 特性
public:
	CExperiment6_3Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	bool set,a,b;
	int bottom;
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
	virtual ~CExperiment6_3View();
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
};

#ifndef _DEBUG  // Experiment6_3View.cpp 中的调试版本
inline CExperiment6_3Doc* CExperiment6_3View::GetDocument() const
   { return reinterpret_cast<CExperiment6_3Doc*>(m_pDocument); }
#endif

