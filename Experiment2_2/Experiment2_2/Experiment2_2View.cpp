
// Experiment2_2View.cpp : CExperiment2_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment2_2.h"
#endif

#include "Experiment2_2Doc.h"
#include "Experiment2_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment2_2View

IMPLEMENT_DYNCREATE(CExperiment2_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment2_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CExperiment2_2View ����/����

CExperiment2_2View::CExperiment2_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment2_2View::~CExperiment2_2View()
{
}

BOOL CExperiment2_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment2_2View ����

void CExperiment2_2View::OnDraw(CDC* pDC)
{
	CExperiment2_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOutW(200, 200, pDoc->s);
	CString t;
	t.Format(_T("a=%d"), pDoc->a);
	pDC->TextOutW(300, 200, t);
}


// CExperiment2_2View ��ӡ

BOOL CExperiment2_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment2_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment2_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment2_2View ���

#ifdef _DEBUG
void CExperiment2_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment2_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment2_2Doc* CExperiment2_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment2_2Doc)));
	return (CExperiment2_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment2_2View ��Ϣ�������
