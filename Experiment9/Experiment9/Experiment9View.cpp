
// Experiment9View.cpp : CExperiment9View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &CExperiment9View::OnFileOpen)
END_MESSAGE_MAP()

// CExperiment9View 构造/析构

CExperiment9View::CExperiment9View()
{
	// TODO: 在此处添加构造代码

}

CExperiment9View::~CExperiment9View()
{
}

BOOL CExperiment9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment9View 绘制

void CExperiment9View::OnDraw(CDC* /*pDC*/)
{
	CExperiment9Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment9View 打印

BOOL CExperiment9View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment9View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment9View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment9View 诊断

#ifdef _DEBUG
void CExperiment9View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment9View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment9Doc* CExperiment9View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment9Doc)));
	return (CExperiment9Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment9View 消息处理程序


void CExperiment9View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
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
