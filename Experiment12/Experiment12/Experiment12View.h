
// Experiment12View.h : CExperiment12View 类的接口
//

#pragma once


class CExperiment12View : public CView
{
protected: // 仅从序列化创建
	CExperiment12View();
	DECLARE_DYNCREATE(CExperiment12View)

// 特性
public:
	CExperiment12Doc* GetDocument() const;

// 操作
public:
	CString name;
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
	virtual ~CExperiment12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMenu();
};

#ifndef _DEBUG  // Experiment12View.cpp 中的调试版本
inline CExperiment12Doc* CExperiment12View::GetDocument() const
   { return reinterpret_cast<CExperiment12Doc*>(m_pDocument); }
#endif

