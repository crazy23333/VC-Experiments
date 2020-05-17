
// Experiment15_2View.cpp : CExperiment15_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment15_2.h"
#endif

#include "Experiment15_2Doc.h"
#include "Experiment15_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment15_2View

IMPLEMENT_DYNCREATE(CExperiment15_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment15_2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CExperiment15_2View ����/����

CExperiment15_2View::CExperiment15_2View()
{
	// TODO: �ڴ˴���ӹ������
	r = 0;

}

CExperiment15_2View::~CExperiment15_2View()
{
}

BOOL CExperiment15_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment15_2View ����

void CExperiment15_2View::OnDraw(CDC* pDC)
{
	CExperiment15_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < pDoc->n; i++) {
		CBrush br(pDoc->color[i]);
		CBrush*pbr = pDC->SelectObject(&br);
		pDC->Ellipse(pDoc->cr[i]);
		pDC->SelectObject(pbr);
	}
}


// CExperiment15_2View ���

#ifdef _DEBUG
void CExperiment15_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment15_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment15_2Doc* CExperiment15_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment15_2Doc)));
	return (CExperiment15_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment15_2View ��Ϣ�������


void CExperiment15_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment15_2Doc* pDoc = GetDocument();
	pDoc->cr[pDoc->n].left = point.x;
	pDoc->cr[pDoc->n].top = point.y;
	pDoc->color[pDoc->n] = RGB(r, 0, 0);
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment15_2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment15_2Doc* pDoc = GetDocument();
	pDoc->cr[pDoc->n].right = point.x;
	pDoc->cr[pDoc->n].bottom = point.y;
	pDoc->color[pDoc->n] = RGB(r, 0, 0);
	pDoc->n++;
	Invalidate();


	CView::OnLButtonUp(nFlags, point);
}


void CExperiment15_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment15_2Doc* pDoc = GetDocument();
	pDoc->cr[pDoc->n].right = point.x;
	pDoc->cr[pDoc->n].bottom = point.y;
	r++;
	pDoc->color[pDoc->n] = RGB(r, 0, 0);
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}
