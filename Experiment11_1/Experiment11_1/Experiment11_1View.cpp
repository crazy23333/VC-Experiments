
// Experiment11_1View.cpp : CExperiment11_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment11_1.h"
#endif

#include "Experiment11_1Doc.h"
#include "Experiment11_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment11_1View

IMPLEMENT_DYNCREATE(CExperiment11_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment11_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CExperiment11_1View 构造/析构

CExperiment11_1View::CExperiment11_1View()
{
	// TODO: 在此处添加构造代码
	rect.top = 10;
	rect.left = 10;
	rect.bottom = 150;
	rect.right = 300;

	set = false;
	p = 0;
}

CExperiment11_1View::~CExperiment11_1View()
{
}

BOOL CExperiment11_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment11_1View 绘制

void CExperiment11_1View::OnDraw(CDC* pDC)
{
	CExperiment11_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(rect);
}


// CExperiment11_1View 打印

BOOL CExperiment11_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment11_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment11_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment11_1View 诊断

#ifdef _DEBUG
void CExperiment11_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment11_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment11_1Doc* CExperiment11_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment11_1Doc)));
	return (CExperiment11_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment11_1View 消息处理程序


void CExperiment11_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (point.x >= rect.left && point.x <= rect.right && point.y >= rect.top && point.y <= rect.bottom) {
		set = true;
		p = point;
	}
	else
		set = false;
	CView::OnLButtonDown(nFlags, point);
}


void CExperiment11_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (set) {
		rect.top += (point.y - p.y);
		rect.bottom += (point.y - p.y);
		rect.left += (point.x - p.x);
		rect.right += (point.x - p.x);
	}
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}
