
// Experiment11_4View.h : CExperiment11_4View ��Ľӿ�
//

#pragma once


class CExperiment11_4View : public CView
{
protected: // �������л�����
	CExperiment11_4View();
	DECLARE_DYNCREATE(CExperiment11_4View)

// ����
public:
	CExperiment11_4Doc* GetDocument() const;

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
	virtual ~CExperiment11_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onshowtext();
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Experiment11_4View.cpp �еĵ��԰汾
inline CExperiment11_4Doc* CExperiment11_4View::GetDocument() const
   { return reinterpret_cast<CExperiment11_4Doc*>(m_pDocument); }
#endif

