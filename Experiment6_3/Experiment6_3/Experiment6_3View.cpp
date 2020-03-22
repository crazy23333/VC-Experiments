
// Experiment6_3View.cpp : CExperiment6_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment6_3.h"
#endif

#include "Experiment6_3Doc.h"
#include "Experiment6_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment6_3View

IMPLEMENT_DYNCREATE(CExperiment6_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment6_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CExperiment6_3View 构造/析构

CExperiment6_3View::CExperiment6_3View()
{
	// TODO: 在此处添加构造代码
	set = true;	a = true;	cr.left = 500;	cr.top = 0;	cr.right = 520;	cr.bottom = 20;

	
}

CExperiment6_3View::~CExperiment6_3View()
{
}

BOOL CExperiment6_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment6_3View 绘制

void CExperiment6_3View::OnDraw(CDC* pDC)
{
	CExperiment6_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect c;
	GetClientRect(&c);
	bottom = c.bottom;
	if (set) {		SetTimer(0, 50, NULL);		set = false;	}
	if (cr.bottom > bottom) {		a = false;	}
	if (!a && cr.bottom <= 0) {
		a = true;
	}
	
	pDC->Ellipse(cr);
}


// CExperiment6_3View 打印

BOOL CExperiment6_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment6_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment6_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment6_3View 诊断

#ifdef _DEBUG
void CExperiment6_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment6_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment6_3Doc* CExperiment6_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment6_3Doc)));
	return (CExperiment6_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment6_3View 消息处理程序


void CExperiment6_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (a) {
		cr.top += 10;		cr.bottom += 10;	}	else {		cr.top -= 10;		cr.bottom -= 10;	}	Invalidate();
	CView::OnTimer(nIDEvent);
}
