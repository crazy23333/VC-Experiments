
// Experiment12View.cpp : CExperiment12View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment12.h"
#endif

#include "Experiment12Doc.h"
#include "Experiment12View.h"
#include "Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment12View

IMPLEMENT_DYNCREATE(CExperiment12View, CView)

BEGIN_MESSAGE_MAP(CExperiment12View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_Menu, &CExperiment12View::OnMenu)
END_MESSAGE_MAP()

// CExperiment12View 构造/析构

CExperiment12View::CExperiment12View()
{
	// TODO: 在此处添加构造代码

}

CExperiment12View::~CExperiment12View()
{
}

BOOL CExperiment12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment12View 绘制

void CExperiment12View::OnDraw(CDC* pDC)
{
	CExperiment12Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->TextOutW(100, 100, name);
}


// CExperiment12View 打印

BOOL CExperiment12View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment12View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment12View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment12View 诊断

#ifdef _DEBUG
void CExperiment12View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment12View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment12Doc* CExperiment12View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment12Doc)));
	return (CExperiment12Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment12View 消息处理程序


void CExperiment12View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFileDialog cfd(true);
	int t = cfd.DoModal();
	if (t == IDOK) {
		name=cfd.GetFileName();
		Invalidate();
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void CExperiment12View::OnMenu()
{
	// TODO: 在此添加命令处理程序代码
	Dlg dlg;
	dlg.n = name;
	int t = dlg.DoModal();
}
