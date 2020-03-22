
// Experiment1_2View.cpp : CExperiment1_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment1_2.h"
#endif

#include "Experiment1_2Doc.h"
#include "Experiment1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment1_2View

IMPLEMENT_DYNCREATE(CExperiment1_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment1_2View ����/����

CExperiment1_2View::CExperiment1_2View()
{
	// TODO: �ڴ˴���ӹ������
	cr.SetSize(100);
}

CExperiment1_2View::~CExperiment1_2View()
{
}

BOOL CExperiment1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment1_2View ����

void CExperiment1_2View::OnDraw(CDC* pDC)
{
	CExperiment1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < cr.GetSize(); i++) {
		pDC->Ellipse(cr.GetAt(i));
	}
}


// CExperiment1_2View ��ӡ

BOOL CExperiment1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment1_2View ���

#ifdef _DEBUG
void CExperiment1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_2Doc* CExperiment1_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_2Doc)));
	return (CExperiment1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment1_2View ��Ϣ�������


void CExperiment1_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r = rand() % 50 + 5;
	CRect c(point.x - r, point.y - r, point.x + r, point.y + r);
	cr.Add(c);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
