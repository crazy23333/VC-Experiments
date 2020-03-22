
// Experiment4_3View.cpp : CExperiment4_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment4_3.h"
#endif

#include "Experiment4_3Doc.h"
#include "Experiment4_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment4_3View

IMPLEMENT_DYNCREATE(CExperiment4_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment4_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment4_3View ����/����

CExperiment4_3View::CExperiment4_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment4_3View::~CExperiment4_3View()
{
}

BOOL CExperiment4_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment4_3View ����

void CExperiment4_3View::OnDraw(CDC* pDC)
{
	CExperiment4_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(pDoc->Acr);
	pDC->Rectangle(pDoc->Bcr);
	pDC->Rectangle(pDoc->Ccr);

	pDC->TextOutW(300, 300, pDoc->A);
	pDC->TextOutW(600, 300, pDoc->B);
	pDC->TextOutW(900, 300, pDoc->C);

}


// CExperiment4_3View ��ӡ

BOOL CExperiment4_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment4_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment4_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment4_3View ���

#ifdef _DEBUG
void CExperiment4_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment4_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment4_3Doc* CExperiment4_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment4_3Doc)));
	return (CExperiment4_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment4_3View ��Ϣ�������


void CExperiment4_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s;
	CClientDC dc(this);
	CExperiment4_3Doc* pDoc = GetDocument();

	if (pDoc->Acr.PtInRect(point)) {
		pDoc->a = rand();
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (pDoc->Bcr.PtInRect(point)) {
		pDoc->b = rand();
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (pDoc->Ccr.PtInRect(point)) {
		s.Format(_T("%d"), pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else{
		s=_T("�����Ч");
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnLButtonDown(nFlags, point);
}
