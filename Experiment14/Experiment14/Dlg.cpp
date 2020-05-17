// Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Experiment14.h"
#include "Dlg.h"
#include "afxdialogex.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


// Dlg 对话框

IMPLEMENT_DYNAMIC(Dlg, CDialogEx)

Dlg::Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Dlg::~Dlg()
{
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Dlg 消息处理程序


void Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ifstream ifs("C:\\Users\\chen\\Desktop\\abc.txt");
	string s;
	ifs >> s;
	CString str(s.c_str());
	CImage img;
	img.Load(str);
	CDC *pDC = GetDlgItem(IDC_STATIC)->GetDC();
	img.Draw(pDC->m_hDC, 0, 0, img.GetWidth(), img.GetHeight());
}
