
// Experiment9View.h : CExperiment9View ��Ľӿ�
//

#pragma once


class CExperiment9View : public CView
{
protected: // �������л�����
	CExperiment9View();
	DECLARE_DYNCREATE(CExperiment9View)

// ����
public:
	CExperiment9Doc* GetDocument() const;

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
	virtual ~CExperiment9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // Experiment9View.cpp �еĵ��԰汾
inline CExperiment9Doc* CExperiment9View::GetDocument() const
   { return reinterpret_cast<CExperiment9Doc*>(m_pDocument); }
#endif

