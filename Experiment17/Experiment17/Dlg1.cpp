// Dlg1.cpp : 实现文件
//

#include "stdafx.h"
#include "Experiment17.h"
#include "Dlg1.h"
#include "afxdialogex.h"


// CDlg1 对话框

IMPLEMENT_DYNAMIC(CDlg1, CDialogEx)

CDlg1::CDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CDlg1::~CDlg1()
{
}

void CDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST9, list);
}


BEGIN_MESSAGE_MAP(CDlg1, CDialogEx)
END_MESSAGE_MAP()


// CDlg1 消息处理程序


BOOL CDlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for (int i = 0; i < str.GetSize(); i++) {
		list.InsertString(-1, str[i]);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
