
// Experiment8_1View.cpp : CExperiment8_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment8_1.h"
#endif

#include "Experiment8_1Doc.h"
#include "Experiment8_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment8_1View

IMPLEMENT_DYNCREATE(CExperiment8_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment8_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_name, &CExperiment8_1View::Onname)
END_MESSAGE_MAP()

// CExperiment8_1View ����/����

CExperiment8_1View::CExperiment8_1View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;
	m.LoadMappedBitmap(IDB_BITMAP2);
	m.GetBitmap(&BM);
	w = BM.bmWidth;
	h = BM.bmHeight;
}

CExperiment8_1View::~CExperiment8_1View()
{
}

BOOL CExperiment8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment8_1View ����

void CExperiment8_1View::OnDraw(CDC* pDC)
{
	CExperiment8_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC DC;
	DC.CreateCompatibleDC(NULL);
	DC.SelectObject(m);
	pDC->BitBlt(0, 0, w, h, &DC, 0, 0, SRCCOPY);
}


// CExperiment8_1View ��ӡ

BOOL CExperiment8_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment8_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment8_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment8_1View ���

#ifdef _DEBUG
void CExperiment8_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment8_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment8_1Doc* CExperiment8_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment8_1Doc)));
	return (CExperiment8_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment8_1View ��Ϣ�������


void CExperiment8_1View::Onname()
{
	// TODO: �ڴ���������������
	CString s = _T("����ʲô�ĲŲ�������");
	CClientDC dc(this);
	dc.TextOutW(500, 500, s);
}
