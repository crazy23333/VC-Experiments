
// Experiment15_2Doc.cpp : CExperiment15_2Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Experiment15_2.h"
#endif

#include "Experiment15_2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CExperiment15_2Doc

IMPLEMENT_DYNCREATE(CExperiment15_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CExperiment15_2Doc, CDocument)
END_MESSAGE_MAP()


// CExperiment15_2Doc ����/����

CExperiment15_2Doc::CExperiment15_2Doc()
{
	// TODO: �ڴ����һ���Թ������
	cr.SetSize(100);
	color.SetSize(100);
	n = 0;

}

CExperiment15_2Doc::~CExperiment15_2Doc()
{
}

BOOL CExperiment15_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CExperiment15_2Doc ���л�

void CExperiment15_2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar << n;
		for (int i = 0; i < n; i++) {
			ar << cr[i];
		}
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar >> n;
		for (int i = 0; i < n; i++) {
			ar >> cr[i];
		}

	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CExperiment15_2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CExperiment15_2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CExperiment15_2Doc::SetSearchContent(const CString& value)
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

// CExperiment15_2Doc ���

#ifdef _DEBUG
void CExperiment15_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExperiment15_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExperiment15_2Doc ����
