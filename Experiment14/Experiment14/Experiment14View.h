
// Experiment14View.h : CExperiment14View ��Ľӿ�
//

#pragma once


class CExperiment14View : public CView
{
protected: // �������л�����
	CExperiment14View();
	DECLARE_DYNCREATE(CExperiment14View)

// ����
public:
	CExperiment14Doc* GetDocument() const;

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
	virtual ~CExperiment14View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onselect();
};

#ifndef _DEBUG  // Experiment14View.cpp �еĵ��԰汾
inline CExperiment14Doc* CExperiment14View::GetDocument() const
   { return reinterpret_cast<CExperiment14Doc*>(m_pDocument); }
#endif

