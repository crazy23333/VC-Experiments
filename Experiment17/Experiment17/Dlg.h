#pragma once


// CDlg �Ի���

class CDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg)

public:
	CDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString filename;
	void foo(CImage& img, int &sx, int& sy, int& w, int& h);
	afx_msg void OnPaint();
};
