
// Experiment11_2View.h : CExperiment11_2View ��Ľӿ�
//

#pragma once


class CExperiment11_2View : public CView
{
protected: // �������л�����
	CExperiment11_2View();
	DECLARE_DYNCREATE(CExperiment11_2View)

// ����
public:
	CExperiment11_2Doc* GetDocument() const;

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
	virtual ~CExperiment11_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On11add();
};

#ifndef _DEBUG  // Experiment11_2View.cpp �еĵ��԰汾
inline CExperiment11_2Doc* CExperiment11_2View::GetDocument() const
   { return reinterpret_cast<CExperiment11_2Doc*>(m_pDocument); }
#endif

