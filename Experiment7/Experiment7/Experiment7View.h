
// Experiment7View.h : CExperiment7View 类的接口
//

#pragma once


class CExperiment7View : public CView
{
protected: // 仅从序列化创建
	CExperiment7View();
	DECLARE_DYNCREATE(CExperiment7View)

// 特性
public:
	CExperiment7Doc* GetDocument() const;

// 操作
public:
	CRect cr;
	int l, x, y,r,g,b;
	bool set,col;
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
	virtual ~CExperiment7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // Experiment7View.cpp 中的调试版本
inline CExperiment7Doc* CExperiment7View::GetDocument() const
   { return reinterpret_cast<CExperiment7Doc*>(m_pDocument); }
#endif

