
// Experiment1_1View.h : CExperiment1_1View ��Ľӿ�
//

#pragma once


class CExperiment1_1View : public CView
{
protected: // �������л�����
	CExperiment1_1View();
	DECLARE_DYNCREATE(CExperiment1_1View)

// ����
public:
	CExperiment1_1Doc* GetDocument() const;

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
	virtual ~CExperiment1_1View();
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
};

#ifndef _DEBUG  // Experiment1_1View.cpp �еĵ��԰汾
inline CExperiment1_1Doc* CExperiment1_1View::GetDocument() const
   { return reinterpret_cast<CExperiment1_1Doc*>(m_pDocument); }
#endif

