
// Experiment11_1View.h : CExperiment11_1View ��Ľӿ�
//

#pragma once


class CExperiment11_1View : public CView
{
protected: // �������л�����
	CExperiment11_1View();
	DECLARE_DYNCREATE(CExperiment11_1View)

// ����
public:
	CExperiment11_1Doc* GetDocument() const;

// ����
public:
	CRect rect;
	bool set;
	CPoint p;
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
	virtual ~CExperiment11_1View();
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
};

#ifndef _DEBUG  // Experiment11_1View.cpp �еĵ��԰汾
inline CExperiment11_1Doc* CExperiment11_1View::GetDocument() const
   { return reinterpret_cast<CExperiment11_1Doc*>(m_pDocument); }
#endif

