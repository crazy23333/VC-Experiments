
// Experiment13_2View.cpp : CExperiment13_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment13_2.h"
#endif

#include "Experiment13_2Doc.h"
#include "Experiment13_2View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment13_2View

IMPLEMENT_DYNCREATE(CExperiment13_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment13_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_draw, &CExperiment13_2View::Ondraw)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_change, &CExperiment13_2View::Onchange)
END_MESSAGE_MAP()

// CExperiment13_2View ����/����

CExperiment13_2View::CExperiment13_2View()
{
	// TODO: �ڴ˴���ӹ������
	cr.SetSize(50);
	color.SetSize(50);
	set = false;
	n = 0;
	select = 0;
	rect.left = 0;
	rect.right = 0;
	rect.top = 0;
	rect.bottom = 0;
}

CExperiment13_2View::~CExperiment13_2View()
{
}

BOOL CExperiment13_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment13_2View ����

void CExperiment13_2View::OnDraw(CDC* pDC)
{
	CExperiment13_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < cr.GetSize(); i++) {
		CBrush brush(color[i]);
		CBrush*oldbrush = pDC->SelectObject(&brush);
		pDC->Ellipse(cr[i]);
		pDC->SelectObject(oldbrush);
	}
	CPen pen(PS_DASH, 2, RGB(0, 0, 0));
	pDC->SelectObject(&pen);
	pDC->SelectStockObject(NULL_BRUSH);
	pDC->Rectangle(rect);
}


// CExperiment13_2View ��ӡ

BOOL CExperiment13_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment13_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment13_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment13_2View ���

#ifdef _DEBUG
void CExperiment13_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment13_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment13_2Doc* CExperiment13_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment13_2Doc)));
	return (CExperiment13_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment13_2View ��Ϣ�������


void CExperiment13_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = true;
	r = rand() % 255;
	g = rand() % 255;
	b = rand() % 255;
	cr[n].left = point.x;
	cr[n].top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment13_2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	set = false;
	cr[n].right = point.x;
	cr[n].bottom = point.y;
	color[n] = RGB(r % 255, g % 255, b % 255);
	n++;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CExperiment13_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (set) {
		cr[n].right = point.x;
		cr[n].bottom = point.y;
		color[n] = RGB(r % 255, g % 255, b % 255);
		r++;
		g++;
		b++;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}


void CExperiment13_2View::Ondraw()
{
	// TODO: �ڴ���������������
	Dlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK) {
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		color[n] = RGB(r % 255, g % 255, b % 255);
		cr[n].left = dlg.x-(dlg.width/2);
		cr[n].top = dlg.y-(dlg.height/2);
		cr[n].right = dlg.x + (dlg.width / 2);
		cr[n].bottom = dlg.y + (dlg.height / 2);
		n++;
		Invalidate();

	}
}


void CExperiment13_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	for (int i = n-1; i >= 0; i--) {
		if (point.x >= cr[i].left && point.x <= cr[i].right && point.y >= cr[i].top && point.y <= cr[i].bottom) {
			rect.left = cr[i].left;
			rect.right = cr[i].right;
			rect.top = cr[i].top;
			rect.bottom = cr[i].bottom;
			select = i;
			Invalidate();
			break;
		}
	}

	CView::OnRButtonDown(nFlags, point);
}


void CExperiment13_2View::Onchange()
{
	// TODO: �ڴ���������������
	CColorDialog dlg;
	int t = dlg.DoModal();
	if (t == IDOK) {
		color[select] = dlg.GetColor();
		Invalidate();

	}
}
