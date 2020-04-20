
// Experiment12View.cpp : CExperiment12View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment12.h"
#endif

#include "Experiment12Doc.h"
#include "Experiment12View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment12View

IMPLEMENT_DYNCREATE(CExperiment12View, CView)

BEGIN_MESSAGE_MAP(CExperiment12View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_Menu, &CExperiment12View::OnMenu)
END_MESSAGE_MAP()

// CExperiment12View ����/����

CExperiment12View::CExperiment12View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment12View::~CExperiment12View()
{
}

BOOL CExperiment12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment12View ����

void CExperiment12View::OnDraw(CDC* pDC)
{
	CExperiment12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOutW(100, 100, name);
}


// CExperiment12View ��ӡ

BOOL CExperiment12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment12View ���

#ifdef _DEBUG
void CExperiment12View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment12Doc* CExperiment12View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment12Doc)));
	return (CExperiment12Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment12View ��Ϣ�������


void CExperiment12View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFileDialog cfd(true);
	int t = cfd.DoModal();
	if (t == IDOK) {
		name=cfd.GetFileName();
		Invalidate();
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CExperiment12View::OnMenu()
{
	// TODO: �ڴ���������������
	Dlg dlg;
	dlg.n = name;
	int t = dlg.DoModal();
}
