
// Experiment11_2View.cpp : CExperiment11_2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment11_2.h"
#endif

#include "Experiment11_2Doc.h"
#include "Experiment11_2View.h"
#include "MyDLg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment11_2View

IMPLEMENT_DYNCREATE(CExperiment11_2View, CView)

BEGIN_MESSAGE_MAP(CExperiment11_2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_11_add, &CExperiment11_2View::On11add)
END_MESSAGE_MAP()

// CExperiment11_2View 构造/析构

CExperiment11_2View::CExperiment11_2View()
{
	// TODO: 在此处添加构造代码

}

CExperiment11_2View::~CExperiment11_2View()
{
}

BOOL CExperiment11_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment11_2View 绘制

void CExperiment11_2View::OnDraw(CDC* /*pDC*/)
{
	CExperiment11_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment11_2View 打印

BOOL CExperiment11_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment11_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment11_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment11_2View 诊断

#ifdef _DEBUG
void CExperiment11_2View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment11_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment11_2Doc* CExperiment11_2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment11_2Doc)));
	return (CExperiment11_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment11_2View 消息处理程序


void CExperiment11_2View::On11add()
{
	// TODO: 在此添加命令处理程序代码
	MyDLg dlg;
	CClientDC dc(this);
	CString s;
	int r = dlg.DoModal();
	if (r == IDOK) {
		int A, B,C;
		A = dlg.a;
		B = dlg.b;
		C = A + B;
		s.Format(_T("%d"),C);
		dc.TextOutW( 100, 100,s);
	}
}
