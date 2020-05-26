#pragma once


// CDlg 对话框

class CDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg)

public:
	CDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString filename;
	void foo(CImage& img, int &sx, int& sy, int& w, int& h);
	afx_msg void OnPaint();
};
