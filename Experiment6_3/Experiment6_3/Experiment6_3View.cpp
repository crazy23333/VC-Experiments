
// Experiment6_3View.cpp : CExperiment6_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment6_3.h"
#endif

#include "Experiment6_3Doc.h"
#include "Experiment6_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment6_3View

IMPLEMENT_DYNCREATE(CExperiment6_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment6_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CExperiment6_3View ����/����

CExperiment6_3View::CExperiment6_3View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;	a = true;	cr.left = 500;	cr.top = 0;	cr.right = 520;	cr.bottom = 20;

	
}

CExperiment6_3View::~CExperiment6_3View()
{
}

BOOL CExperiment6_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment6_3View ����

void CExperiment6_3View::OnDraw(CDC* pDC)
{
	CExperiment6_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect c;
	GetClientRect(&c);
	bottom = c.bottom;
	if (set) {		SetTimer(0, 50, NULL);		set = false;	}
	if (cr.bottom > bottom) {		a = false;	}
	if (!a && cr.bottom <= 0) {
		a = true;
	}
	
	pDC->Ellipse(cr);
}


// CExperiment6_3View ��ӡ

BOOL CExperiment6_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment6_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment6_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment6_3View ���

#ifdef _DEBUG
void CExperiment6_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment6_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment6_3Doc* CExperiment6_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment6_3Doc)));
	return (CExperiment6_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment6_3View ��Ϣ�������


void CExperiment6_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (a) {
		cr.top += 10;		cr.bottom += 10;	}	else {		cr.top -= 10;		cr.bottom -= 10;	}	Invalidate();
	CView::OnTimer(nIDEvent);
}
