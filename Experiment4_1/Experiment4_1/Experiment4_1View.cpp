
// Experiment4_1View.cpp : CExperiment4_1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment4_1.h"
#endif

#include "Experiment4_1Doc.h"
#include "Experiment4_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment4_1View

IMPLEMENT_DYNCREATE(CExperiment4_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment4_1View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CExperiment4_1View ����/����

CExperiment4_1View::CExperiment4_1View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment4_1View::~CExperiment4_1View()
{
}

BOOL CExperiment4_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment4_1View ����

void CExperiment4_1View::OnDraw(CDC* /*pDC*/)
{
	CExperiment4_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment4_1View ��ӡ

BOOL CExperiment4_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment4_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment4_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment4_1View ���

#ifdef _DEBUG
void CExperiment4_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment4_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment4_1Doc* CExperiment4_1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment4_1Doc)));
	return (CExperiment4_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment4_1View ��Ϣ�������


void CExperiment4_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s=_T("�����������");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);

	CView::OnLButtonDown(nFlags, point);
}


void CExperiment4_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString s = _T("�������̧��");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
