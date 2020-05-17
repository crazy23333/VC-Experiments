
// Experiment13_2View.h : CExperiment13_2View ��Ľӿ�
//

#pragma once


class CExperiment13_2View : public CView
{
protected: // �������л�����
	CExperiment13_2View();
	DECLARE_DYNCREATE(CExperiment13_2View)

// ����
public:
	CExperiment13_2Doc* GetDocument() const;

// ����
public:
	CArray<CRect, CRect&>cr;
	CArray<COLORREF, COLORREF&>color;
	bool set;
	int n,select;
	int r, g, b;
	CRect rect;

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
	virtual ~CExperiment13_2View();
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
	afx_msg void Ondraw();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void Onchange();
};

#ifndef _DEBUG  // Experiment13_2View.cpp �еĵ��԰汾
inline CExperiment13_2Doc* CExperiment13_2View::GetDocument() const
   { return reinterpret_cast<CExperiment13_2Doc*>(m_pDocument); }
#endif

