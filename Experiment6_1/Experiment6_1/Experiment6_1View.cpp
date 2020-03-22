
// Experiment6_1View.cpp : CExperiment6_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment6_1.h"
#endif

#include "Experiment6_1Doc.h"
#include "Experiment6_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment6_1View

IMPLEMENT_DYNCREATE(CExperiment6_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment6_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CExperiment6_1View 构造/析构

CExperiment6_1View::CExperiment6_1View()
{
	// TODO: 在此处添加构造代码
	count = 0;
	x = 0;
}

CExperiment6_1View::~CExperiment6_1View()
{
}

BOOL CExperiment6_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment6_1View 绘制

void CExperiment6_1View::OnDraw(CDC* /*pDC*/)
{
	CExperiment6_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment6_1View 打印

BOOL CExperiment6_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment6_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment6_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment6_1View 诊断

#ifdef _DEBUG
void CExperiment6_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment6_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment6_1Doc* CExperiment6_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment6_1Doc)));
	return (CExperiment6_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment6_1View 消息处理程序


void CExperiment6_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	count = 0;
	x = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment6_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int m = count;
	int n = abs(point.x - x)/m;
	CString s;
	s.Format(_T("MouseMove发生了%d次，横向移动%d个像素发生一次"), m, n);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}


void CExperiment6_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	count++;
	CView::OnMouseMove(nFlags, point);
}
