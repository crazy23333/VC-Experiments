
// Experiment12View.h : CExperiment12View ��Ľӿ�
//

#pragma once


class CExperiment12View : public CView
{
protected: // �������л�����
	CExperiment12View();
	DECLARE_DYNCREATE(CExperiment12View)

// ����
public:
	CExperiment12Doc* GetDocument() const;

// ����
public:
	CString name;
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
	virtual ~CExperiment12View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMenu();
};

#ifndef _DEBUG  // Experiment12View.cpp �еĵ��԰汾
inline CExperiment12Doc* CExperiment12View::GetDocument() const
   { return reinterpret_cast<CExperiment12Doc*>(m_pDocument); }
#endif

