
// Experiment15_2View.h : CExperiment15_2View ��Ľӿ�
//

#pragma once


class CExperiment15_2View : public CView
{
protected: // �������л�����
	CExperiment15_2View();
	DECLARE_DYNCREATE(CExperiment15_2View)

// ����
public:
	CExperiment15_2Doc* GetDocument() const;

// ����
public:
	int r;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExperiment15_2View();
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

#ifndef _DEBUG  // Experiment15_2View.cpp �еĵ��԰汾
inline CExperiment15_2Doc* CExperiment15_2View::GetDocument() const
   { return reinterpret_cast<CExperiment15_2Doc*>(m_pDocument); }
#endif

