
// Experiment1_1View.cpp : CExperiment1_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment1_1.h"
#endif

#include "Experiment1_1Doc.h"
#include "Experiment1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment1_1View

IMPLEMENT_DYNCREATE(CExperiment1_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment1_1View 构造/析构

CExperiment1_1View::CExperiment1_1View()
{
	// TODO: 在此处添加构造代码

}

CExperiment1_1View::~CExperiment1_1View()
{
}

BOOL CExperiment1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment1_1View 绘制

void CExperiment1_1View::OnDraw(CDC* /*pDC*/)
{
	CExperiment1_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment1_1View 打印

BOOL CExperiment1_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment1_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment1_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment1_1View 诊断

#ifdef _DEBUG
void CExperiment1_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_1Doc* CExperiment1_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_1Doc)));
	return (CExperiment1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment1_1View 消息处理程序


void CExperiment1_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 50 + 5;
	CRect cr(point.x - r, point.y - r, point.x + r, point.y + r);
	CClientDC dc(this);
	dc.Ellipse(cr);
	CView::OnLButtonDown(nFlags, point);
}
