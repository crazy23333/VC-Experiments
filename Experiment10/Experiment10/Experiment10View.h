
// Experiment10View.h : CExperiment10View ��Ľӿ�
//

#pragma once


class CExperiment10View : public CView
{
protected: // �������л�����
	CExperiment10View();
	DECLARE_DYNCREATE(CExperiment10View)

// ����
public:
	CExperiment10Doc* GetDocument() const;

// ����
public:
	CString s;
	CPoint sp;
	CRect rect;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CExperiment10View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Experiment10View.cpp �еĵ��԰汾
inline CExperiment10Doc* CExperiment10View::GetDocument() const
   { return reinterpret_cast<CExperiment10Doc*>(m_pDocument); }
#endif

