
// Experiment11_3View.cpp : CExperiment11_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment11_3.h"
#endif

#include "Experiment11_3Doc.h"
#include "Experiment11_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment11_3View

IMPLEMENT_DYNCREATE(CExperiment11_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment11_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CExperiment11_3View ����/����

CExperiment11_3View::CExperiment11_3View()
{
	// TODO: �ڴ˴���ӹ������
	r = 5;
	cr.left = 0;
	cr.top = 0;
	cr.right = 50;
	cr.bottom = 50;
	set1 = false;
	set2 = false;

}

CExperiment11_3View::~CExperiment11_3View()
{
}

BOOL CExperiment11_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment11_3View ����

void CExperiment11_3View::OnDraw(CDC* pDC)
{
	CExperiment11_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set1) {
		SetTimer(0,1,NULL);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Ellipse(cr);
}


// CExperiment11_3View ��ӡ

BOOL CExperiment11_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment11_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment11_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment11_3View ���

#ifdef _DEBUG
void CExperiment11_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment11_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment11_3Doc* CExperiment11_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment11_3Doc)));
	return (CExperiment11_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment11_3View ��Ϣ�������


void CExperiment11_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect c;
	GetClientRect(&c);
	if (!set2) {
		cr.left += r;
		cr.right += r;
		Invalidate();
		if (cr.right >= c.right)
			set2 = true;
	}
	if(set2){
		cr.left -= r;
		cr.right -= r;
		Invalidate();
		if (cr.left <= c.left)
			set2 = false;
	}
	CView::OnTimer(nIDEvent);
}

void CExperiment11_3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set1 = false;
	KillTimer(0);
	Invalidate();
	CView::OnLButtonDblClk(nFlags, point);
}
void CExperiment11_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set1 = true;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}