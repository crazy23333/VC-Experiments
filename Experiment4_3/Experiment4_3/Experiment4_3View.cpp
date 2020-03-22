
// Experiment4_3View.cpp : CExperiment4_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment4_3.h"
#endif

#include "Experiment4_3Doc.h"
#include "Experiment4_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment4_3View

IMPLEMENT_DYNCREATE(CExperiment4_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment4_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment4_3View 构造/析构

CExperiment4_3View::CExperiment4_3View()
{
	// TODO: 在此处添加构造代码

}

CExperiment4_3View::~CExperiment4_3View()
{
}

BOOL CExperiment4_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment4_3View 绘制

void CExperiment4_3View::OnDraw(CDC* pDC)
{
	CExperiment4_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(pDoc->Acr);
	pDC->Rectangle(pDoc->Bcr);
	pDC->Rectangle(pDoc->Ccr);

	pDC->TextOutW(300, 300, pDoc->A);
	pDC->TextOutW(600, 300, pDoc->B);
	pDC->TextOutW(900, 300, pDoc->C);

}


// CExperiment4_3View 打印

BOOL CExperiment4_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment4_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment4_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment4_3View 诊断

#ifdef _DEBUG
void CExperiment4_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment4_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment4_3Doc* CExperiment4_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment4_3Doc)));
	return (CExperiment4_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment4_3View 消息处理程序


void CExperiment4_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	CClientDC dc(this);
	CExperiment4_3Doc* pDoc = GetDocument();

	if (pDoc->Acr.PtInRect(point)) {
		pDoc->a = rand();
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (pDoc->Bcr.PtInRect(point)) {
		pDoc->b = rand();
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (pDoc->Ccr.PtInRect(point)) {
		s.Format(_T("%d"), pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s);
	}
	else{
		s=_T("点击无效");
		dc.TextOutW(point.x, point.y, s);
	}
	CView::OnLButtonDown(nFlags, point);
}
