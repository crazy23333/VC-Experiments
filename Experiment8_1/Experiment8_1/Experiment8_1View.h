
// Experiment8_1View.h : CExperiment8_1View ��Ľӿ�
//

#pragma once


class CExperiment8_1View : public CView
{
protected: // �������л�����
	CExperiment8_1View();
	DECLARE_DYNCREATE(CExperiment8_1View)

// ����
public:
	CExperiment8_1Doc* GetDocument() const;

// ����
public:
	CBitmap m;
	int w;
	int h;
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
	virtual ~CExperiment8_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onname();
};

#ifndef _DEBUG  // Experiment8_1View.cpp �еĵ��԰汾
inline CExperiment8_1Doc* CExperiment8_1View::GetDocument() const
   { return reinterpret_cast<CExperiment8_1Doc*>(m_pDocument); }
#endif

