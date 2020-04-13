
// Experiment10View.cpp : CExperiment10View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment10.h"
#endif

#include "Experiment10Doc.h"
#include "Experiment10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment10View

IMPLEMENT_DYNCREATE(CExperiment10View, CView)

BEGIN_MESSAGE_MAP(CExperiment10View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment10View ����/����

CExperiment10View::CExperiment10View()
{
	// TODO: �ڴ˴���ӹ������
	s = "";

}

CExperiment10View::~CExperiment10View()
{
}

BOOL CExperiment10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment10View ����

void CExperiment10View::OnDraw(CDC* pDC)
{
	CExperiment10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect c;
	GetClientRect(&c);
	rect.left = c.left + 200;
	rect.top = c.top + 100;
	rect.right = c.right - 200;
	rect.bottom = c.bottom - 100;
	sp.x = 200;
	sp.y = 100;
	SetCaretPos(sp);
	pDC->Rectangle(rect);
}


// CExperiment10View ���

#ifdef _DEBUG
void CExperiment10View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment10Doc* CExperiment10View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment10Doc)));
	return (CExperiment10Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment10View ��Ϣ�������


void CExperiment10View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CSize size = dc.GetTextExtent(s);
	if ((size.cx+sp.x)>=rect.right) {
		s.Empty();
		sp.y += tm.tmHeight;
	}
	else if (nChar == 0x0d) {
		s.Empty();
		sp.y += tm.tmHeight;
	}
	else {
		s +=(WCHAR)nChar;
	}

	
	dc.TextOutW(sp.x+1, sp.y+1, s);



	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CExperiment10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCaretPos(point);
	s.Empty();
	sp = point;

	CView::OnLButtonDown(nFlags, point);
}
