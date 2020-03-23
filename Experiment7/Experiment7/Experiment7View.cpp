
// Experiment7View.cpp : CExperiment7View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment7.h"
#endif

#include "Experiment7Doc.h"
#include "Experiment7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment7View

IMPLEMENT_DYNCREATE(CExperiment7View, CView)

BEGIN_MESSAGE_MAP(CExperiment7View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_32771, &CExperiment7View::On32771)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CExperiment7View 构造/析构

CExperiment7View::CExperiment7View()
{
	// TODO: 在此处添加构造代码
	l = 5;
	x = 0; y = 0; r = 0; g = 0; b = 0;
	set = false; col = false;
}

CExperiment7View::~CExperiment7View()
{
}

BOOL CExperiment7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment7View 绘制

void CExperiment7View::OnDraw(CDC* pDC)
{
	CExperiment7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
	CPen pen(PS_SOLID,3,RGB(r, g, b));
	CPen*open = pDC->SelectObject(&pen);
	pDC->Ellipse(cr);
	pDC->SelectObject(open);

}


// CExperiment7View 打印

BOOL CExperiment7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment7View 诊断

#ifdef _DEBUG
void CExperiment7View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment7Doc* CExperiment7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment7Doc)));
	return (CExperiment7Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment7View 消息处理程序


void CExperiment7View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	set = true;
	if (set) {
		SetTimer(0, 100, NULL);
		CRect c;
		GetClientRect(&c);
		x = c.right / 2;
		y = c.bottom / 2;
		
		cr.left = x;
		cr.top = y;
		cr.right = x;
		cr.bottom = y;
		
		set = false;
	}
}


void CExperiment7View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	cr.left -= l;
	cr.right += l;
	cr.top -= l;
	cr.bottom += l;
	if(!col)
		r+=10;
	if (col)
		r -= 10;
	if (r == 0)
		col = false;
	if (r == 250)
		col = true;
	
	Invalidate();
	CView::OnTimer(nIDEvent);
}
