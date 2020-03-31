
// Experiment9View.cpp : CExperiment9View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment9.h"
#endif

#include "Experiment9Doc.h"
#include "Experiment9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment9View

IMPLEMENT_DYNCREATE(CExperiment9View, CView)

BEGIN_MESSAGE_MAP(CExperiment9View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CExperiment9View::OnFileOpen)
END_MESSAGE_MAP()

// CExperiment9View ����/����

CExperiment9View::CExperiment9View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment9View::~CExperiment9View()
{
}

BOOL CExperiment9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment9View ����

void CExperiment9View::OnDraw(CDC* /*pDC*/)
{
	CExperiment9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment9View ��ӡ

BOOL CExperiment9View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment9View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment9View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment9View ���

#ifdef _DEBUG
void CExperiment9View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment9Doc* CExperiment9View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment9Doc)));
	return (CExperiment9Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment9View ��Ϣ�������


void CExperiment9View::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	CClientDC dc(this);
	
	if (r == IDOK) {
		CString filename=cfd.GetPathName();
		CImage img;
		img.Load(filename);
		int h, w, sx, sy;
		CRect rect;
		GetClientRect(&rect);

		float rect_ratio = 1.0*rect.Width() / rect.Height();
		float img_ratio = 1.0*img.GetWidth() / img.GetHeight();

		if (rect_ratio > img_ratio) {
			h = rect.Height();
			w = img_ratio*h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else {
			w = rect.Width();
			h = w / img_ratio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}

		
		img.Draw(dc.m_hDC, sx, sy, w, h);
	}
}
