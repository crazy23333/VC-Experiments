
// Experiment11_4View.cpp : CExperiment11_4View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment11_4.h"
#endif

#include "Experiment11_4Doc.h"
#include "Experiment11_4View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment11_4View

IMPLEMENT_DYNCREATE(CExperiment11_4View, CView)

BEGIN_MESSAGE_MAP(CExperiment11_4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_showtext, &CExperiment11_4View::Onshowtext)
END_MESSAGE_MAP()

// CExperiment11_4View 构造/析构

CExperiment11_4View::CExperiment11_4View()
{
	// TODO: 在此处添加构造代码

}

CExperiment11_4View::~CExperiment11_4View()
{
}

BOOL CExperiment11_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment11_4View 绘制

void CExperiment11_4View::OnDraw(CDC* /*pDC*/)
{
	CExperiment11_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment11_4View 打印

BOOL CExperiment11_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment11_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment11_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment11_4View 诊断

#ifdef _DEBUG
void CExperiment11_4View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment11_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment11_4Doc* CExperiment11_4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment11_4Doc)));
	return (CExperiment11_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment11_4View 消息处理程序


void CExperiment11_4View::Onshowtext()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	
}


