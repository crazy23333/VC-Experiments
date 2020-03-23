
// Experiment7View.cpp : CExperiment7View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment7.h"
#endif

#include "Experiment7Doc.h"
#include "Experiment7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment7View

IMPLEMENT_DYNCREATE(CExperiment7View, CView)

BEGIN_MESSAGE_MAP(CExperiment7View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CExperiment7View::On32771)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CExperiment7View ����/����

CExperiment7View::CExperiment7View()
{
	// TODO: �ڴ˴���ӹ������
	l = 5;
	x = 0; y = 0; r = 0; g = 0; b = 0;
	set = false; col = false;
}

CExperiment7View::~CExperiment7View()
{
}

BOOL CExperiment7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment7View ����

void CExperiment7View::OnDraw(CDC* pDC)
{
	CExperiment7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CPen pen(PS_SOLID,3,RGB(r, g, b));
	CPen*open = pDC->SelectObject(&pen);
	pDC->Ellipse(cr);
	pDC->SelectObject(open);

}


// CExperiment7View ��ӡ

BOOL CExperiment7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment7View ���

#ifdef _DEBUG
void CExperiment7View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment7Doc* CExperiment7View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment7Doc)));
	return (CExperiment7Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment7View ��Ϣ�������


void CExperiment7View::On32771()
{
	// TODO: �ڴ���������������
	set = true;
	if (set) {
		SetTimer(0, 100, NULL);
		CRect c;
		GetClientRect(&c);
		x = c.right / 2;
		y = c.bottom / 2;
		
		cr.left = x;
		cr.top = y;
		cr.right = x;
		cr.bottom = y;
		
		set = false;
	}
}


void CExperiment7View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cr.left -= l;
	cr.right += l;
	cr.top -= l;
	cr.bottom += l;
	if(!col)
		r+=10;
	if (col)
		r -= 10;
	if (r == 0)
		col = false;
	if (r == 250)
		col = true;
	
	Invalidate();
	CView::OnTimer(nIDEvent);
}
