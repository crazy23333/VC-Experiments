
// Experiment5View.cpp : CExperiment5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment5.h"
#endif

#include "Experiment5Doc.h"
#include "Experiment5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment5View

IMPLEMENT_DYNCREATE(CExperiment5View, CView)

BEGIN_MESSAGE_MAP(CExperiment5View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CExperiment5View 构造/析构

CExperiment5View::CExperiment5View()
{
	// TODO: 在此处添加构造代码

}

CExperiment5View::~CExperiment5View()
{
}

BOOL CExperiment5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment5View 绘制

void CExperiment5View::OnDraw(CDC* pDC)
{
	CExperiment5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment5View 打印

BOOL CExperiment5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment5View 诊断

#ifdef _DEBUG
void CExperiment5View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment5Doc* CExperiment5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment5Doc)));
	return (CExperiment5Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment5View 消息处理程序


void CExperiment5View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExperiment5Doc* pDoc = GetDocument();
	pDoc->cr.left = point.x;
	pDoc->cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment5View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExperiment5Doc* pDoc = GetDocument();
	pDoc->cr.right = point.x;
	pDoc->cr.bottom = point.y;
	CClientDC dc(this);
	dc.Rectangle(pDoc->cr);
	CView::OnLButtonUp(nFlags, point);
}


void CExperiment5View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExperiment5Doc* pDoc = GetDocument();
	CClientDC dc(this);
	pDoc->x = point.x;
	pDoc->y = point.y;
	CString s;
	s.Format(_T("(%d,%d)"), pDoc->x, pDoc->y);
	dc.TextOutW(0, 0, s);
	CView::OnMouseMove(nFlags, point);
}
