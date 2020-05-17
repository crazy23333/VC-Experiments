
// Experiment13_1Dlg.h : 头文件
//

#pragma once


// CExperiment13_1Dlg 对话框
class CExperiment13_1Dlg : public CDialogEx
{
// 构造
public:
	CExperiment13_1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPERIMENT13_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double first;
	double second;
	int set;
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedSqu();
	afx_msg void OnBnClickedRec();
	afx_msg void OnBnClickedEqual();
	CString result;
};
