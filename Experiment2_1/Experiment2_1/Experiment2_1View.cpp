
// Experiment2_1View.cpp : CExperiment2_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment2_1.h"
#endif

#include "Experiment2_1Doc.h"
#include "Experiment2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment2_1View

IMPLEMENT_DYNCREATE(CExperiment2_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment2_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CExperiment2_1View ����/����

CExperiment2_1View::CExperiment2_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment2_1View::~CExperiment2_1View()
{
}

BOOL CExperiment2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment2_1View ����

void CExperiment2_1View::OnDraw(CDC* pDC)
{
	CExperiment2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CString s = _T("����***");
	int a = 5;
	pDC->TextOutW(200, 200, s);
	CString t;
	t.Format(_T("%d"), a);
	pDC->TextOutW(300, 200, t);
}


// CExperiment2_1View ��ӡ

BOOL CExperiment2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment2_1View ���

#ifdef _DEBUG
void CExperiment2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment2_1Doc* CExperiment2_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment2_1Doc)));
	return (CExperiment2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment2_1View ��Ϣ�������
