
// Experiment8_1View.cpp : CExperiment8_1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment8_1.h"
#endif

#include "Experiment8_1Doc.h"
#include "Experiment8_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment8_1View

IMPLEMENT_DYNCREATE(CExperiment8_1View, CView)

BEGIN_MESSAGE_MAP(CExperiment8_1View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_name, &CExperiment8_1View::Onname)
END_MESSAGE_MAP()

// CExperiment8_1View 构造/析构

CExperiment8_1View::CExperiment8_1View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;
	m.LoadMappedBitmap(IDB_BITMAP2);
	m.GetBitmap(&BM);
	w = BM.bmWidth;
	h = BM.bmHeight;
}

CExperiment8_1View::~CExperiment8_1View()
{
}

BOOL CExperiment8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment8_1View 绘制

void CExperiment8_1View::OnDraw(CDC* pDC)
{
	CExperiment8_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CDC DC;
	DC.CreateCompatibleDC(NULL);
	DC.SelectObject(m);
	pDC->BitBlt(0, 0, w, h, &DC, 0, 0, SRCCOPY);
}


// CExperiment8_1View 打印

BOOL CExperiment8_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment8_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment8_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment8_1View 诊断

#ifdef _DEBUG
void CExperiment8_1View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment8_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment8_1Doc* CExperiment8_1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment8_1Doc)));
	return (CExperiment8_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment8_1View 消息处理程序


void CExperiment8_1View::Onname()
{
	// TODO: 在此添加命令处理程序代码
	CString s = _T("名字什么的才不告诉你");
	CClientDC dc(this);
	dc.TextOutW(500, 500, s);
}
