
// Experiment6_3View.h : CExperiment6_3View ��Ľӿ�
//

#pragma once


class CExperiment6_3View : public CView
{
protected: // �������л�����
	CExperiment6_3View();
	DECLARE_DYNCREATE(CExperiment6_3View)

// ����
public:
	CExperiment6_3Doc* GetDocument() const;

// ����
public:
	CRect cr;
	bool set,a,b;
	int bottom;
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
	virtual ~CExperiment6_3View();
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
};

#ifndef _DEBUG  // Experiment6_3View.cpp �еĵ��԰汾
inline CExperiment6_3Doc* CExperiment6_3View::GetDocument() const
   { return reinterpret_cast<CExperiment6_3Doc*>(m_pDocument); }
#endif

