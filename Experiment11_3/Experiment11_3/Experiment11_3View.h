
// Experiment11_3View.h : CExperiment11_3View ��Ľӿ�
//

#pragma once


class CExperiment11_3View : public CView
{
protected: // �������л�����
	CExperiment11_3View();
	DECLARE_DYNCREATE(CExperiment11_3View)

// ����
public:
	CExperiment11_3Doc* GetDocument() const;

// ����
public:
	CRect cr;
	bool set1, set2;
	int r;
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
	virtual ~CExperiment11_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment11_3View.cpp �еĵ��԰汾
inline CExperiment11_3Doc* CExperiment11_3View::GetDocument() const
   { return reinterpret_cast<CExperiment11_3Doc*>(m_pDocument); }
#endif

