
// Experiment1_3View.h : CExperiment1_3View ��Ľӿ�
//

#pragma once


class CExperiment1_3View : public CView
{
protected: // �������л�����
	CExperiment1_3View();
	DECLARE_DYNCREATE(CExperiment1_3View)

// ����
public:
	CExperiment1_3Doc* GetDocument() const;

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
	virtual ~CExperiment1_3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Experiment1_3View.cpp �еĵ��԰汾
inline CExperiment1_3Doc* CExperiment1_3View::GetDocument() const
   { return reinterpret_cast<CExperiment1_3Doc*>(m_pDocument); }
#endif

