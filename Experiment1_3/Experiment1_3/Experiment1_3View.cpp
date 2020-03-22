
// Experiment1_3View.cpp : CExperiment1_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment1_3.h"
#endif

#include "Experiment1_3Doc.h"
#include "Experiment1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment1_3View

IMPLEMENT_DYNCREATE(CExperiment1_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CExperiment1_3View ����/����

CExperiment1_3View::CExperiment1_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment1_3View::~CExperiment1_3View()
{
}

BOOL CExperiment1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment1_3View ����

void CExperiment1_3View::OnDraw(CDC* pDC)
{
	CExperiment1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	int color = RGB(rand() % 255, rand() % 255, rand() % 255);
	CBrush br(color);
	CBrush *obr = pDC->SelectObject(&br);
	CRect cr;
	GetClientRect(&cr);
	pDC->Ellipse(cr);

}


// CExperiment1_3View ��ӡ

BOOL CExperiment1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment1_3View ���

#ifdef _DEBUG
void CExperiment1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_3Doc* CExperiment1_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_3Doc)));
	return (CExperiment1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment1_3View ��Ϣ�������
