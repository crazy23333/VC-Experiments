// Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Experiment12.h"
#include "Dlg.h"
#include "afxdialogex.h"


// Dlg �Ի���

IMPLEMENT_DYNAMIC(Dlg, CDialogEx)

Dlg::Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, n(_T(""))
	, m(_T(""))
{

}

Dlg::~Dlg()
{
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n);
	DDX_LBString(pDX, IDC_LIST1, m);
	DDX_Control(pDX, IDC_LIST1, LBox);
}


BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
END_MESSAGE_MAP()


// Dlg ��Ϣ�������


BOOL Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	LBox.AddString(n);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
