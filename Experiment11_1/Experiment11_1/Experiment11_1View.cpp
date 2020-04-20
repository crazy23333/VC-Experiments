
// Experiment11_1View.cpp : CExperiment11_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment11_1.h"
#endif

#include "Experiment11_1Doc.h"
#include "Experiment11_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment11_1View

IMPLEMENT_DYNCREATE(CExperiment11_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment11_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CExperiment11_1View ����/����

CExperiment11_1View::CExperiment11_1View()
{
	// TODO: �ڴ˴���ӹ������
	rect.top = 10;
	rect.left = 10;
	rect.bottom = 150;
	rect.right = 300;

	set = false;
	p = 0;
}

CExperiment11_1View::~CExperiment11_1View()
{
}

BOOL CExperiment11_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment11_1View ����

void CExperiment11_1View::OnDraw(CDC* pDC)
{
	CExperiment11_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(rect);
}


// CExperiment11_1View ��ӡ

BOOL CExperiment11_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment11_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment11_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment11_1View ���

#ifdef _DEBUG
void CExperiment11_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment11_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment11_1Doc* CExperiment11_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment11_1Doc)));
	return (CExperiment11_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment11_1View ��Ϣ�������


void CExperiment11_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point.x >= rect.left && point.x <= rect.right && point.y >= rect.top && point.y <= rect.bottom) {
		set = true;
		p = point;
	}
	else
		set = false;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment11_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set) {
		rect.top += (point.y - p.y);
		rect.bottom += (point.y - p.y);
		rect.left += (point.x - p.x);
		rect.right += (point.x - p.x);
	}
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
