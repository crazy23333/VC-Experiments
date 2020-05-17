
// Experiment14View.h : CExperiment14View 类的接口
//

#pragma once


class CExperiment14View : public CView
{
protected: // 仅从序列化创建
	CExperiment14View();
	DECLARE_DYNCREATE(CExperiment14View)

// 特性
public:
	CExperiment14Doc* GetDocument() const;

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
	virtual ~CExperiment14View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onselect();
};

#ifndef _DEBUG  // Experiment14View.cpp 中的调试版本
inline CExperiment14Doc* CExperiment14View::GetDocument() const
   { return reinterpret_cast<CExperiment14Doc*>(m_pDocument); }
#endif

