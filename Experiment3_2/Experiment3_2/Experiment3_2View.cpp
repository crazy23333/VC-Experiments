
// Experiment3_2View.cpp : CExperiment3_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment3_2.h"
#endif

#include "Experiment3_2Doc.h"
#include "Experiment3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment3_2View

IMPLEMENT_DYNCREATE(CExperiment3_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment3_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment3_2View ����/����

CExperiment3_2View::CExperiment3_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment3_2View::~CExperiment3_2View()
{
}

BOOL CExperiment3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment3_2View ����

void CExperiment3_2View::OnDraw(CDC* pDC)
{
	CExperiment3_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < pDoc->cr.GetSize(); i++) {
		pDC->Ellipse(pDoc->cr.GetAt(i));
	}
}


// CExperiment3_2View ��ӡ

BOOL CExperiment3_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment3_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment3_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment3_2View ���

#ifdef _DEBUG
void CExperiment3_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment3_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment3_2Doc* CExperiment3_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment3_2Doc)));
	return (CExperiment3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment3_2View ��Ϣ�������


void CExperiment3_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int m = rand() % 50 + 5;
	int n = rand() % 50 + 5;
	CRect c(point.x - m, point.y - n, point.x + m, point.y + n);
	CExperiment3_2Doc* pDoc = GetDocument();
	pDoc->cr.Add(c);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
