
// Experiment8_2View.cpp : CExperiment8_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment8_2.h"
#endif

#include "Experiment8_2Doc.h"
#include "Experiment8_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment8_2View

IMPLEMENT_DYNCREATE(CExperiment8_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment8_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_line, &CExperiment8_2View::Online)
	ON_COMMAND(ID_circle, &CExperiment8_2View::Oncircle)
	ON_COMMAND(ID_rect, &CExperiment8_2View::Onrect)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CExperiment8_2View ����/����

CExperiment8_2View::CExperiment8_2View()
{
	// TODO: �ڴ˴���ӹ������
	cr.top = 0;
	cr.bottom = 0;
	cr.left = 0;
	cr.right = 0;

	line = false;
	circle = false;
	rect = false;
}

CExperiment8_2View::~CExperiment8_2View()
{
}

BOOL CExperiment8_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment8_2View ����

void CExperiment8_2View::OnDraw(CDC* pDC)
{
	CExperiment8_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment8_2View ��ӡ

BOOL CExperiment8_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment8_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment8_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment8_2View ���

#ifdef _DEBUG
void CExperiment8_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment8_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment8_2Doc* CExperiment8_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment8_2Doc)));
	return (CExperiment8_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment8_2View ��Ϣ�������


void CExperiment8_2View::Online()
{
	// TODO: �ڴ���������������
	line = true;
	circle = false;
	rect = false;

}


void CExperiment8_2View::Oncircle()
{
	// TODO: �ڴ���������������
	line = false;
	circle = true;
	rect = false;
}


void CExperiment8_2View::Onrect()
{
	// TODO: �ڴ���������������
	line = false;
	circle = false;
	rect = true;
}


void CExperiment8_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment8_2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cr.right = point.x;
	cr.bottom = point.y;
	CClientDC dc(this);
	if (line) {
		dc.MoveTo(cr.left, cr.top);
		dc.LineTo(cr.right,cr.bottom);
	}
	else if (circle) {
		dc.Ellipse(cr);
	}
	else if (rect) {
		dc.Rectangle(cr);
	}
	CView::OnLButtonUp(nFlags, point);
}
