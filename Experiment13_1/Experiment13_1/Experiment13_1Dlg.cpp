
// Experiment13_1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Experiment13_1.h"
#include "Experiment13_1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CExperiment13_1Dlg �Ի���



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


// CExperiment13_1Dlg ��Ϣ�������

BOOL CExperiment13_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CExperiment13_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CExperiment13_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExperiment13_1Dlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = 1;
}


void CExperiment13_1Dlg::OnBnClickedSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = 2;
}


void CExperiment13_1Dlg::OnBnClickedMul()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = 3;
}


void CExperiment13_1Dlg::OnBnClickedDiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = 4;
}


void CExperiment13_1Dlg::OnBnClickedSqu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = 5;
}


void CExperiment13_1Dlg::OnBnClickedRec()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	set = 6;
}


void CExperiment13_1Dlg::OnBnClickedEqual()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	double m;
	this->UpdateData(true);
	switch (set) {
	case 1 :m = first + second; result.Format(_T("%f"), m); break;
	case 2 :m = first - second; result.Format(_T("%f"), m); break;
	case 3 :m = first * second; result.Format(_T("%f"), m); break;
	case 4 :if (second == 0) {
		result = "��������Ϊ0"; break;
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
