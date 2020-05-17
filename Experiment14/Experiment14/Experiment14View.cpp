
// Experiment14View.cpp : CExperiment14View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Experiment14.h"
#endif

#include "Experiment14Doc.h"
#include "Experiment14View.h"

#include "Dlg.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExperiment14View

IMPLEMENT_DYNCREATE(CExperiment14View, CView)

BEGIN_MESSAGE_MAP(CExperiment14View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_select, &CExperiment14View::Onselect)
END_MESSAGE_MAP()

// CExperiment14View 构造/析构

CExperiment14View::CExperiment14View()
{
	// TODO: 在此处添加构造代码

}

CExperiment14View::~CExperiment14View()
{
}

BOOL CExperiment14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CExperiment14View 绘制

void CExperiment14View::OnDraw(CDC* /*pDC*/)
{
	CExperiment14Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CExperiment14View 打印

BOOL CExperiment14View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CExperiment14View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CExperiment14View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CExperiment14View 诊断

#ifdef _DEBUG
void CExperiment14View::AssertValid() const
{
	CView::AssertValid();
}

void CExperiment14View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExperiment14Doc* CExperiment14View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExperiment14Doc)));
	return (CExperiment14Doc*)m_pDocument;
}
#endif //_DEBUG


// CExperiment14View 消息处理程序


void CExperiment14View::Onselect()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	if (r == IDOK) {
		CString fname = cfd.GetPathName();
		ofstream ofs("C:\\Users\\chen\\Desktop\\abc.txt");
		ofs << CT2A(fname.GetString()) << endl;

		
		Dlg dlg;
		dlg.DoModal();
		
		

	}
}
