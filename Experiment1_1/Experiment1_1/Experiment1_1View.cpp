
// Experiment1_1View.cpp : CExperiment1_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment1_1.h"
#endif

#include "Experiment1_1Doc.h"
#include "Experiment1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment1_1View

IMPLEMENT_DYNCREATE(CExperiment1_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment1_1View ����/����

CExperiment1_1View::CExperiment1_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment1_1View::~CExperiment1_1View()
{
}

BOOL CExperiment1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment1_1View ����

void CExperiment1_1View::OnDraw(CDC* /*pDC*/)
{
	CExperiment1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment1_1View ��ӡ

BOOL CExperiment1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment1_1View ���

#ifdef _DEBUG
void CExperiment1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_1Doc* CExperiment1_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_1Doc)));
	return (CExperiment1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment1_1View ��Ϣ�������


void CExperiment1_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int r = rand() % 50 + 5;
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	CClientDC dc(this);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
