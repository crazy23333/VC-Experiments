
// Experiment5View.h : CExperiment5View ��Ľӿ�
//

#pragma once


class CExperiment5View : public CView
{
protected: // �������л�����
	CExperiment5View();
	DECLARE_DYNCREATE(CExperiment5View)

// ����
public:
	CExperiment5Doc* GetDocument() const;

// ����
public:

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
	virtual ~CExperiment5View();
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

#ifndef _DEBUG  // Experiment5View.cpp �еĵ��԰汾
inline CExperiment5Doc* CExperiment5View::GetDocument() const
   { return reinterpret_cast<CExperiment5Doc*>(m_pDocument); }
#endif

