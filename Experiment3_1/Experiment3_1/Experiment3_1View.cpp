
// Experiment3_1View.cpp : CExperiment3_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment3_1.h"
#endif

#include "Experiment3_1Doc.h"
#include "Experiment3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment3_1View

IMPLEMENT_DYNCREATE(CExperiment3_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment3_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment3_1View 构造/析构

CExperiment3_1View::CExperiment3_1View()
{
	// TODO: 在此处添加构造代码

}

CExperiment3_1View::~CExperiment3_1View()
{
}

BOOL CExperiment3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment3_1View 绘制

void CExperiment3_1View::OnDraw(CDC* pDC)
{
	CExperiment3_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	cr.left = m - r;
	cr.right = m + r;
	cr.top = n - r;
	cr.bottom = n + r;
	pDC->Ellipse(cr);
}


// CExperiment3_1View 打印

BOOL CExperiment3_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment3_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment3_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment3_1View 诊断

#ifdef _DEBUG
void CExperiment3_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment3_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment3_1Doc* CExperiment3_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment3_1Doc)));
	return (CExperiment3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment3_1View 消息处理程序


void CExperiment3_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect c;
	GetClientRect(&c);
	if (c.bottom > c.right)
		r = c.right/2;
	else
		r = c.bottom/2;
	m = c.right / 2;
	n = c.bottom / 2;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
