
// Experiment3_2View.h : CExperiment3_2View ��Ľӿ�
//

#pragma once


class CExperiment3_2View : public CView
{
protected: // �������л�����
	CExperiment3_2View();
	DECLARE_DYNCREATE(CExperiment3_2View)

// ����
public:
	CExperiment3_2Doc* GetDocument() const;

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
	virtual ~CExperiment3_2View();
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

#ifndef _DEBUG  // Experiment3_2View.cpp �еĵ��԰汾
inline CExperiment3_2Doc* CExperiment3_2View::GetDocument() const
   { return reinterpret_cast<CExperiment3_2Doc*>(m_pDocument); }
#endif

