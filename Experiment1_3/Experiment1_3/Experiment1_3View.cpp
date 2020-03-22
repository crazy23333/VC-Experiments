
// Experiment1_3View.cpp : CExperiment1_3View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment1_3.h"
#endif

#include "Experiment1_3Doc.h"
#include "Experiment1_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment1_3View

IMPLEMENT_DYNCREATE(CExperiment1_3View, CView)

BEGIN_MESSAGE_MAP(CExperiment1_3View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CExperiment1_3View 构造/析构

CExperiment1_3View::CExperiment1_3View()
{
	// TODO: 在此处添加构造代码

}

CExperiment1_3View::~CExperiment1_3View()
{
}

BOOL CExperiment1_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment1_3View 绘制

void CExperiment1_3View::OnDraw(CDC* pDC)
{
	CExperiment1_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int color = RGB(rand() % 255, rand() % 255, rand() % 255);
	CBrush br(color);
	CBrush *obr = pDC->SelectObject(&br);
	CRect cr;
	GetClientRect(&cr);
	pDC->Ellipse(cr);

}


// CExperiment1_3View 打印

BOOL CExperiment1_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment1_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment1_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment1_3View 诊断

#ifdef _DEBUG
void CExperiment1_3View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment1_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment1_3Doc* CExperiment1_3View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment1_3Doc)));
	return (CExperiment1_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment1_3View 消息处理程序
