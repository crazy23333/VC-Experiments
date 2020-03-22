
// Experiment6_2View.cpp : CExperiment6_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment6_2.h"
#endif

#include "Experiment6_2Doc.h"
#include "Experiment6_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment6_2View

IMPLEMENT_DYNCREATE(CExperiment6_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment6_2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment6_2View 构造/析构

CExperiment6_2View::CExperiment6_2View()
{
	// TODO: 在此处添加构造代码
	rect.left = 500;	rect.top = 200;	rect.right = 800;	rect.bottom = 400;
}

CExperiment6_2View::~CExperiment6_2View()
{
}

BOOL CExperiment6_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment6_2View 绘制

void CExperiment6_2View::OnDraw(CDC* pDC)
{
	CExperiment6_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(rect);
}


// CExperiment6_2View 打印

BOOL CExperiment6_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment6_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment6_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment6_2View 诊断

#ifdef _DEBUG
void CExperiment6_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment6_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment6_2Doc* CExperiment6_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment6_2Doc)));
	return (CExperiment6_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment6_2View 消息处理程序


void CExperiment6_2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nChar) {	case VK_UP:		rect.top -= 5;		rect.bottom -= 5;		break;	case VK_DOWN:		rect.top += 5;		rect.bottom += 5;		break;	case VK_LEFT:		rect.left -= 5;		rect.right -= 5;		break;	case VK_RIGHT:		rect.left += 5;		rect.right += 5;		break;	case VK_HOME:		rect.left -= 5;		rect.top -= 5;		break;	case VK_END:		rect.left += 5;		rect.top += 5;		break;	}	InvalidateRect(NULL, TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CExperiment6_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	rect.left = 500;	rect.top = 200;	rect.right = 800;	rect.bottom = 400;	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}
