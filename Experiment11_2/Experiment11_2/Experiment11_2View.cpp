
// Experiment11_2View.cpp : CExperiment11_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment11_2.h"
#endif

#include "Experiment11_2Doc.h"
#include "Experiment11_2View.h"
#include "MyDLg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment11_2View

IMPLEMENT_DYNCREATE(CExperiment11_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment11_2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_11_add, &CExperiment11_2View::On11add)
END_MESSAGE_MAP()

// CExperiment11_2View ����/����

CExperiment11_2View::CExperiment11_2View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment11_2View::~CExperiment11_2View()
{
}

BOOL CExperiment11_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment11_2View ����

void CExperiment11_2View::OnDraw(CDC* /*pDC*/)
{
	CExperiment11_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment11_2View ��ӡ

BOOL CExperiment11_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment11_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment11_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment11_2View ���

#ifdef _DEBUG
void CExperiment11_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment11_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment11_2Doc* CExperiment11_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment11_2Doc)));
	return (CExperiment11_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment11_2View ��Ϣ�������


void CExperiment11_2View::On11add()
{
	// TODO: �ڴ���������������
	MyDLg dlg;
	CClientDC dc(this);
	CString s;
	int r = dlg.DoModal();
	if (r == IDOK) {
		int A, B,C;
		A = dlg.a;
		B = dlg.b;
		C = A + B;
		s.Format(_T("%d"),C);
		dc.TextOutW( 100, 100,s);
	}
}
