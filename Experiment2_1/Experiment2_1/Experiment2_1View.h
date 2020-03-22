
// Experiment2_1View.h : CExperiment2_1View 类的接口
//

#pragma once


class CExperiment2_1View : public CView
{
protected: // 仅从序列化创建
	CExperiment2_1View();
	DECLARE_DYNCREATE(CExperiment2_1View)

// 特性
public:
	CExperiment2_1Doc* GetDocument() const;

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
	virtual ~CExperiment2_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Experiment2_1View.cpp 中的调试版本
inline CExperiment2_1Doc* CExperiment2_1View::GetDocument() const
   { return reinterpret_cast<CExperiment2_1Doc*>(m_pDocument); }
#endif

