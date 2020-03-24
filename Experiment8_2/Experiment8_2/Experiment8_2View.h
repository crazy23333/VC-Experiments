
// Experiment8_2View.h : CExperiment8_2View ��Ľӿ�
//

#pragma once


class CExperiment8_2View : public CView
{
protected: // �������л�����
	CExperiment8_2View();
	DECLARE_DYNCREATE(CExperiment8_2View)

// ����
public:
	CExperiment8_2Doc* GetDocument() const;

// ����
public:
	CRect cr;
	bool line, circle, rect;
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
	virtual ~CExperiment8_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Online();
	afx_msg void Oncircle();
	afx_msg void Onrect();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment8_2View.cpp �еĵ��԰汾
inline CExperiment8_2Doc* CExperiment8_2View::GetDocument() const
   { return reinterpret_cast<CExperiment8_2Doc*>(m_pDocument); }
#endif

