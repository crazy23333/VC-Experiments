
// Experiment2_2View.h : CExperiment2_2View ��Ľӿ�
//

#pragma once


class CExperiment2_2View : public CView
{
protected: // �������л�����
	CExperiment2_2View();
	DECLARE_DYNCREATE(CExperiment2_2View)

// ����
public:
	CExperiment2_2Doc* GetDocument() const;

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
	virtual ~CExperiment2_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Experiment2_2View.cpp �еĵ��԰汾
inline CExperiment2_2Doc* CExperiment2_2View::GetDocument() const
   { return reinterpret_cast<CExperiment2_2Doc*>(m_pDocument); }
#endif

