
// Experiment11_2View.h : CExperiment11_2View 类的接口
//

#pragma once


class CExperiment11_2View : public CView
{
protected: // 仅从序列化创建
	CExperiment11_2View();
	DECLARE_DYNCREATE(CExperiment11_2View)

// 特性
public:
	CExperiment11_2Doc* GetDocument() const;

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
	virtual ~CExperiment11_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On11add();
};

#ifndef _DEBUG  // Experiment11_2View.cpp 中的调试版本
inline CExperiment11_2Doc* CExperiment11_2View::GetDocument() const
   { return reinterpret_cast<CExperiment11_2Doc*>(m_pDocument); }
#endif

