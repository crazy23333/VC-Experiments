
// Experiment6_1View.h : CExperiment6_1View ��Ľӿ�
//

#pragma once


class CExperiment6_1View : public CView
{
protected: // �������л�����
	CExperiment6_1View();
	DECLARE_DYNCREATE(CExperiment6_1View)

// ����
public:
	CExperiment6_1Doc* GetDocument() const;

// ����
public:
	int count,x;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CExperiment6_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment6_1View.cpp �еĵ��԰汾
inline CExperiment6_1Doc* CExperiment6_1View::GetDocument() const
   { return reinterpret_cast<CExperiment6_1Doc*>(m_pDocument); }
#endif

