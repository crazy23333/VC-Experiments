
// Experiment6_2View.h : CExperiment6_2View ��Ľӿ�
//

#pragma once


class CExperiment6_2View : public CView
{
protected: // �������л�����
	CExperiment6_2View();
	DECLARE_DYNCREATE(CExperiment6_2View)

// ����
public:
	CExperiment6_2Doc* GetDocument() const;

// ����
public:
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
	virtual ~CExperiment6_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment6_2View.cpp �еĵ��԰汾
inline CExperiment6_2Doc* CExperiment6_2View::GetDocument() const
   { return reinterpret_cast<CExperiment6_2Doc*>(m_pDocument); }
#endif

