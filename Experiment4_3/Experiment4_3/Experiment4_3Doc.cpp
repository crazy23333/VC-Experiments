
// Experiment4_3Doc.cpp : CExperiment4_3Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment4_3.h"
#endif

#include "Experiment4_3Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CExperiment4_3Doc

IMPLEMENT_DYNCREATE(CExperiment4_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment4_3Doc, CDocument)
END_MESSAGE_MAP()


// CExperiment4_3Doc ����/����

CExperiment4_3Doc::CExperiment4_3Doc()
{
	// TODO: �ڴ����һ���Թ������
	Acr.left = 200;
	Acr.top = 200;
	Acr.right = 400;
	Acr.bottom = 400;

	Bcr.left = 500;
	Bcr.top = 200;
	Bcr.right = 700;
	Bcr.bottom = 400;

	Ccr.left = 800;
	Ccr.top = 200;
	Ccr.right = 1000;
	Ccr.bottom = 400;

	A = 'A'; B = 'B'; C = 'C';
	a = 0; b = 0;
}

CExperiment4_3Doc::~CExperiment4_3Doc()
{
}

BOOL CExperiment4_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CExperiment4_3Doc ���л�

void CExperiment4_3Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CExperiment4_3Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CExperiment4_3Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CExperiment4_3Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CExperiment4_3Doc ���

#ifdef _DEBUG
void CExperiment4_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment4_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExperiment4_3Doc ����
