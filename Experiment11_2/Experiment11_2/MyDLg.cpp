// MyDLg.cpp : 实现文件
//

#include "stdafx.h"
#include "Experiment11_2.h"
#include "MyDLg.h"
#include "afxdialogex.h"


// MyDLg 对话框

IMPLEMENT_DYNAMIC(MyDLg, CDialogEx)

MyDLg::MyDLg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, a(0)
	, b(0)
{

}

MyDLg::~MyDLg()
{
}

void MyDLg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);
	DDX_Text(pDX, IDC_EDIT2, b);
}


BEGIN_MESSAGE_MAP(MyDLg, CDialogEx)
END_MESSAGE_MAP()


// MyDLg 消息处理程序
