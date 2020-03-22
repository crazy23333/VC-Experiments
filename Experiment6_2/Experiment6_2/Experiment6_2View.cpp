
// Experiment6_2View.cpp : CExperiment6_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment6_2.h"
#endif

#include "Experiment6_2Doc.h"
#include "Experiment6_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment6_2View

IMPLEMENT_DYNCREATE(CExperiment6_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment6_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment6_2View ����/����

CExperiment6_2View::CExperiment6_2View()
{
	// TODO: �ڴ˴���ӹ������
	rect.left = 500;	rect.top = 200;	rect.right = 800;	rect.bottom = 400;
}

CExperiment6_2View::~CExperiment6_2View()
{
}

BOOL CExperiment6_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment6_2View ����

void CExperiment6_2View::OnDraw(CDC* pDC)
{
	CExperiment6_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(rect);
}


// CExperiment6_2View ��ӡ

BOOL CExperiment6_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment6_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment6_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment6_2View ���

#ifdef _DEBUG
void CExperiment6_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment6_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment6_2Doc* CExperiment6_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment6_2Doc)));
	return (CExperiment6_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment6_2View ��Ϣ�������


void CExperiment6_2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	switch (nChar) {	case VK_UP:		rect.top -= 5;		rect.bottom -= 5;		break;	case VK_DOWN:		rect.top += 5;		rect.bottom += 5;		break;	case VK_LEFT:		rect.left -= 5;		rect.right -= 5;		break;	case VK_RIGHT:		rect.left += 5;		rect.right += 5;		break;	case VK_HOME:		rect.left -= 5;		rect.top -= 5;		break;	case VK_END:		rect.left += 5;		rect.top += 5;		break;	}	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CExperiment6_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	rect.left = 500;	rect.top = 200;	rect.right = 800;	rect.bottom = 400;	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
