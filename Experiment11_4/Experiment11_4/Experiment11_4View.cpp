
// Experiment11_4View.cpp : CExperiment11_4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment11_4.h"
#endif

#include "Experiment11_4Doc.h"
#include "Experiment11_4View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment11_4View

IMPLEMENT_DYNCREATE(CExperiment11_4View, CView)

BEGIN_MESSAGE_MAP(CExperiment11_4View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_showtext, &CExperiment11_4View::Onshowtext)
END_MESSAGE_MAP()

// CExperiment11_4View ����/����

CExperiment11_4View::CExperiment11_4View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment11_4View::~CExperiment11_4View()
{
}

BOOL CExperiment11_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment11_4View ����

void CExperiment11_4View::OnDraw(CDC* /*pDC*/)
{
	CExperiment11_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment11_4View ��ӡ

BOOL CExperiment11_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment11_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment11_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment11_4View ���

#ifdef _DEBUG
void CExperiment11_4View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment11_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment11_4Doc* CExperiment11_4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment11_4Doc)));
	return (CExperiment11_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment11_4View ��Ϣ�������


void CExperiment11_4View::Onshowtext()
{
	// TODO: �ڴ���������������
	MyDlg dlg;
	int t = dlg.DoModal();
	
}


