
// Experiment7View.h : CExperiment7View ��Ľӿ�
//

#pragma once


class CExperiment7View : public CView
{
protected: // �������л�����
	CExperiment7View();
	DECLARE_DYNCREATE(CExperiment7View)

// ����
public:
	CExperiment7Doc* GetDocument() const;

// ����
public:
	CRect cr;
	int l, x, y,r,g,b;
	bool set,col;
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
	virtual ~CExperiment7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // Experiment7View.cpp �еĵ��԰汾
inline CExperiment7Doc* CExperiment7View::GetDocument() const
   { return reinterpret_cast<CExperiment7Doc*>(m_pDocument); }
#endif

