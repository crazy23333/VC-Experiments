
// Experiment14View.cpp : CExperiment14View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment14.h"
#endif

#include "Experiment14Doc.h"
#include "Experiment14View.h"

#include "Dlg.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment14View

IMPLEMENT_DYNCREATE(CExperiment14View, CView)

BEGIN_MESSAGE_MAP(CExperiment14View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_select, &CExperiment14View::Onselect)
END_MESSAGE_MAP()

// CExperiment14View ����/����

CExperiment14View::CExperiment14View()
{
	// TODO: �ڴ˴���ӹ������

}

CExperiment14View::~CExperiment14View()
{
}

BOOL CExperiment14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CExperiment14View ����

void CExperiment14View::OnDraw(CDC* /*pDC*/)
{
	CExperiment14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CExperiment14View ��ӡ

BOOL CExperiment14View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CExperiment14View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CExperiment14View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CExperiment14View ���

#ifdef _DEBUG
void CExperiment14View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment14Doc* CExperiment14View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment14Doc)));
	return (CExperiment14Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment14View ��Ϣ�������


void CExperiment14View::Onselect()
{
	// TODO: �ڴ���������������
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		CString fname = cfd.GetPathName();
		ofstream ofs("C:\\Users\\chen\\Desktop\\abc.txt");
		ofs << CT2A(fname.GetString()) << endl;

		
		Dlg dlg;
		dlg.DoModal();
		
		

	}
}
