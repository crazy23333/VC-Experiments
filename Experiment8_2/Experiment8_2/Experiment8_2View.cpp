
// Experiment8_2View.cpp : CExperiment8_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment8_2.h"
#endif

#include "Experiment8_2Doc.h"
#include "Experiment8_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment8_2View

IMPLEMENT_DYNCREATE(CExperiment8_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment8_2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_line, &CExperiment8_2View::Online)
	ON_COMMAND(ID_circle, &CExperiment8_2View::Oncircle)
	ON_COMMAND(ID_rect, &CExperiment8_2View::Onrect)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CExperiment8_2View 构造/析构

CExperiment8_2View::CExperiment8_2View()
{
	// TODO: 在此处添加构造代码
	cr.top = 0;
	cr.bottom = 0;
	cr.left = 0;
	cr.right = 0;

	line = false;
	circle = false;
	rect = false;
}

CExperiment8_2View::~CExperiment8_2View()
{
}

BOOL CExperiment8_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment8_2View 绘制

void CExperiment8_2View::OnDraw(CDC* pDC)
{
	CExperiment8_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment8_2View 打印

BOOL CExperiment8_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment8_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment8_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment8_2View 诊断

#ifdef _DEBUG
void CExperiment8_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment8_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment8_2Doc* CExperiment8_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment8_2Doc)));
	return (CExperiment8_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment8_2View 消息处理程序


void CExperiment8_2View::Online()
{
	// TODO: 在此添加命令处理程序代码
	line = true;
	circle = false;
	rect = false;

}


void CExperiment8_2View::Oncircle()
{
	// TODO: 在此添加命令处理程序代码
	line = false;
	circle = true;
	rect = false;
}


void CExperiment8_2View::Onrect()
{
	// TODO: 在此添加命令处理程序代码
	line = false;
	circle = false;
	rect = true;
}


void CExperiment8_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cr.left = point.x;
	cr.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment8_2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cr.right = point.x;
	cr.bottom = point.y;
	CClientDC dc(this);
	if (line) {
		dc.MoveTo(cr.left, cr.top);
		dc.LineTo(cr.right,cr.bottom);
	}
	else if (circle) {
		dc.Ellipse(cr);
	}
	else if (rect) {
		dc.Rectangle(cr);
	}
	CView::OnLButtonUp(nFlags, point);
}
