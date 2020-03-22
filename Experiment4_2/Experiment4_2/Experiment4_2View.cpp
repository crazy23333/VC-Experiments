
// Experiment4_2View.cpp : CExperiment4_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment4_2.h"
#endif

#include "Experiment4_2Doc.h"
#include "Experiment4_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment4_2View

IMPLEMENT_DYNCREATE(CExperiment4_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment4_2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment4_2View 构造/析构

CExperiment4_2View::CExperiment4_2View()
{
	// TODO: 在此处添加构造代码

}

CExperiment4_2View::~CExperiment4_2View()
{
}

BOOL CExperiment4_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment4_2View 绘制

void CExperiment4_2View::OnDraw(CDC* /*pDC*/)
{
	CExperiment4_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment4_2View 打印

BOOL CExperiment4_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment4_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment4_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment4_2View 诊断

#ifdef _DEBUG
void CExperiment4_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment4_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment4_2Doc* CExperiment4_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment4_2Doc)));
	return (CExperiment4_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment4_2View 消息处理程序


void CExperiment4_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CExperiment4_2Doc* pDoc = GetDocument();
	CString s;
	s.Format(_T("A+B=%d"), pDoc->A + pDoc->B);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
