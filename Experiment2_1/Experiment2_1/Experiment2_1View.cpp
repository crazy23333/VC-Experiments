
// Experiment2_1View.cpp : CExperiment2_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment2_1.h"
#endif

#include "Experiment2_1Doc.h"
#include "Experiment2_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment2_1View

IMPLEMENT_DYNCREATE(CExperiment2_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment2_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CExperiment2_1View 构造/析构

CExperiment2_1View::CExperiment2_1View()
{
	// TODO: 在此处添加构造代码

}

CExperiment2_1View::~CExperiment2_1View()
{
}

BOOL CExperiment2_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment2_1View 绘制

void CExperiment2_1View::OnDraw(CDC* pDC)
{
	CExperiment2_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CString s = _T("我是***");
	int a = 5;
	pDC->TextOutW(200, 200, s);
	CString t;
	t.Format(_T("%d"), a);
	pDC->TextOutW(300, 200, t);
}


// CExperiment2_1View 打印

BOOL CExperiment2_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment2_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment2_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment2_1View 诊断

#ifdef _DEBUG
void CExperiment2_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment2_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment2_1Doc* CExperiment2_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment2_1Doc)));
	return (CExperiment2_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment2_1View 消息处理程序
