
// Experiment3_1View.cpp : CExperiment3_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment3_1.h"
#endif

#include "Experiment3_1Doc.h"
#include "Experiment3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment3_1View

IMPLEMENT_DYNCREATE(CExperiment3_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment3_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment3_1View ����/����

CExperiment3_1View::CExperiment3_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment3_1View::~CExperiment3_1View()
{
}

BOOL CExperiment3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment3_1View ����

void CExperiment3_1View::OnDraw(CDC* pDC)
{
	CExperiment3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	cr.left = m - r;
	cr.right = m + r;
	cr.top = n - r;
	cr.bottom = n + r;
	pDC->Ellipse(cr);
}


// CExperiment3_1View ��ӡ

BOOL CExperiment3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment3_1View ���

#ifdef _DEBUG
void CExperiment3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment3_1Doc* CExperiment3_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment3_1Doc)));
	return (CExperiment3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment3_1View ��Ϣ�������


void CExperiment3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect c;
	GetClientRect(&c);
	if (c.bottom > c.right)
		r = c.right/2;
	else
		r = c.bottom/2;
	m = c.right / 2;
	n = c.bottom / 2;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
