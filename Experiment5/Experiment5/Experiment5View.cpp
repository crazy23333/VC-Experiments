
// Experiment5View.cpp : CExperiment5View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment5.h"
#endif

#include "Experiment5Doc.h"
#include "Experiment5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment5View

IMPLEMENT_DYNCREATE(CExperiment5View, CView)

BEGIN_MESSAGE_MAP(CExperiment5View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CExperiment5View ����/����

CExperiment5View::CExperiment5View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment5View::~CExperiment5View()
{
}

BOOL CExperiment5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment5View ����

void CExperiment5View::OnDraw(CDC* pDC)
{
	CExperiment5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment5View ��ӡ

BOOL CExperiment5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment5View ���

#ifdef _DEBUG
void CExperiment5View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment5Doc* CExperiment5View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment5Doc)));
	return (CExperiment5Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment5View ��Ϣ�������


void CExperiment5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment5Doc* pDoc = GetDocument();
	pDoc->cr.left = point.x;
	pDoc->cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment5Doc* pDoc = GetDocument();
	pDoc->cr.right = point.x;
	pDoc->cr.bottom = point.y;
	CClientDC dc(this);
	dc.Rectangle(pDoc->cr);
	CView::OnLButtonUp(nFlags, point);
}


void CExperiment5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment5Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->x = point.x;
	pDoc->y = point.y;
	CString s;
	s.Format(_T("(%d,%d)"), pDoc->x, pDoc->y);
	dc.TextOutW(0, 0, s);
	CView::OnMouseMove(nFlags, point);
}
