
// Experiment4_2View.h : CExperiment4_2View ��Ľӿ�
//

#pragma once


class CExperiment4_2View : public CView
{
protected: // �������л�����
	CExperiment4_2View();
	DECLARE_DYNCREATE(CExperiment4_2View)

// ����
public:
	CExperiment4_2Doc* GetDocument() const;

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
	virtual ~CExperiment4_2View();
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

#ifndef _DEBUG  // Experiment4_2View.cpp �еĵ��԰汾
inline CExperiment4_2Doc* CExperiment4_2View::GetDocument() const
   { return reinterpret_cast<CExperiment4_2Doc*>(m_pDocument); }
#endif

