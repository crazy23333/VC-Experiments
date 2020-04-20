
// Experiment11_3View.cpp : CExperiment11_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment11_3.h"
#endif

#include "Experiment11_3Doc.h"
#include "Experiment11_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment11_3View

IMPLEMENT_DYNCREATE(CExperiment11_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment11_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CExperiment11_3View 构造/析构

CExperiment11_3View::CExperiment11_3View()
{
	// TODO: 在此处添加构造代码
	r = 5;
	cr.left = 0;
	cr.top = 0;
	cr.right = 50;
	cr.bottom = 50;
	set1 = false;
	set2 = false;

}

CExperiment11_3View::~CExperiment11_3View()
{
}

BOOL CExperiment11_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment11_3View 绘制

void CExperiment11_3View::OnDraw(CDC* pDC)
{
	CExperiment11_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (set1) {
		SetTimer(0,1,NULL);
	}
	// TODO: 在此处为本机数据添加绘制代码
	pDC->Ellipse(cr);
}


// CExperiment11_3View 打印

BOOL CExperiment11_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment11_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment11_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment11_3View 诊断

#ifdef _DEBUG
void CExperiment11_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment11_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment11_3Doc* CExperiment11_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment11_3Doc)));
	return (CExperiment11_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment11_3View 消息处理程序


void CExperiment11_3View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect c;
	GetClientRect(&c);
	if (!set2) {
		cr.left += r;
		cr.right += r;
		Invalidate();
		if (cr.right >= c.right)
			set2 = true;
	}
	if(set2){
		cr.left -= r;
		cr.right -= r;
		Invalidate();
		if (cr.left <= c.left)
			set2 = false;
	}
	CView::OnTimer(nIDEvent);
}

void CExperiment11_3View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set1 = false;
	KillTimer(0);
	Invalidate();
	CView::OnLButtonDblClk(nFlags, point);
}
void CExperiment11_3View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	set1 = true;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}