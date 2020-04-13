
// Experiment10View.cpp : CExperiment10View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment10.h"
#endif

#include "Experiment10Doc.h"
#include "Experiment10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment10View

IMPLEMENT_DYNCREATE(CExperiment10View, CView)

BEGIN_MESSAGE_MAP(CExperiment10View, CView)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CExperiment10View 构造/析构

CExperiment10View::CExperiment10View()
{
	// TODO: 在此处添加构造代码
	s = "";

}

CExperiment10View::~CExperiment10View()
{
}

BOOL CExperiment10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment10View 绘制

void CExperiment10View::OnDraw(CDC* pDC)
{
	CExperiment10Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect c;
	GetClientRect(&c);
	rect.left = c.left + 200;
	rect.top = c.top + 100;
	rect.right = c.right - 200;
	rect.bottom = c.bottom - 100;
	sp.x = 200;
	sp.y = 100;
	SetCaretPos(sp);
	pDC->Rectangle(rect);
}


// CExperiment10View 诊断

#ifdef _DEBUG
void CExperiment10View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment10View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment10Doc* CExperiment10View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment10Doc)));
	return (CExperiment10Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment10View 消息处理程序


void CExperiment10View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CSize size = dc.GetTextExtent(s);
	if ((size.cx+sp.x)>=rect.right) {
		s.Empty();
		sp.y += tm.tmHeight;
	}
	else if (nChar == 0x0d) {
		s.Empty();
		sp.y += tm.tmHeight;
	}
	else {
		s +=(WCHAR)nChar;
	}

	
	dc.TextOutW(sp.x+1, sp.y+1, s);



	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CExperiment10View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCaretPos(point);
	s.Empty();
	sp = point;

	CView::OnLButtonDown(nFlags, point);
}
