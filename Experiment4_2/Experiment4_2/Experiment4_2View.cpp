
// Experiment4_2View.cpp : CExperiment4_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment4_2.h"
#endif

#include "Experiment4_2Doc.h"
#include "Experiment4_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment4_2View

IMPLEMENT_DYNCREATE(CExperiment4_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment4_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment4_2View ����/����

CExperiment4_2View::CExperiment4_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment4_2View::~CExperiment4_2View()
{
}

BOOL CExperiment4_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment4_2View ����

void CExperiment4_2View::OnDraw(CDC* /*pDC*/)
{
	CExperiment4_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment4_2View ��ӡ

BOOL CExperiment4_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment4_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment4_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment4_2View ���

#ifdef _DEBUG
void CExperiment4_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment4_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment4_2Doc* CExperiment4_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment4_2Doc)));
	return (CExperiment4_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment4_2View ��Ϣ�������


void CExperiment4_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment4_2Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("A+B=%d"), pDoc->A + pDoc->B);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
