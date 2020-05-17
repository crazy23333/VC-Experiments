
// Experiment13_1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Experiment13_1.h"
#include "Experiment13_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CExperiment13_1Dlg 对话框



CExperiment13_1Dlg::CExperiment13_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXPERIMENT13_1_DIALOG, pParent)
	, first(0)
	, second(0)
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CExperiment13_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, first);
	DDX_Text(pDX, IDC_EDIT2, second);
	DDX_Text(pDX, IDC_EDIT3, result);
	DDX_Text(pDX, IDC_EDIT3, result);
}

BEGIN_MESSAGE_MAP(CExperiment13_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CExperiment13_1Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &CExperiment13_1Dlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_BUTTON3, &CExperiment13_1Dlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_BUTTON4, &CExperiment13_1Dlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_BUTTON5, &CExperiment13_1Dlg::OnBnClickedSqu)
	ON_BN_CLICKED(IDC_BUTTON6, &CExperiment13_1Dlg::OnBnClickedRec)
	ON_BN_CLICKED(IDC_BUTTON7, &CExperiment13_1Dlg::OnBnClickedEqual)
END_MESSAGE_MAP()


// CExperiment13_1Dlg 消息处理程序

BOOL CExperiment13_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CExperiment13_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CExperiment13_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CExperiment13_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExperiment13_1Dlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	set = 1;
}


void CExperiment13_1Dlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码
	set = 2;
}


void CExperiment13_1Dlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	set = 3;
}


void CExperiment13_1Dlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	set = 4;
}


void CExperiment13_1Dlg::OnBnClickedSqu()
{
	// TODO: 在此添加控件通知处理程序代码
	set = 5;
}


void CExperiment13_1Dlg::OnBnClickedRec()
{
	// TODO: 在此添加控件通知处理程序代码
	set = 6;
}


void CExperiment13_1Dlg::OnBnClickedEqual()
{
	// TODO: 在此添加控件通知处理程序代码
	double m;
	this->UpdateData(true);
	switch (set) {
	case 1 :m = first + second; result.Format(_T("%f"), m); break;
	case 2 :m = first - second; result.Format(_T("%f"), m); break;
	case 3 :m = first * second; result.Format(_T("%f"), m); break;
	case 4 :if (second == 0) {
		result = "除数不能为0"; break;
	}
			else { m = first / second; result.Format(_T("%f"), m); break; }
	case 5 :m = first *first; result.Format(_T("%f"), m); break;
	case 6 :if (first == 0) {
		result = "0"; break;
	}
			else { m = 1 / first; result.Format(_T("%f"), m); break; }
	}
	UpdateData(false);
}
