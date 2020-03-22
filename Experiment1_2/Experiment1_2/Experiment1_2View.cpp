
// Experiment1_2View.cpp : CExperiment1_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment1_2.h"
#endif

#include "Experiment1_2Doc.h"
#include "Experiment1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment1_2View

IMPLEMENT_DYNCREATE(CExperiment1_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment1_2View 构造/析构

CExperiment1_2View::CExperiment1_2View()
{
	// TODO: 在此处添加构造代码
	cr.SetSize(100);
}

CExperiment1_2View::~CExperiment1_2View()
{
}

BOOL CExperiment1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment1_2View 绘制

void CExperiment1_2View::OnDraw(CDC* pDC)
{
	CExperiment1_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	for (int i = 0; i < cr.GetSize(); i++) {
		pDC->Ellipse(cr.GetAt(i));
	}
}


// CExperiment1_2View 打印

BOOL CExperiment1_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment1_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment1_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment1_2View 诊断

#ifdef _DEBUG
void CExperiment1_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_2Doc* CExperiment1_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_2Doc)));
	return (CExperiment1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment1_2View 消息处理程序


void CExperiment1_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int r = rand() % 50 + 5;
	CRect c(point.x - r, point.y - r, point.x + r, point.y + r);
	cr.Add(c);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
