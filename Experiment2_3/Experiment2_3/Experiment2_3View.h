
// Experiment2_3View.h : CExperiment2_3View ��Ľӿ�
//

#pragma once


class CExperiment2_3View : public CView
{
protected: // �������л�����
	CExperiment2_3View();
	DECLARE_DYNCREATE(CExperiment2_3View)

// ����
public:
	CExperiment2_3Doc* GetDocument() const;

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
	virtual ~CExperiment2_3View();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment2_3View.cpp �еĵ��԰汾
inline CExperiment2_3Doc* CExperiment2_3View::GetDocument() const
   { return reinterpret_cast<CExperiment2_3Doc*>(m_pDocument); }
#endif

