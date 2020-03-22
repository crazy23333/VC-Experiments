
// Experiment6_1View.cpp : CExperiment6_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment6_1.h"
#endif

#include "Experiment6_1Doc.h"
#include "Experiment6_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment6_1View

IMPLEMENT_DYNCREATE(CExperiment6_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment6_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CExperiment6_1View ����/����

CExperiment6_1View::CExperiment6_1View()
{
	// TODO: �ڴ˴���ӹ������
	count = 0;
	x = 0;
}

CExperiment6_1View::~CExperiment6_1View()
{
}

BOOL CExperiment6_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment6_1View ����

void CExperiment6_1View::OnDraw(CDC* /*pDC*/)
{
	CExperiment6_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment6_1View ��ӡ

BOOL CExperiment6_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment6_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment6_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment6_1View ���

#ifdef _DEBUG
void CExperiment6_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment6_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment6_1Doc* CExperiment6_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment6_1Doc)));
	return (CExperiment6_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment6_1View ��Ϣ�������


void CExperiment6_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	count = 0;
	x = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment6_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int m = count;
	int n = abs(point.x - x)/m;
	CString s;
	s.Format(_T("MouseMove������%d�Σ������ƶ�%d�����ط���һ��"), m, n);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}


void CExperiment6_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	count++;
	CView::OnMouseMove(nFlags, point);
}
