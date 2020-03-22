
// Experiment2_3View.cpp : CExperiment2_3View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment2_3.h"
#endif

#include "Experiment2_3Doc.h"
#include "Experiment2_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment2_3View

IMPLEMENT_DYNCREATE(CExperiment2_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment2_3View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment2_3View ����/����

CExperiment2_3View::CExperiment2_3View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment2_3View::~CExperiment2_3View()
{
}

BOOL CExperiment2_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment2_3View ����

void CExperiment2_3View::OnDraw(CDC* /*pDC*/)
{
	CExperiment2_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment2_3View ��ӡ

BOOL CExperiment2_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment2_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment2_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment2_3View ���

#ifdef _DEBUG
void CExperiment2_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment2_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment2_3Doc* CExperiment2_3View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment2_3Doc)));
	return (CExperiment2_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment2_3View ��Ϣ�������


void CExperiment2_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment2_3Doc* pDoc = GetDocument();
	pDoc->count++;

	CView::OnLButtonDown(nFlags, point);
}


void CExperiment2_3View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CExperiment2_3Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("�ۼƵ��%d��"), pDoc->count);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnRButtonDown(nFlags, point);
}
